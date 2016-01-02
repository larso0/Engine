/* 
 * File:   Renderer.h
 * Author: larso
 *
 * Created on 30. desember 2015, 00:44
 */

#ifndef RENDERER_H
#define RENDERER_H

#include "Object.h"
#include "Program.h"
#include "Camera.h"
#include <unordered_map>

namespace Engine
{
	class Renderer
	{
	public:
		Renderer(Program* program);
		virtual ~Renderer();

		virtual void init();
		void render(Node* scene, Camera* camera);
		
		void setFieldOfView(float fov);
		void setAspectRatio(float aspectRatio);
		void setNear(float near);
		void setFar(float far);
		float getFieldOfView() const;
		float getAspectRatio() const;
		float getNear() const;
		float getFar() const;
	private:
		bool initialized;
		Program* program;

		GLint positionLocation;
		GLint normalLocation;
		GLint uvLocation;
		GLint mvpMatrixLocation;
		GLint normalMatrixLocation;
		GLint objectColorLocation;
		GLint lightPositionLocation;
		
		glm::mat4 projectionMatrix;
		float fieldOfView;
		float aspectRatio;
		float near;
		float far;
		bool needsUpdate;
		
		std::unordered_map<Geometry*, GLuint> vertexArrayObjects;
		void useGeometry(Geometry* geometry);
	};
}

#endif /* RENDERER_H */

