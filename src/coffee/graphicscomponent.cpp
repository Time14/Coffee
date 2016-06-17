#include "graphicscomponent.h"

namespace coffee {

	std::vector<GraphicsComponent*> GraphicsComponent::_components;

	//OpenGL stuff
	GLuint GraphicsComponent::_vertexArray = NULL;
	GLuint GraphicsComponent::_vertexBuffer = NULL;
	const size_t  GraphicsComponent::_elementsPerTriangle = 3;
	const size_t  GraphicsComponent::_bufferDataElementCount = 18;
	const GLfloat GraphicsComponent::_bufferData[] = {
		//First triangle
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,

		//Second triangle
		0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	GraphicsComponent::GraphicsComponent(GameObject* owner): Component(owner), _visible(true) {
		addGraphicsComponent(this);
	}

	void GraphicsComponent::init() {
		//You're not moron...
		glGenVertexArrays(1, &_vertexArray);
		glBindVertexArray(_vertexArray);

		//Send this once, and only once
		glGenBuffers(1, &_vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(_bufferData[0]) * _bufferDataElementCount, _bufferData, GL_STATIC_DRAW);
	}

	void GraphicsComponent::destroy() {
		for (size_t i = 0; i < _components.size(); i++) {
			delete _components[i];
		}

		_components.erase(_components.begin(), _components.end());
	}

	void GraphicsComponent::loop(float delta) {
		preDraw();
		for (size_t i = 0; i < _components.size(); i++) {
			_components[i]->draw(delta);
		}
		postDraw();
	}

	void GraphicsComponent::preDraw() {
		if (!_vertexArray) {
			init();
		}

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
		glVertexAttribPointer(0, _elementsPerTriangle, GL_FLOAT, GL_FALSE, 0, (void*) 0);
	}

	void GraphicsComponent::draw(float delta) {
		//Todo, add position support for the rendering code
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	void GraphicsComponent::postDraw() {
		glDisableVertexAttribArray(0);
	}
	
	void GraphicsComponent::addGraphicsComponent(GraphicsComponent * component) {
		_components.push_back(component);
	}
	
	void GraphicsComponent::removeGraphicsComponent(GraphicsComponent* component) {
		_components.erase(std::remove(_components.begin(), _components.end(), component), _components.end());
	}
}