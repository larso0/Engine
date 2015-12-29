/* 
 * File:   Shader.cpp
 * Author: larso
 * 
 * Created on 28. desember 2015, 19:22
 */

#include <GL/glew.h>
#include "Shader.h"
#include <fstream>
#include <stdexcept>

namespace Engine
{

	static std::string fileToString(std::string fileName)
	{
		std::ifstream file(fileName);
		if(!file.is_open())
		{
			throw std::runtime_error("Could not open file '" + fileName + "'.");
		}

		std::string str;

		file.seekg(0, std::ios::end);
		str.reserve(file.tellg());
		file.seekg(0, std::ios::beg);

		str.assign((std::istreambuf_iterator<char>(file)),
				std::istreambuf_iterator<char>());
		return str;
	}

	static std::string shaderInfoLog(GLuint shader)
	{
		GLint len = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
		GLchar* cstr = new GLchar[len];
		glGetShaderInfoLog(shader, len, &len, cstr);
		std::string log(cstr);
		delete[] cstr;
		return log;
	}

	Shader::Shader(GLenum shaderType) :
	shaderType(shaderType),
	objectId(0),
	haveSourceCode(false),
	isCompiled(false)
	{
	}

	Shader::Shader(std::string filePath, GLenum shaderType) :
	shaderType(shaderType),
	objectId(0),
	isCompiled(false)
	{
		source = fileToString(filePath);
		haveSourceCode = true;
	}

	Shader::~Shader()
	{
		if(isCompiled)
		{
			glDeleteShader(objectId);
		}
	}

	void Shader::compile()
	{
		if(!haveSourceCode)
		{
			throw std::runtime_error("No source code to compile.");
		}
		
		objectId = glCreateShader(shaderType);
		const GLchar* csrc = source.c_str();
		glShaderSource(objectId, 1, &csrc, nullptr);

		glCompileShader(objectId);
		GLint compile_status = 0;
		glGetShaderiv(objectId, GL_COMPILE_STATUS, &compile_status);
		infolog = shaderInfoLog(objectId);
		if(compile_status == GL_FALSE)
		{
			glDeleteShader(objectId);
			throw std::runtime_error("Unable to compile shader: " + infolog);
		}

		isCompiled = true;
	}

	void Shader::setSource(std::string source)
	{
		this->source = source;
		haveSourceCode = true;
	}

	void Shader::loadSource(std::string filePath)
	{
		source = fileToString(filePath);
		haveSourceCode = true;
	}

	GLuint Shader::getObjectId() const
	{
		return objectId;
	}

	const std::string& Shader::getSource() const
	{
		return source;
	}

	const std::string& Shader::getInfolog() const
	{
		return infolog;
	}
}

