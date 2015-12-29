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
	Engine::Camera camera;
	
	glm::mat4 projectionMatrix;
	float fov;
	float near;
	float far;
	
	GLint mvpMatrixLocation;
	GLint normalMatrixLocation;
	GLuint cubeVAO;
};

#endif /* SANDBOXAPPLICATION_H */

