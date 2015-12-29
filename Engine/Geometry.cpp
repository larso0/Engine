/* 
 * File:   Geometry.cpp
 * Author: larso
 * 
 * Created on 28. desember 2015, 19:31
 */

#include "Geometry.h"

namespace Engine
{
	const GLvoid* Vertex::positionOffset = 0;
	const GLvoid* Vertex::normalOffset = (GLvoid*)(sizeof(glm::vec3));
	const GLvoid* Vertex::uvOffset = (GLvoid*)(2 * sizeof(glm::vec3));
	const GLsizei Vertex::stride = sizeof(Vertex);

	Geometry::Geometry() :
	drawMode(GL_TRIANGLES)
	{
	}

	Geometry::~Geometry()
	{
	}

	void Geometry::vertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 uv)
	{
		vertices.push_back({pos, normal, uv});
	}
}

