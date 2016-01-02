/* 
 * File:   PlaneGeometry.cpp
 * Author: larso
 * 
 * Created on 2. januar 2016, 20:54
 */

#include "PlaneGeometry.h"

using glm::vec3;
using glm::vec2;

namespace Engine
{

	PlaneGeometry::PlaneGeometry(bool doubleSided) :
	IndexGeometry()
	{
		vec3 normal(0.f, 1.f, 0.f);
		vertex(vec3(-0.5f, 0.f, 0.5f), normal, vec2(0.f, 0.f));
		vertex(vec3(0.5f, 0.f, 0.5f), normal, vec2(1.f, 0.f));
		vertex(vec3(0.5f, 0.f, -0.5f), normal, vec2(1.f, 1.f));
		vertex(vec3(-0.5f, 0.f, -0.5f), normal, vec2(0.f, 1.f));
		face(0, 1, 2);
		face(0, 2, 3);
		if(doubleSided)
		{
			face(0, 2, 1);
			face(0, 3, 2);
		}
	}

}