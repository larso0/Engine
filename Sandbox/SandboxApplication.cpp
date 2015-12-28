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

SandboxApplication::SandboxApplication(int argc, char** argv) :
Engine::Application(argc, argv)
{
	setTitle("Sandbox");
}

SandboxApplication::~SandboxApplication()
{
}

void SandboxApplication::startup()
{
	glClearColor(1.f, 0.f, 0.f, 1.f);
}

void SandboxApplication::render(float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT);
}
