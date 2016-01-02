/* 
 * File:   Material.cpp
 * Author: larso
 * 
 * Created on 2. januar 2016, 21:18
 */

#include "Material.h"

namespace Engine
{

	Material::Material() :
	color(1.f, 1.f, 1.f, 1.f),
	lightSource(nullptr)
	{
	}

	Material::Material(glm::vec4 color) :
	color(color),
	lightSource(nullptr)
	{
	}

	Material::~Material()
	{
	}

	void Material::setColor(glm::vec4 color)
	{
		this->color = color;
	}

	void Material::setColor(float r, float g, float b, float a)
	{
		color = glm::vec4(r, g, b, a);
	}

	void Material::setLightSource(Light* lightSource)
	{
		this->lightSource = lightSource;
	}

	const glm::vec4& Material::getColor() const
	{
		return color;
	}

	const Light* Material::getLightSource() const
	{
		return lightSource;
	}

}

