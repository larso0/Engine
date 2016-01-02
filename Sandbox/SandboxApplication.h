/* 
 * File:   SandboxApplication.h
 * Author: larso
 *
 * Created on 28. desember 2015, 19:06
 */

#ifndef SANDBOXAPPLICATION_H
#define SANDBOXAPPLICATION_H

#include <Application.h>
#include <CubeGeometry.h>
#include <PlaneGeometry.h>
#include <Program.h>
#include <Camera.h>
#include <Renderer.h>
#include <Object.h>

class SandboxApplication : public Engine::Application
{
public:
	SandboxApplication(int argc, char** argv);
private:
	void startup() override;
	void shutdown() override;
	void resize(int w, int h) override;
	void render(float deltaTime) override;
	void handleEvent(SDL_Event* event) override;
	
	Engine::Program program;
	Engine::CubeGeometry cubeGeometry;
	Engine::PlaneGeometry planeGeometry;
	Engine::Node scene;
	Engine::Object cube1, cube2, plane;
	Engine::Camera camera;
	Engine::Renderer renderer;
	float mouseSensitivity;
};

#endif /* SANDBOXAPPLICATION_H */

