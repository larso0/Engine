/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SandboxApplication.cpp
 * Author: larso
 * 
 * Created on 28. desember 2015, 19:06
 */

#include "SandboxApplication.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Engine;

SandboxApplication::SandboxApplication(int argc, char** argv) :
Engine::Application(argc, argv),
fov(60.f),
near(0.1f),
far(100.f),
eye(0.f, 1.f, 1.f),
lookAt(0.f, 0.f, 0.f),
up(0.f, 1.f, 0.f),
mvpMatrixLocation(0),
normalMatrixLocation(0),
cubeVAO(0)
{
	setTitle("Sandbox");
}

void SandboxApplication::startup()
{
	Shader vertexShader("VertexShader.glsl", GL_VERTEX_SHADER);
	Shader fragmentShader("FragmentShader.glsl", GL_FRAGMENT_SHADER);

	vertexShader.compile();
	fragmentShader.compile();

	program.attachShader(vertexShader);
	program.attachShader(fragmentShader);
	program.link();

	GLint vPosition = 0; //program.getAttributeLocation("vPosition");
	GLint vNormal = 1; //program.getAttributeLocation("vNormal");
	GLint vUV = 2; //program.getAttributeLocation("vUV");

	cubeGeometry.sendData();
	
	program.use();
	cubeVAO = cubeGeometry.createVertexArrayObject(vPosition, vNormal, vUV);

	mvpMatrixLocation = program.getUniformLocation("mvpMatrix");
	normalMatrixLocation = program.getUniformLocation("normalMatrix");

	viewMatrix = glm::lookAt(eye, lookAt, up);
	
	glEnable(GL_CULL_FACE);

	glClearColor(0.f, 0.f, 0.f, 1.f);
}

void SandboxApplication::shutdown()
{
	glDeleteVertexArrays(1, &cubeVAO);
}

void SandboxApplication::resize(int w, int h)
{
	glViewport(0, 0, w, h);
	projectionMatrix = glm::perspective(fov, (float)w / h, near, far);
}

void SandboxApplication::render(float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glm::mat4 mvpMatrix = projectionMatrix * viewMatrix *
		glm::rotate(glm::mat4(), currentTime, glm::vec3(0.f, 1.f, 0.f));
	glm::mat3 normalMatrix = glm::inverse(glm::mat3(mvpMatrix));
	glUniformMatrix4fv(mvpMatrixLocation, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
	glUniformMatrix3fv(normalMatrixLocation, 1, GL_TRUE, glm::value_ptr(normalMatrix));
	cubeGeometry.draw();
}
