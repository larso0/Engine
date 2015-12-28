/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Application.cpp
 * Author: larso
 * 
 * Created on 28. desember 2015, 17:48
 */

#include "Application.h"

namespace Engine
{

	Application::Application(int argc, char** argv) :
	argc(argc), argv(argv),
	sdlInitFlags(SDL_INIT_VIDEO),
	windowFlags(SDL_WINDOW_RESIZABLE),
	glMajorVersion(3), glMinorVersion(1),
	verticalSync(true),
	x(SDL_WINDOWPOS_UNDEFINED), y(SDL_WINDOWPOS_UNDEFINED),
	width(640), height(480),
	title("Application"),
	currentTime(0.f),
	initialized(false), running(false),
	window(nullptr), glContext(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::init()
	{
		int error = SDL_Init(sdlInitFlags);
		if(error)
		{
			std::string errorString(SDL_GetError());
			throw std::runtime_error("SDL_Init failed: " + errorString);
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, glMajorVersion);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, glMinorVersion);

		window = SDL_CreateWindow
			(
			title.c_str(),
			x, y,
			width, height,
			SDL_WINDOW_OPENGL | windowFlags
			);
		if(window == nullptr)
		{
			std::string errorString(SDL_GetError());
			SDL_Quit();
			throw std::runtime_error("SDL_CreateWindow failed: " + errorString);
		}

		glContext = SDL_GL_CreateContext(window);
		if(glContext == nullptr)
		{
			std::string errorString(SDL_GetError());
			SDL_DestroyWindow(window);
			SDL_Quit();
			throw std::runtime_error("SDL_GL_CreateContext failed: " + errorString);
		}

		if(verticalSync)
		{
			error = SDL_GL_SetSwapInterval(1);
			if(error)
			{
				std::string errorString = "Warning: Unable to set VSync: " + std::string(SDL_GetError());
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Unable to set VSync",
										errorString.c_str(), window);
			}
		}

		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();
		if(glewError != GLEW_OK)
		{
			std::string errorString((const char*)glewGetErrorString(glewError));
			throw std::runtime_error("Unable to initialize GLEW: " + errorString);
		}

		initialized = true;
	}

	void Application::run()
	{
		try
		{
			init();
			startup();
			resize(width, height);

			running = true;
			currentTime = SDL_GetTicks() / 1000.f;
			SDL_Event event;
			while(running)
			{
				while(SDL_PollEvent(&event))
				{
					if(event.type == SDL_QUIT)
					{
						running = false;
					}
					else if(event.type == SDL_WINDOWEVENT &&
							(event.window.event == SDL_WINDOWEVENT_RESIZED ||
							event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED))
					{
						width = event.window.data1;
						height = event.window.data2;
						resize(width, height);
					}
					else
					{
						handleEvent(&event);
					}
				}
				float newTime = SDL_GetTicks() / 1000.f;
				float deltaTime = newTime - currentTime;
				currentTime = newTime;
				render(deltaTime);
				SDL_GL_SwapWindow(window);
			}

			shutdown();
			SDL_GL_DeleteContext(glContext);
			SDL_DestroyWindow(window);
			SDL_Quit();
		}
		catch(const std::runtime_error& error)
		{
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
									error.what(), nullptr);
		}
	}

	void Application::setTitle(std::string title)
	{
		this->title = title;
		if(initialized)
		{
			SDL_SetWindowTitle(window, title.c_str());
		}
	}

	void Application::setSize(int w, int h)
	{
		width = w;
		height = h;
		if(initialized)
		{
			SDL_SetWindowSize(window, w, h);
		}
	}

	void Application::quit()
	{
		running = false;
	}

	const Uint8* Application::keyboardState()
	{
		return SDL_GetKeyboardState(nullptr);
	}

	void Application::startup()
	{
	}

	void Application::shutdown()
	{
	}

	void Application::resize(int w, int h)
	{
		glViewport(0, 0, width, height);
	}

	void Application::render(float deltaTime)
	{
	}

	void Application::handleEvent(SDL_Event* event)
	{
	}

}