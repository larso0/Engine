/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayGeometry.h
 * Author: larso
 *
 * Created on 28. desember 2015, 19:34
 */

#ifndef ARRAYGEOMETRY_H
#define ARRAYGEOMETRY_H

#include "Geometry.h"

namespace Engine
{
	class ArrayGeometry : public Geometry
	{
	public:
		ArrayGeometry();
		virtual ~ArrayGeometry();

		void sendData() override;
		GLuint createVertexArrayObject(GLint positionLocation, GLint normalLocation, GLint uvLocation) override;
		void draw() override;

	private:
		bool dataIsSent;
		GLuint vertexBuffer;
	};
}

#endif /* ARRAYGEOMETRY_H */

