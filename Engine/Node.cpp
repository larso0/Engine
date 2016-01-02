/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: larso
 * 
 * Created on 29. desember 2015, 00:51
 */

#include "Node.h"
#include <algorithm>
#include <stdexcept>

namespace Engine
{
	DEFINE_META(Node);

	Node::Node(Node* parent) :
	parent(parent)
	{
		if(parent != nullptr)
		{
			parent->children.push_back(this);
		}
	}

	Node::~Node()
	{
	}

	void Node::setParent(Node* parent)
	{
		if(this->parent != nullptr)
		{
			this->parent->children.erase
				(
				std::remove(this->parent->children.begin(),
							this->parent->children.end(), this),
				this->parent->children.end());
		}
		this->parent = parent;
		if(parent != nullptr)
		{
			parent->children.push_back(this);
		}
		update();
	}

	void Node::add(Node* child)
	{
		if(child == nullptr)
		{
			throw std::invalid_argument("Tried to add nullptr.");
		}
		child->setParent(this);
	}

	void Node::traverse(std::function<void(Node*)> f)
	{
		f(this);
		for(Node* child : children)
		{
			child->traverse(f);
		}
	}

	void Node::update()
	{
		if(parent == nullptr)
		{
			worldMatrix = glm::translate(glm::mat4(), translationVector) *
				glm::mat4_cast(rotationQuaternion);
			orientationQuaternion = rotationQuaternion;
		}
		else
		{
			worldMatrix = parent->worldMatrix *
				glm::translate(glm::mat4(), translationVector) *
				glm::mat4_cast(rotationQuaternion);
			orientationQuaternion = rotationQuaternion * parent->orientationQuaternion;
		}
		position = glm::vec3(worldMatrix * glm::vec4(0.f, 0.f, 0.f, 1.f));

		transformationMatrix = worldMatrix;
		
		for(Node* child : children)
		{
			child->update();
		}
	}

	void Node::translate(float x, float y, float z)
	{
		translationVector.x += x;
		translationVector.y += y;
		translationVector.z += z;
		update();
	}

	void Node::translate(glm::vec3 t)
	{
		translationVector += t;
		update();
	}

	void Node::rotate(float x, float y, float z)
	{
		rotationQuaternion *= glm::angleAxis(x, glm::vec3(1.f, 0.f, 0.f));
		rotationQuaternion *= glm::angleAxis(y, glm::vec3(0.f, 1.f, 0.f));
		rotationQuaternion *= glm::angleAxis(z, glm::vec3(0.f, 0.f, 1.f));
		update();
	}

	void Node::rotate(glm::vec3 angles)
	{
		rotationQuaternion *= glm::angleAxis(angles.x, glm::vec3(1.f, 0.f, 0.f));
		rotationQuaternion *= glm::angleAxis(angles.y, glm::vec3(0.f, 1.f, 0.f));
		rotationQuaternion *= glm::angleAxis(angles.z, glm::vec3(0.f, 0.f, 1.f));
		update();
	}

	void Node::rotate(glm::vec3 axis, float angle)
	{
		rotationQuaternion *= glm::angleAxis(angle, glm::normalize(axis));
		update();
	}

	void Node::setTranslation(float x, float y, float z)
	{
		resetTranslation();
		translate(x, y, z);
	}

	void Node::setTranslation(glm::vec3 t)
	{
		resetTranslation();
		translate(t);
	}

	void Node::setRotation(float x, float y, float z)
	{
		resetRotation();
		rotate(x, y, z);
	}

	void Node::setRotation(glm::vec3 angles)
	{
		resetRotation();
		rotate(angles);
	}

	void Node::setRotation(glm::vec3 axis, float angle)
	{
		resetRotation();
		rotate(axis, angle);
	}

	void Node::setDefaultTranslation(float x, float y, float z)
	{
		defaultTranslationVector = glm::vec3(x, y, z);
	}

	void Node::setDefaultTranslation(glm::vec3 t)
	{
		defaultTranslationVector = t;
	}

	void Node::setDefaultRotation(float x, float y, float z)
	{
		defaultRotationQuaternion =
			glm::angleAxis(x, glm::vec3(1.f, 0.f, 0.f)) *
			glm::angleAxis(y, glm::vec3(0.f, 1.f, 0.f)) *
			glm::angleAxis(z, glm::vec3(0.f, 0.f, 1.f));
	}

	void Node::setDefaultRotation(glm::vec3 angles)
	{
		defaultRotationQuaternion =
			glm::angleAxis(angles.x, glm::vec3(1.f, 0.f, 0.f)) *
			glm::angleAxis(angles.y, glm::vec3(0.f, 1.f, 0.f)) *
			glm::angleAxis(angles.z, glm::vec3(0.f, 0.f, 1.f));
	}

	void Node::setDefaultRotation(glm::vec3 axis, float angle)
	{
		defaultRotationQuaternion = glm::angleAxis(angle, glm::normalize(axis));
	}

	void Node::resetTranslation()
	{
		translationVector = defaultTranslationVector;
		update();
	}

	void Node::resetRotation()
	{
		rotationQuaternion = defaultRotationQuaternion;
		update();
	}

	const glm::vec3& Node::getPosition() const
	{
		return position;
	}

	const glm::mat4& Node::getTransformationMatrix() const
	{
		return transformationMatrix;
	}

	const glm::quat Node::getOrientationQuaternion() const
	{
		return orientationQuaternion;
	}

}