#include "bean.h"

namespace coffee {

	std::vector<void(*)(float)> Bean::_functions;
	bool Bean::_running = true;

	Bean::Bean() {
		_running = true;
		InputManager::readInputMap();
	
		GraphicsComponent::init();
		registerComponentManagerFunction(GraphicsComponent::loop);
	}

	Bean::~Bean() {
		InputManager::writeInputMap();

		GraphicsComponent::destroy();
	}

	void Bean::stop() {
		_running = false;
	}

	void Bean::brew() {
		while (_running) {
			_display.update();
			InputManager::update();

			float delta = 0;

			//Reverse for loop, so you add things to the beging of the vector. 
			//This makes sure the the Graphics and Physics components are calculated last 
			//so all behaviours can affect them propperly
			for (size_t i = _functions.size() - 1; i >= 0; i--) {
				_functions[i](delta);
			}
		}
	}

	void Bean::registerComponentManagerFunction(void(*function)(float)) { 
		_functions.push_back(function); 
	}
}