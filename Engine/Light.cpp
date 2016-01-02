/* 
 * File:   Light.cpp
 * Author: larso
 * 
 * Created on 2. januar 2016, 22:00
 */

#include "Light.h"

namespace Engine
{
	DEFINE_META_INHERIT(Light, Node);

	Light::Light(Node* parent) :
	Node(parent)
	{
		INHERIT_META_PTR(Light);
	}

	Light::~Light()
	{
	}

}