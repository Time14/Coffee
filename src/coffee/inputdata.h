#ifndef __INPUTDATA__H__
#define __INPUTDATA__H__

#include <string>
#include <sstream>

namespace coffee {

	struct InputData {
		InputData(): _device(0), _button(0), _mods(0), _axis(0) {}

		InputData(unsigned int d, unsigned int b, unsigned int m): _device(d), _button(b), _mods(m), _axis(0) {};
		InputData(unsigned int d, unsigned int b, unsigned int m, unsigned int a): _device(d), _button(b), _mods(m), _axis(a) {};

		InputData(const std::string& data) {
			std::istringstream ss(data);
			std::string token;

			if (std::getline(ss, token, ':')) {
				_device = atoi(token.c_str());
			} else {
				_device = -1;
			}
			if (std::getline(ss, token, ':')) {
				_axis = atoi(token.c_str());
			} else {
				_axis = 0;
			}
			if (std::getline(ss, token, ':')) {
				_button = atoi(token.c_str());
			} else {
				_button = -1;
			}
			if (std::getline(ss, token, ':') && _device == -1) {
				_mods = atoi(token.c_str());
			} else {
				_mods = 0;
			}
			if (std::getline(ss, token, ':')) {
				_name = token;
			} else {
				_name = "";
			}
		}

		unsigned int _device; //The device ID
		unsigned int _button; //The button that was pressed
		unsigned int _mods; //Only matters if controller = -1
		unsigned int _axis;
		std::string _name;

		std::string serialize() {
			return getKey();
		}

		std::string serialize(std::string name) {
			std::string s = getKey();
			return s + ":" + name;
		}
		std::string getKey() {
			return (std::to_string(_device) + ":" + std::to_string(_axis) + ":" + std::to_string(_button) + ":" + std::to_string(_mods));
		}
	};
	/*
	* Seralized input maps:
	* device:axis:button:mods:name
	*
	* device, the controller/keyboard that enterd the command, -1 is keyboard, the rest are contollers.
	* button, the button index
	* mods, any modifyers tyhat were pressed, like shift
	* name, the name that this input can be reached by.
	*/
}

#endif // !__INPUTDATA__H__