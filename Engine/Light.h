/* 
 * File:   Light.h
 * Author: larso
 *
 * Created on 2. januar 2016, 22:00
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Node.h"

namespace Engine
{
	DECLARE_META(Light);
	class Light : public Node
	{
	public:
		Light(Node* parent = nullptr);
		virtual ~Light();
	};
}

#endif /* LIGHT_H */

