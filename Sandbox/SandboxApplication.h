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
#include <SphereGeometry.h>
#include <Program.h>
#include <Camera.h>
#include <Renderer.h>
#include <Object.h>
#include <Material.h>
#include <Light.h>

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
	Engine::SphereGeometry sphereGeometry;
	Engine::Node scene;
	Engine::Object cube1, cube2, plane, sphere;
	Engine::Light lightSource;
	Engine::Material m1, m2, m3, m4;
	Engine::Texture wallTexture, globeTexture, redTexture, grassTexture;
	Engine::Camera camera;
	Engine::Renderer renderer;
	float mouseSensitivity;
};

#endif /* SANDBOXAPPLICATION_H */

