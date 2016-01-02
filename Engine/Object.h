/* 
 * File:   Object.h
 * Author: larso
 *
 * Created on 29. desember 2015, 23:57
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "Node.h"
#include "Geometry.h"
#include "Material.h"

namespace Engine
{
	DECLARE_META(Object);
	class Object : public Node
	{
	public:
		Object(Geometry* geometry, Material* material);
		virtual ~Object();

		//Scale the object relative to the current scale.
		void scale(float x, float y, float z);
		void scale(glm::vec3 s);

		//Scale the object relative to the default scale.
		void setScale(float x, float y, float z);
		void setScale(glm::vec3 s);

		//Set the default scale.
		void setDefaultScale(float x, float y, float z);
		void setDefaultScale(glm::vec3 s);

		//Reset the scale transformation to the default scale.
		void resetScale();

		Geometry* getGeometry();
		Material* getMaterial();
		
	protected:
		virtual void update() override;
		
	private:
		glm::vec3 scaleVector;
		glm::vec3 defaultScaleVector;

		Geometry* geometry;
		Material* material;
	};
}

#endif /* OBJECT_H */

