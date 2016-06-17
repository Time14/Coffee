#include "InputManager.h"

#include "bean.h"

#include <fstream>
#include <iostream>

namespace coffee {

	std::string InputManager::_path;
	std::vector<short> InputManager::_controllerMap;
	std::vector<SDL_GameController*> InputManager::_controllers;
	std::unordered_map<std::string, std::string> InputManager::_inputMap;
	std::unordered_map<std::string, float> InputManager::_inputData;
	glm::vec2 InputManager::_mousePos;

	void InputManager::addInput(unsigned int device, unsigned int button, unsigned int mods, unsigned int axis, const std::string& name) { 
		//I know how dumb this looks, but this was the only way I could make it work. I'm sorry I'm not smarter!
		addInput(InputData(device, button, mods, axis), name); 
	}

	void InputManager::addInput(InputData data, const std::string& name) {
		if (name != "") {
			data._name = name;
		}
		_inputMap.insert(std::make_pair(data.getKey(), data._name));
		//To allow multiple keybindings to the same input. (e.g. Controller and Keyboard)
		auto it = _inputData.find(data._name);
		if (it != _inputData.end()) {
			_inputData.insert(std::make_pair(data._name, 0.0f));
		}
	}

	bool InputManager::readInputMap(const std::string& path) {
		_path = path;
		std::ifstream file(path);
		std::string line;

		if (file.fail()) {
			std::cerr << "Error loading file \"" << path << "\"" << std::endl;
			return false;
		}

		while (std::getline(file, line)) {
			InputData id(line);
			addInput(id, id._name);
		}
		return true;
	}

	bool InputManager::writeInputMap(const std::string& path) {
		std::ofstream file;
		std::string line;

		//Check if a path is given in, otherwise use the default
		if (path != "") {
			_path = path;
		}

		file.open(_path);

		if (file.fail()) {
			std::cerr << "Error loading file \"" << path << "\"" << std::endl;
			return false;
		}

		//Loop through
		for (auto it = _inputMap.begin(); it != _inputMap.end(); ++it) {
			//line = <device:button:mods> + <name>
			line = it->first + ":" + it->second;
			file << line << std::endl;
		}
		file.flush();
		file.close();

		return true;
	}

