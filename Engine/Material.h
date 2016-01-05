/* 
 * File:   Material.h
 * Author: larso
 *
 * Created on 2. januar 2016, 21:18
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Light.h"
#include "Texture.h"
#include <glm/glm.hpp>

namespace Engine
{
	class Material
	{
	public:
		Material();
		Material(glm::vec4 color);
		virtual ~Material();
		
		void setColor(glm::vec4 color);
		void setColor(float r, float g, float b, float a);
		void setLightSource(Light* lightSource);
		void setTexture(Texture* texture);
		
		const glm::vec4& getColor() const;
		const Light* getLightSource() const;
		const Texture* getTexture() const;
	protected:
		glm::vec4 color;
		Light* lightSource;
		Texture* texture;
	};
}

#endif /* MATERIAL_H */

