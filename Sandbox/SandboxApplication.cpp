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
sphereGeometry(3),
cube1(&cubeGeometry, &m1), cube2(&cubeGeometry, &m2),
plane(&planeGeometry, &m1), sphere(&sphereGeometry, &m2),
wallTexture("WallTexture.jpg"),
renderer(&program),
mouseSensitivity(1000.f)
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

	cubeGeometry.sendData();
	planeGeometry.sendData();
	sphereGeometry.sendData();
	wallTexture.init();
	m1.setColor(0.7f, 0.7f, 0.7f, 1.f);
	m2.setColor(0.9f, 0.3f, 0.5f, 1.f);
	m1.setLightSource(&lightSource);
	m2.setLightSource(&lightSource);
	m1.setTexture(&wallTexture);
	m2.setTexture(&wallTexture);

	scene.add(&camera);
	scene.add(&lightSource);
	scene.add(&plane);
	scene.add(&cube1);
	scene.add(&sphere);
	cube1.add(&cube2);
	camera.translate(0.f, 1.f, 2.f);
	lightSource.translate(0.f, 5.f, 0.f);
	plane.scale(20.f, 20.f, 20.f);
	cube1.translate(0.f, 0.75f, 0.f);
	sphere.translate(-2.f, 2.5f, 2.f);
	cube2.translate(1.5f, 0.f, 0.f);
	cube2.scale(0.5f, 2.f, 0.5f);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	renderer.init();
	SDL_SetRelativeMouseMode(SDL_TRUE);
	glClearColor(0.f, 0.f, 0.f, 1.f);
}

void SandboxApplication::shutdown()
{
}

void SandboxApplication::resize(int w, int h)
{
	glViewport(0, 0, w, h);
	renderer.setAspectRatio((float)w / h);
}

void SandboxApplication::render(float deltaTime)
{
	const Uint8* keys = keyboardState();
	if(keys[SDL_SCANCODE_W])
	{
		camera.moveForward(deltaTime);
	}
	if(keys[SDL_SCANCODE_S])
	{
		camera.moveBackward(deltaTime);
	}
	if(keys[SDL_SCANCODE_A])
	{
		camera.moveLeft(deltaTime);
	}
	if(keys[SDL_SCANCODE_D])
	{
		camera.moveRight(deltaTime);
	}
	if(keys[SDL_SCANCODE_I])
	{
		lightSource.translate(0.f, deltaTime, 0.f);
	}
	if(keys[SDL_SCANCODE_K])
	{
		lightSource.translate(0.f, -deltaTime, 0.f);
	}
	if(keys[SDL_SCANCODE_J])
	{
		lightSource.translate(-deltaTime, 0.f, 0.f);
	}
	if(keys[SDL_SCANCODE_I])
	{
		lightSource.translate(deltaTime, 0.f, 0.f);
	}
	cube1.rotate(glm::vec3(0.f, 1.f, 0.f), deltaTime);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	renderer.render(&scene, &camera);
}

void SandboxApplication::handleEvent(SDL_Event* event)
{
	switch(event->type)
	{
	case SDL_MOUSEMOTION:
		camera.motion(event->motion.xrel / mouseSensitivity,
					event->motion.yrel / mouseSensitivity);
		break;
	}
}
