/* 
 * File:   Camera.h
 * Author: larso
 *
 * Created on 29. desember 2015, 21:17
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "Node.h"

namespace Engine
{
	DECLARE_META(Camera);
	class Camera : public Node
	{
		DECLARE_META_PTR(Camera);
	public:
		Camera(Node* parent = nullptr);
		virtual ~Camera();
		virtual void update() override;
		
		void moveForward(float amount);
		void moveBackward(float amount);
		void moveUp(float amount);
		void moveDown(float amount);
		void moveLeft(float amount);
		void moveRight(float amount);
		
		const glm::mat4& getViewMatrix() const;
	private:
		glm::vec3 direction;
		glm::vec3 up;
		glm::vec3 right;
		glm::mat4 viewMatrix;
	};
}

#endif /* CAMERA_H */

