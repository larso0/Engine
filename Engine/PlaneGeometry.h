/* 
 * File:   PlaneGeometry.h
 * Author: larso
 *
 * Created on 2. januar 2016, 20:54
 */

#ifndef PLANEGEOMETRY_H
#define PLANEGEOMETRY_H

#include "IndexGeometry.h"

namespace Engine
{
	class PlaneGeometry : public IndexGeometry
	{
	public:
		PlaneGeometry(bool doubleSided = false);
	};
}

#endif /* PLANEGEOMETRY_H */

