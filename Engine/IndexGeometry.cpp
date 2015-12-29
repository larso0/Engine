/* 
 * File:   IndexGeometry.cpp
 * Author: larso
 * 
 * Created on 28. desember 2015, 19:41
 */

#include "IndexGeometry.h"
#include <stdexcept>

namespace Engine
{

	IndexGeometry::IndexGeometry() :
	Geometry(),
	dataIsSent(false),
	vertexBuffer(0),
	indexBuffer(0)
	{
	}

	IndexGeometry::~IndexGeometry()
	{
		if(dataIsSent)
		{
			glDeleteBuffers(1, &vertexBuffer);
			glDeleteBuffers(1, &indexBuffer);
		}
	}

	void IndexGeometry::face(GLushort a, GLushort b, GLushort c)
	{
		indices.push_back(a);
		indices.push_back(b);
		indices.push_back(c);
	}

	void IndexGeometry::sendData()
	{
		if(!dataIsSent)
		{
			glGenBuffers(1, &vertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
			glGenBuffers(1, &indexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, indexBuffer);
			glBufferData(GL_ARRAY_BUFFER, indices.size() * sizeof(GLushort), indices.data(), GL_STATIC_DRAW);
			dataIsSent = true;
		}
	}

	GLuint IndexGeometry::createVertexArrayObject(GLint positionLocation, GLint normalLocation, GLint uvLocation)
	{
		if(!dataIsSent)
		{
			throw std::runtime_error("Data must be sent to GPU with send_data() before creating a vertex array object.");
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
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

		return vertexArrayObject;
	}

	void IndexGeometry::draw()
	{
		glDrawElements(drawMode, indices.size(), GL_UNSIGNED_SHORT, 0);
	}
}

