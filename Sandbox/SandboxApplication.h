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
	
	Engine::Program program;
	Engine::CubeGeometry cubeGeometry;
	Engine::Node scene;
	Engine::Object cube1, cube2;
	Engine::Camera camera;
	Engine::Renderer renderer;
};

#endif /* SANDBOXAPPLICATION_H */

