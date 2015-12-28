/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Application.h
 * Author: larso
 *
 * Created on 28. desember 2015, 17:48
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <stdexcept>

namespace Engine
{

	class Application
	{
	public:
		Application(int argc, char** argv);
		virtual ~Application();

		void run();

	protected:
		int argc;
		char** argv;

		Uint32 sdlInitFlags;
		Uint32 windowFlags;
		int glMajorVersion;
		int glMinorVersion;
		bool verticalSync;

		int x, y;
		int width, height;
		std::string title;
		float currentTime;

		void setTitle(std::string title);
		void setSize(int w, int h);
		void quit();

		const Uint8* keyboardState();

		virtual void startup();
		virtual void shutdown();
		virtual void resize(int w, int h);
		virtual void render(float deltaTime);
		virtual void handleEvent(SDL_Event* event);

	private:
		bool initialized;
		bool running;

		SDL_Window* window;
		SDL_GLContext glContext;

		void init();
	};

}

#endif /* APPLICATION_H */

