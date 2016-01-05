/* 
 * File:   Texture.cpp
 * Author: larso
 * 
 * Created on 5. januar 2016, 14:43
 */

#include "Texture.h"
#include <SDL2/SDL_image.h>
#include <stdexcept>

namespace Engine
{

	Texture::Texture(std::string fileName) :
	initialized(false),
	objectId(0)
	{
		surface = IMG_Load(fileName.c_str());
		if(surface == nullptr)
		{
			std::string errorString(SDL_GetError());
			throw std::runtime_error("Could not load image file \"" +
									fileName + "\". Error: " + errorString);
		}
	}

	Texture::~Texture()
	{
		SDL_FreeSurface(surface);
		if(initialized)
		{
			glDeleteTextures(1, &objectId);
		}
	}

	void Texture::init()
	{
		glGenTextures(1, &objectId);
		glBindTexture(GL_TEXTURE_2D, objectId);

		int mode = GL_RGB;
		if(surface->format->BytesPerPixel == 4)
		{
			mode = GL_RGBA;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0,
					mode, GL_UNSIGNED_BYTE, surface->pixels);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	void Texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, objectId);
	}

}