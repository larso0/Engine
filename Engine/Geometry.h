/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Geometry.h
 * Author: larso
 *
 * Created on 28. desember 2015, 19:31
 */

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace Engine
{
	class Vertex
	{
	public:
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 uv;
		static const GLvoid* positionOffset;
		static const GLvoid* normalOffset;
		static const GLvoid* uvOffset;
		static const GLsizei stride;
	};
	class Geometry
	{
	public:
		Geometry();
		virtual ~Geometry();

		void vertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 uv);
		virtual void sendData() = 0;
		virtual GLuint createVertexArrayObject(GLint positionLocation, GLint normalLocation, GLint uvLocation) = 0;
		virtual void draw() = 0;

	protected:
		GLenum drawMode;
		std::vector<Vertex> vertices;
	};
}

#endif /* GEOMETRY_H */

