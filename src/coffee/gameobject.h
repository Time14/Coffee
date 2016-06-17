#ifndef __GAMEOBJECT__H__
#define __GAMEOBJECT__H__

#include "transform.h"
#include "component.h"
//#include "scene.h"

#include <vector>

namespace coffee {

	class Component;

	class GameObject {
//		friend Scene;
	public:
		GameObject(Transform transform);
		
		~GameObject();

		void addComponent(Component* component);
		
		Transform* getTransform();

	protected:
		int _layer;

	private:
		Transform _transform;
		std::vector<Component*> _components;

	};
}

#endif // !__GAMEOBJECT__H__
