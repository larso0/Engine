/* 
 * File:   SphereGeometry.h
 * Author: larso
 *
 * Created on 4. januar 2016, 11:45
 */

#ifndef SPHEREGEOMETRY_H
#define SPHEREGEOMETRY_H

#include "ArrayGeometry.h"

namespace Engine
{
	class SphereGeometry : public ArrayGeometry
	{
	public:
		SphereGeometry(int level = 0);
	private:
		void subdivide(glm::vec3& a, glm::vec3& b, glm::vec3& c, int level);
		void triangle(glm::vec3& a, glm::vec3& b, glm::vec3& c);
		static glm::vec2 sphereUv(glm::vec3& p);
	};
}

#endif /* SPHEREGEOMETRY_H */

