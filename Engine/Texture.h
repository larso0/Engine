/* 
 * File:   Texture.h
 * Author: larso
 *
 * Created on 5. januar 2016, 14:43
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <string>

namespace Engine
{
	class Texture
	{
	public:
		Texture(std::string fileName);
		~Texture();
		void init();
		void bind() const;
	private:
		bool initialized;
		SDL_Surface* surface;
		GLuint objectId;
	};
}

#endif /* TEXTURE_H */

