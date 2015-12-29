/* 
 * File:   Program.h
 * Author: larso
 *
 * Created on 28. desember 2015, 19:25
 */

#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include "Shader.h"

namespace Engine
{
	class Program
	{
	public:
		Program();
		virtual ~Program();

		void attachShader(const Shader& shader);
		void link();
		void use();

		GLint getAttributeLocation(std::string attributeName);
		GLint getUniformLocation(std::string uniformName);
		GLuint getObjectId() const;
		const std::string& getInfolog() const;

	private:
		GLuint objectId;
		bool shadersAreAttached;
		bool isLinked;
		std::string infolog;
	};
}

#endif /* PROGRAM_H */

