#ifndef __COMPONENT__H__
#define __COMPONENT__H__

#include "gameobject.h"

namespace coffee {

	class GameObject;

	class Component {
	public:
		Component(GameObject* owner): _owner(owner) {}
		virtual ~Component() {}

	protected:
		GameObject* _owner;
	
	};
}

#endif // !__COMPONENT__H__
