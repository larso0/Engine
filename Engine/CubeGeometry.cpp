/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CubeGeometry.cpp
 * Author: larso
 * 
 * Created on 28. desember 2015, 19:43
 */

#include "CubeGeometry.h"

using glm::vec3;
using glm::vec2;

namespace Engine
{

	CubeGeometry::CubeGeometry()
	{
		vertex(vec3(-0.5f, -0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(0.f, 0.f));
		vertex(vec3(0.5f, -0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(1.f, 0.f));
		vertex(vec3(0.5f, 0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(1.f, 1.f));
		vertex(vec3(0.5f, 0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(1.f, 1.f));
		vertex(vec3(-0.5f, 0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(0.f, 1.f));
		vertex(vec3(-0.5f, -0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(0.f, 0.f));
		vertex(vec3(-0.5f, 0.5f, 0.5f), vec3(0.f, 1.f, 0.f), vec2(0.f, 0.f));
		vertex(vec3(0.5f, 0.5f, 0.5f), vec3(0.f, 1.f, 0.f), vec2(1.f, 0.f));
		vertex(vec3(0.5f, 0.5f, -0.5f), vec3(0.f, 1.f, 0.f), vec2(1.f, 1.f));
		vertex(vec3(0.5f, 0.5f, -0.5f), vec3(0.f, 1.f, 0.f), vec2(1.f, 1.f));
		vertex(vec3(-0.5f, 0.5f, -0.5f), vec3(0.f, 1.f, 0.f), vec2(0.f, 1.f));
		vertex(vec3(-0.5f, 0.5f, 0.5f), vec3(0.f, 1.f, 0.f), vec2(0.f, 0.f));
		vertex(vec3(-0.5f, 0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(0.f, 0.f));
		vertex(vec3(0.5f, 0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(1.f, 0.f));
		vertex(vec3(0.5f, -0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(1.f, 1.f));
		vertex(vec3(0.5f, -0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(1.f, 1.f));
		vertex(vec3(-0.5f, -0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(0.f, 1.f));
		vertex(vec3(-0.5f, 0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(0.f, 0.f));
		vertex(vec3(-0.5f, -0.5f, -0.5f), vec3(-1.f, 0.f, 0.f), vec2(0.f, 0.f));
		vertex(vec3(-0.5f, -0.5f, 0.5f), vec3(-1.f, 0.f, 0.f), vec2(1.f, 0.f));
		vertex(vec3(-0.5f, 0.5f, 0.5f), vec3(-1.f, 0.f, 0.f), vec2(1.f, 1.f));
		vertex(vec3(-0.5f, 0.5f, 0.5f), vec3(-1.f, 0.f, 0.f), vec2(1.f, 1.f));
		vertex(vec3(-0.5f, 0.5f, -0.5f), vec3(-1.f, 0.f, 0.f), vec2(0.f, 1.f));
		vertex(vec3(-0.5f, -0.5f, -0.5f), vec3(-1.f, 0.f, 0.f), vec2(0.f, 0.f));
		vertex(vec3(-0.5f, -0.5f, 0.5f), vec3(0.f, -1.f, 0.f), vec2(0.f, 0.f));
		vertex(vec3(0.5f, -0.5f, -0.5f), vec3(0.f, -1.f, 0.f), vec2(1.f, 0.f));
		vertex(vec3(0.5f, -0.5f, 0.5f), vec3(0.f, -1.f, 0.f), vec2(1.f, 1.f));
		vertex(vec3(-0.5f, -0.5f, -0.5f), vec3(0.f, -1.f, 0.f), vec2(1.f, 1.f));
		vertex(vec3(0.5f, -0.5f, -0.5f), vec3(0.f, -1.f, 0.f), vec2(0.f, 1.f));
		vertex(vec3(-0.5f, -0.5f, 0.5f), vec3(0.f, -1.f, 0.f), vec2(0.f, 0.f));
		vertex(vec3(0.5f, -0.5f, 0.5f), vec3(1.f, 0.f, 0.f), vec2(0.f, 0.f));
		vertex(vec3(0.5f, -0.5f, -0.5f), vec3(1.f, 0.f, 0.f), vec2(1.f, 0.f));
		vertex(vec3(0.5f, 0.5f, -0.5f), vec3(1.f, 0.f, 0.f), vec2(1.f, 1.f));
		vertex(vec3(0.5f, 0.5f, -0.5f), vec3(1.f, 0.f, 0.f), vec2(1.f, 1.f));
		vertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.f, 0.f, 0.f), vec2(0.f, 1.f));
		vertex(vec3(0.5f, -0.5f, 0.5f), vec3(1.f, 0.f, 0.f), vec2(0.f, 0.f));
	}
}

