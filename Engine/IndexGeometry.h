/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IndexGeometry.h
 * Author: larso
 *
 * Created on 28. desember 2015, 19:41
 */

#ifndef INDEXGEOMETRY_H
#define INDEXGEOMETRY_H

#include "Geometry.h"

namespace Engine
{
	class IndexGeometry : public Geometry
	{
	public:
		IndexGeometry();
		virtual ~IndexGeometry();

		void face(GLushort a, GLushort b, GLushort c);
		void sendData() override;
		GLuint createVertexArrayObject(GLint positionLocation, GLint normalLocation, GLint uvLocation) override;
		void draw() override;

	private:
		std::vector<GLushort> indices;
		bool dataIsSent;
		GLuint vertexBuffer;
		GLuint indexBuffer;
	};
}

#endif /* INDEXGEOMETRY_H */

