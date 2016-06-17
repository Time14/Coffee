#ifndef __GRAPHICSCOMPONENT__H__
#define __GRAPHICSCOMPONENT__H__

#include "include.h"
#include "component.h"
#include "gameobject.h"

#include <algorithm>

namespace coffee {

	class GraphicsComponent: Component {
	public:
		GraphicsComponent(GameObject* owner);

		virtual ~GraphicsComponent() {};

		void static init();
		void static destroy();
		void static loop(float delta);

		void static preDraw();
		void draw(float delta);
		void static postDraw();

		bool isVisible() { return _visible; }
		void setVisiability(bool visible) { _visible = visible; }

		static void addGraphicsComponent(GraphicsComponent* component);
		static void removeGraphicsComponent(GraphicsComponent* component);

	private:
		bool _visible;

		//Refferences to all graphics components.
		static std::vector<GraphicsComponent*> _components;

		//All will use a square mesh hence the static nature
		//And render their sprites on them
		static GLuint _vertexArray;
		static GLuint _vertexBuffer;
		static const size_t _elementsPerTriangle;
		static const size_t _bufferDataElementCount;
		static const GLfloat _bufferData[];
	};
}

#endif // !__GRAPHICSCOMPONENT__H__
