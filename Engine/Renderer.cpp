/* 
 * File:   Renderer.cpp
 * Author: larso
 * 
 * Created on 30. desember 2015, 00:44
 */

#include "Renderer.h"
#include "Light.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <glm/gtc/type_ptr.hpp>

namespace Engine
{

	Renderer::Renderer(Program* program) :
	initialized(false),
	program(program),
	positionLocation(-1),
	normalLocation(-1),
	uvLocation(-1),
	modelMatrixLocation(-1),
	viewProjectionMatrixLocation(-1),
	orientationQuaternionLocation(-1),
	objectColorLocation(-1),
	lightPositionLocation(-1),
	cameraPositionLocation(-1),
	fieldOfView(60.f),
	aspectRatio(1.f),
	near(0.1f),
	far(100.f),
	needsUpdate(true)
	{
		if(program == nullptr)
		{
			throw std::invalid_argument("Program can not be a nullpointer.");
		}
	}

	Renderer::~Renderer()
	{
		std::vector<GLuint> vaos;
		for(auto iter = vertexArrayObjects.begin(); iter != vertexArrayObjects.end(); iter++)
		{
			vaos.push_back(iter->second);
		}
		glDeleteVertexArrays(vaos.size(), vaos.data());
	}

	void Renderer::init()
	{
		positionLocation = program->getAttributeLocation("vPosition");
		normalLocation = program->getAttributeLocation("vNormal");
		uvLocation = program->getAttributeLocation("vUV");
		modelMatrixLocation = program->getUniformLocation("modelMatrix");
		viewProjectionMatrixLocation = program->getUniformLocation("viewProjectionMatrix");
		orientationQuaternionLocation = program->getUniformLocation("orientationQuaternion");
		objectColorLocation = program->getUniformLocation("objectColor");
		lightPositionLocation = program->getUniformLocation("lightPosition");
		cameraPositionLocation = program->getUniformLocation("cameraPosition");
		initialized = true;
	}

	void Renderer::render(Node* scene, Camera* camera)
	{
		if(needsUpdate)
		{
			projectionMatrix = glm::perspective(glm::radians(fieldOfView), aspectRatio, near, far);
			needsUpdate = false;
		}
		std::vector<Object*> drawableNodes;
		scene->traverse([&drawableNodes](Node * node)
		{
			if(INSTANCE_OF(node, Object))
			{
				drawableNodes.push_back((Object*)node);
			}
		});

		if(drawableNodes.size() > 0)
		{
			program->use();
			
			glm::mat4 viewProjectionMatrix = projectionMatrix * camera->getViewMatrix();
			glUniformMatrix4fv(viewProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewProjectionMatrix));
			glm::vec3 cameraPosition = camera->getPosition();
			glUniform3fv(cameraPositionLocation, 1, glm::value_ptr(cameraPosition));
			
			std::sort(drawableNodes.begin(), drawableNodes.end(),
					[](Object* a, Object * b) -> bool
					{
						return a->getGeometry() < b->getGeometry();
					});

			Geometry* currentGeometry = drawableNodes[0]->getGeometry();
			useGeometry(currentGeometry);
			for(Object* obj : drawableNodes)
			{
				if(obj->getGeometry() != currentGeometry)
				{
					currentGeometry = obj->getGeometry();
					useGeometry(currentGeometry);
				}
				glm::mat4 modelMatrix = obj->getTransformationMatrix();
				glm::quat orientationQuat = obj->getOrientationQuaternion();
				glm::vec4 color = obj->getMaterial()->getColor();
				glm::vec3 lightPosition(0.f, 0.f, 0.f);
				if(obj->getMaterial()->getLightSource() != nullptr)
				{
					lightPosition = obj->getMaterial()->getLightSource()->getPosition();
				}
				if(obj->getMaterial()->getTexture() != nullptr)
				{
					obj->getMaterial()->getTexture()->bind();
				}
				glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
				glUniform4fv(orientationQuaternionLocation, 1, glm::value_ptr(orientationQuat));
				glUniform4fv(objectColorLocation, 1, glm::value_ptr(color));
				glUniform3fv(lightPositionLocation, 1, glm::value_ptr(lightPosition));
				currentGeometry->draw();
			}
		}
	}

	void Renderer::setFieldOfView(float fov)
	{
		fieldOfView = fov;
		needsUpdate = true;
	}

	void Renderer::setAspectRatio(float aspectRatio)
	{
		this->aspectRatio = aspectRatio;
		needsUpdate = true;
	}

	void Renderer::setNear(float near)
	{
		this->near = near;
		needsUpdate = true;
	}

	void Renderer::setFar(float far)
	{
		this->far = far;
		needsUpdate = true;
	}

	float Renderer::getFieldOfView() const
	{
		return fieldOfView;
	}

	float Renderer::getAspectRatio() const
	{
		return aspectRatio;
	}

	float Renderer::getNear() const
	{
		return near;
	}

	float Renderer::getFar() const
	{
		return far;
	}

	void Renderer::useGeometry(Geometry* geometry)
	{
		if(vertexArrayObjects.find(geometry) != vertexArrayObjects.end())
		{
			glBindVertexArray(vertexArrayObjects[geometry]);
		}
		else
		{
			GLuint newVAO = geometry->createVertexArrayObject(positionLocation, normalLocation, uvLocation);
			vertexArrayObjects[geometry] = newVAO;
			glBindVertexArray(newVAO);
		}
	}

}