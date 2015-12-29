/* 
 * File:   Program.cpp
 * Author: larso
 * 
 * Created on 28. desember 2015, 19:25
 */

#include <GL/glew.h>
#include "Program.h"
#include <stdexcept>

namespace Engine
{

	std::string programInfoLog(GLuint shader)
	{
		GLint len = 0;
		glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &len);
		GLchar* cstr = new GLchar[len];
		glGetProgramInfoLog(shader, len, &len, cstr);
		std::string log(cstr);
		delete[] cstr;
		return log;
	}

	Program::Program() :
	objectId(0),
	shadersAreAttached(false),
	isLinked(false)
	{
	}

	Program::~Program()
	{
		if(shadersAreAttached)
		{
			glDeleteProgram(objectId);
		}
	}

	void Program::attachShader(const Shader& shader)
	{
		if(!shadersAreAttached)
		{
			objectId = glCreateProgram();
		}
		glGetError();
		glAttachShader(objectId, shader.getObjectId());
		GLenum error = glGetError();
		if(error != GL_NO_ERROR)
		{
			throw std::runtime_error("Error when attaching shader.");
		}
		shadersAreAttached = true;
	}

	void Program::link()
	{
		if(!shadersAreAttached)
		{
			throw std::runtime_error("Shaders need to be attached before linking program.");
		}
		glLinkProgram(objectId);
		GLint linkStatus = 0;
		glGetProgramiv(objectId, GL_LINK_STATUS, &linkStatus);
		infolog = programInfoLog(objectId);
		if(linkStatus == GL_FALSE)
		{
			throw std::runtime_error("Unable to link program: " + infolog);
		}

		isLinked = true;
	}

	void Program::use()
	{
		if(!isLinked)
		{
			throw std::runtime_error("Program must be linked before usage.");
		}
		glUseProgram(objectId);
	}

	GLint Program::getAttributeLocation(std::string attributeName)
	{
		GLint location = glGetAttribLocation(objectId, attributeName.c_str());
		if(location == -1)
		{
			throw std::runtime_error("Could not get attribute location for attribute with name \"" + attributeName + "\".");
		}
		return location;
	}

	GLint Program::getUniformLocation(std::string uniformName)
	{
		GLint location = glGetUniformLocation(objectId, uniformName.c_str());
		if(location == -1)
		{
			throw std::runtime_error("Could not get uniform location for uniform with name \"" + uniformName + "\".");
		}
		return location;
	}

	GLuint Program::getObjectId() const
	{
		return objectId;
	}

	const std::string& Program::getInfolog() const
	{
		return infolog;
	}
}