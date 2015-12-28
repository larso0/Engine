/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayGeometry.cpp
 * Author: larso
 * 
 * Created on 28. desember 2015, 19:34
 */

#include "ArrayGeometry.h"
#include <stdexcept>

namespace Engine
{

	ArrayGeometry::ArrayGeometry() :
	Geometry(),
	dataIsSent(false),
	vertexBuffer(0)
	{
	}

	ArrayGeometry::~ArrayGeometry()
	{
		if(dataIsSent)
		{
			glDeleteBuffers(1, &vertexBuffer);
		}
	}

	void ArrayGeometry::sendData()
	{
		if(!dataIsSent)
		{
			glGenBuffers(1, &vertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
			dataIsSent = true;
		}
	}

	GLuint ArrayGeometry::createVertexArrayObject(GLint positionLocation, GLint normalLocation, GLint uvLocation)
	{
		if(!dataIsSent)
		{
			throw std::runtime_error("Data must be sent to GPU with sendData() before creating a vertex array object.");
		}

		GLuint vertexArrayObject;
		glGenVertexArrays(1, &vertexArrayObject);

		glBindVertexArray(vertexArrayObject);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glEnableVertexAttribArray(positionLocation);
		glVertexAttribPointer(positionLocation, 3, GL_FLOAT, false, Vertex::stride, Vertex::positionOffset);
		glEnableVertexAttribArray(normalLocation);
		glVertexAttribPointer(normalLocation, 3, GL_FLOAT, false, Vertex::stride, Vertex::normalOffset);
		glEnableVertexAttribArray(uvLocation);
		glVertexAttribPointer(uvLocation, 2, GL_FLOAT, false, Vertex::stride, Vertex::uvOffset);

		return vertexArrayObject;
	}

	void ArrayGeometry::draw()
	{
		glDrawArrays(drawMode, 0, vertices.size());
	}
}

