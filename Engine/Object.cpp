/* 
 * File:   Object.cpp
 * Author: larso
 * 
 * Created on 29. desember 2015, 23:57
 */

#include "Object.h"
#include <stdexcept>

namespace Engine
{
	DEFINE_META_INHERIT(Object, Node);

	Object::Object(Geometry* geometry, Material* material) :
	Node(),
	scaleVector(1.f, 1.f, 1.f),
	defaultScaleVector(1.f, 1.f, 1.f),
	geometry(geometry),
	material(material)
	{
		INHERIT_META_PTR(Object);
		if(geometry == nullptr)
		{
			throw std::invalid_argument("Geometry pointer was a nullpointer.");
		}
		if(material == nullptr)
		{
			throw std::invalid_argument("Material pointer was a nullpointer");
		}
	}

	Object::~Object()
	{
	}

	void Object::scale(float x, float y, float z)
	{
		scaleVector.x *= x;
		scaleVector.y *= y;
		scaleVector.z *= z;
		update();
	}

	void Object::scale(glm::vec3 s)
	{
		scaleVector *= s;
		update();
	}

	void Object::setScale(float x, float y, float z)
	{
		resetScale();
		scale(x, y, z);
	}

	void Object::setScale(glm::vec3 s)
	{
		resetScale();
		scale(s);
	}

	void Object::setDefaultScale(float x, float y, float z)
	{
		defaultScaleVector = glm::vec3(x, y, z);
	}

	void Object::setDefaultScale(glm::vec3 s)
	{
		defaultScaleVector = s;
	}

	void Object::resetScale()
	{
		scaleVector = defaultScaleVector;
		update();
	}

	Geometry* Object::getGeometry()
	{
		return geometry;
	}

	Material* Object::getMaterial()
	{
		return material;
	}

	void Object::update()
	{
		Node::update();
		transformationMatrix = glm::scale(transformationMatrix, scaleVector);
	}
}

