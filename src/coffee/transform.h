#ifndef __TRANSFORM__H__
#define __TRANSFORM__H__

#include "glm\glm.hpp"

namespace coffee {

	struct Transform {

		Transform(): position(0.0f, 0.0f), rotation(0.0f), scale(1.0f, 1.0f) {}
		Transform(float x, float y): position(x, y), rotation(0.0f), scale(1.0f, 1.0f) {}
		Transform(float x, float y, float r): position(x, y), rotation(r), scale(1.0f, 1.0f) {}
		Transform(float x, float y, float r, float sx, float sy): position(x, y), rotation(r), scale(sx, sy) {}

		glm::vec2 position;
		float rotation;
		glm::vec2 scale;
	};

}

#endif // !__TRANSFORM__H__
