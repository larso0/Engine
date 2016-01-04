/* 
 * File:   SphereGeometry.cpp
 * Author: larso
 * 
 * Created on 4. januar 2016, 11:45
 */

#include "SphereGeometry.h"
#include <cmath>

namespace Engine
{

	SphereGeometry::SphereGeometry(int level) :
	ArrayGeometry()
	{
		glm::vec3 a(-1.f, 0.f, 1.f),
			b(1.f, 0.f, 1.f),
			c(1.f, 0.f, -1.f),
			d(-1.f, 0.f, -1.f),
			e(0.f, 1.f, 0.f),
			f(0.f, -1.f, 0.f);
		a = glm::normalize(a);
		b = glm::normalize(b);
		c = glm::normalize(c);
		d = glm::normalize(d);
		subdivide(a, b, e, level);
		subdivide(b, c, e, level);
		subdivide(c, d, e, level);
		subdivide(d, a, e, level);
		subdivide(b, a, f, level);
		subdivide(c, b, f, level);
		subdivide(d, c, f, level);
		subdivide(a, d, f, level);
	}

	void SphereGeometry::subdivide(glm::vec3& a, glm::vec3& b, glm::vec3& c, int level)
	{
		if(level > 0)
		{
			glm::vec3 ab = glm::normalize(glm::mix(a, b, 0.5f));
			glm::vec3 ac = glm::normalize(glm::mix(a, c, 0.5f));
			glm::vec3 bc = glm::normalize(glm::mix(b, c, 0.5f));
			level--;
			subdivide(a, ab, ac, level);
			subdivide(ab, b, bc, level);
			subdivide(bc, c, ac, level);
			subdivide(ab, bc, ac, level);
		}
		else
		{
			triangle(a, b, c);
		}
	}

	void SphereGeometry::triangle(glm::vec3& a, glm::vec3& b, glm::vec3& c)
	{
		vertex(a, a, sphereUv(a));
		vertex(b, b, sphereUv(b));
		vertex(c, c, sphereUv(c));
	}

	glm::vec2 SphereGeometry::sphereUv(glm::vec3& p)
	{
		float twoPi = 2 * M_PI;
		glm::vec2 uv;
		uv.x = 0.5f - ((float)atan2(p.z, p.x) / twoPi);
		uv.y = 0.5f - 2.0f * ((float)asin(p.y) / twoPi);
		return uv;
	}

}