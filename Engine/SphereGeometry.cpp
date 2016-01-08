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
	IndexGeometry()
	{
		glm::vec3 va(-1.f, 0.f, 1.f),
			vb(1.f, 0.f, 1.f),
			vc(1.f, 0.f, -1.f),
			vd(-1.f, 0.f, -1.f),
			ve(0.f, 1.f, 0.f),
			vf(0.f, -1.f, 0.f);
		va = glm::normalize(va);
		vb = glm::normalize(vb);
		vc = glm::normalize(vc);
		vd = glm::normalize(vd);
		
		GLushort a = 0;
		vertex(va, va, sphereUv(va));
		GLushort b = 1;
		vertex(vb, vb, sphereUv(vb));
		GLushort c = 2;
		vertex(vc, vc, sphereUv(vc));
		GLushort d = 3;
		vertex(vd, vd, sphereUv(vd));
		GLushort e = 4;
		vertex(ve, ve, sphereUv(ve));
		GLushort f = 5;
		vertex(vf, vf, sphereUv(vf));
		
		subdivide(a, b, e, level);
		subdivide(b, c, e, level);
		subdivide(c, d, e, level);
		subdivide(d, a, e, level);
		subdivide(b, a, f, level);
		subdivide(c, b, f, level);
		subdivide(d, c, f, level);
		subdivide(a, d, f, level);
	}

	void SphereGeometry::subdivide(GLushort a, GLushort b, GLushort c, int level)
	{
		if(level > 0)
		{
			GLushort ab = subVertex(a, b);
			GLushort ac = subVertex(a, c);
			GLushort bc = subVertex(b, c);
			level--;
			subdivide(a, ab, ac, level);
			subdivide(ab, b, bc, level);
			subdivide(bc, c, ac, level);
			subdivide(ab, bc, ac, level);
		}
		else
		{
			face(a, b, c);
		}
	}

	GLushort SphereGeometry::subVertex(GLushort a, GLushort b)
	{
		GLushort index = vertices.size();
		glm::vec3 pos = glm::normalize(glm::mix(vertices[a].position, vertices[b].position, 0.5f));
		vertex(pos, pos, sphereUv(pos));
		return index;
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