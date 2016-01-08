/* 
 * File:   SphereGeometry.h
 * Author: larso
 *
 * Created on 4. januar 2016, 11:45
 */

#ifndef SPHEREGEOMETRY_H
#define SPHEREGEOMETRY_H

#include "IndexGeometry.h"

namespace Engine
{
	class SphereGeometry : public IndexGeometry
	{
	public:
		SphereGeometry(int level = 0);
	private:
		void subdivide(GLushort a, GLushort b, GLushort c, int level);
		GLushort subVertex(GLushort a, GLushort b);
		static glm::vec2 sphereUv(glm::vec3& p);
	};
}

#endif /* SPHEREGEOMETRY_H */