	void InputManager::update() {
		//I don't know if this is a really dumb way to do it. It might be smarter to just clone the entire map
		//Anyways, this updates the inputData map to make presses pulses
		for (auto it = _inputData.begin(); it != _inputData.end(); ++it) {
			if (it->second == KEY_PRESSED) {
				it->second = KEY_DOWN;
			} else if (it->second == KEY_RELEASED) {
				it->second = KEY_UP;
			}
		}

		//Pulls any new events and makes sure they get handled the right way
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
				case SDL_QUIT:
					//requestClose = true;
					std::cout << "Trying to quit" << std::endl;
					coffee::Bean::stop();
					break;
				case SDL_KEYDOWN:
					keyEvent(InputType::KEY_DOWN, e.key.keysym.sym, e.key.keysym.mod);
					break;
				case SDL_KEYUP:
					keyEvent(InputType::KEY_UP, e.key.keysym.sym, e.key.keysym.mod);
					break;
				case SDL_MOUSEMOTION:
					mouseMove((float) e.motion.x, (float) e.motion.y);
					break;
				case SDL_MOUSEBUTTONDOWN:
					mouseEvent(InputType::MOUSE_CLICK, e.key.keysym.sym);
					break;
				case SDL_MOUSEBUTTONUP:
					mouseEvent(InputType::MOUSE_RELEASE, e.key.keysym.sym);
					break;
				case SDL_CONTROLLERDEVICEADDED:
					controllerEvent(InputType::CONTROLLER_ADD, e.cdevice.which);
					break;
				case SDL_CONTROLLERDEVICEREMOVED:
					controllerEvent(InputType::CONTROLLER_REMOVE, e.cdevice.which);
					break;
				case SDL_CONTROLLERBUTTONDOWN:
					controllerEvent(InputType::BUTTON_DOWN, e.cbutton.which, e.cbutton.button);
					break;
				case SDL_CONTROLLERBUTTONUP:
					controllerEvent(InputType::BUTTON_UP, e.cbutton.which, e.cbutton.button);
					break;
				case SDL_CONTROLLERAXISMOTION:
					axisEvent(e.caxis.which, e.caxis.axis, e.caxis.value);
					break;
			}
		}
	}

	void InputManager::keyEvent(InputType type, unsigned int key, unsigned int mods) {
		//-1 = Keyboard
		//Take out some mods, not all off them are usefull.
		mods = (mods & KMOD_ALT) + (mods & KMOD_CTRL) + (mods & KMOD_SHIFT);
		InputData in(-1, key, mods);
		auto it = _inputMap.find(in.getKey());

		if (it != _inputMap.end()) {
			if (type == InputType::KEY_DOWN) {
				_inputData[it->second] = KEY_PRESSED;
			} else if (type == InputType::KEY_UP) {
				_inputData[it->second] = KEY_RELEASED;
			}
		} else {
			//Write the keys to the log for debug purposes.
			std::cout << "Inputevent: " << in.getKey() << std::endl;
		}
	}

	void InputManager::mouseEvent(InputType type, unsigned int button) {
		//-2 = Mouse
		InputData in(-2, button, 0);
		auto it = _inputMap.find(in.getKey());

		if (it != _inputMap.end()) {
			if (type == InputType::KEY_DOWN) {
				_inputData[it->second] = KEY_PRESSED;
			} else if (type == InputType::KEY_UP) {
				_inputData[it->second] = KEY_RELEASED;
			}
		}
	}

	void InputManager::controllerEvent(InputType type, unsigned int which, unsigned int button) {
		if (type == InputType::CONTROLLER_ADD || type == InputType::CONTROLLER_REMOVE) {
			//IDEK
			std::cout << "A controller was ";
			if (type == InputType::CONTROLLER_ADD) {
				_controllers.push_back(SDL_GameControllerOpen(which));
				std::cout << "plugged in." << std::endl;

				bool added = false;
				//Is there an unbound controller? Then use it.
				for (short c : _controllerMap) {
					if (c == -1) {
						c = which;
						added = true;
						break;
					}
				}
				//If it failed, insert it at the end. 
				if (!added) {
					_controllerMap.push_back(which);
				}

			} else {
				SDL_GameControllerClose(_controllers[which]);
				std::cout << "unplugged." << std::endl;;

				//Un bind the controller
				for (short c : _controllerMap) {
					if (c == which) {
						c = -1;
						break;
					}
				}
			}
		} else {
			short controller = 0;
			for (size_t i = 0; i < _controllerMap.size(); i++) {
				if (_controllerMap[i] == which) {
					controller = (short) i;
					break;
				}
			}

			InputData in(controller, button, 0);
			auto it = _inputMap.find(in.getKey());

			printf("Button event on device ID:%i\nButton:%i\n", controller, button);

			if (it != _inputMap.end()) {
				if (type == InputType::KEY_DOWN) {
					_inputData[it->second] = KEY_PRESSED;
				} else if (type == InputType::KEY_UP) {
					_inputData[it->second] = KEY_RELEASED;
				}
			}
		}
	}

	void InputManager::mouseMove(float x, float y) {
		_mousePos = glm::vec2(x, y);
	}

	void InputManager::axisEvent(unsigned int which, unsigned int axis, short value) {
		short controller = 0;
		for (size_t i = 0; i < _controllerMap.size(); i++) {
			if (_controllerMap[i] == which) {
				controller = (short) i;
				break;
			}
		}

		InputData in(controller, 0, 0);
		in._axis = axis;
		float v = value / 32767.0f;
		if (v < -1) {
			v = -1.0f;
		}

		auto it = _inputMap.find(in.getKey());
		if (it != _inputMap.end()) {
			_inputData[it->second] = v;
		}
	}
}