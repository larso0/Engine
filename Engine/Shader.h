/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shader.h
 * Author: larso
 *
 * Created on 28. desember 2015, 19:22
 */

#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace Engine
{

	class Shader
	{
	public:
		Shader(GLenum shaderType);
		Shader(std::string filePath, GLenum shaderType);
		virtual ~Shader();
		
		void compile();
		
		void setSource(std::string source);
		void loadSource(std::string filePath);
		
		GLuint getObjectId() const;
		const std::string& getSource() const;
		const std::string& getInfolog() const;

	private:
		GLenum shaderType;
		GLuint objectId;
		bool haveSourceCode;
		bool isCompiled;
		std::string source;
		std::string infolog;
	};
}

#endif /* SHADER_H */

