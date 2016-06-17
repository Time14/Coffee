#include "gameobject.h"

namespace coffee {
	GameObject::GameObject(Transform transform): _transform(transform) {}

	GameObject::~GameObject() {
		for (size_t i = 0; i < _components.size(); i++) {
			//Prevent memory leaks!
			delete _components[i];
		}
	}

	void GameObject::addComponent(Component * component) { 
		_components.push_back(component); 
	}

	Transform * GameObject::getTransform() {
		return &_transform;
	}


}