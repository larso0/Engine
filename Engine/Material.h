/* 
 * File:   Material.h
 * Author: larso
 *
 * Created on 2. januar 2016, 21:18
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Light.h"
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
		
		const glm::vec4& getColor() const;
		const Light* getLightSource() const;
	protected:
		glm::vec4 color;
		Light* lightSource;
	};
}

#endif /* MATERIAL_H */

