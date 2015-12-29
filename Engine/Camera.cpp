/* 
 * File:   Camera.cpp
 * Author: larso
 * 
 * Created on 29. desember 2015, 21:17
 */

#include "Camera.h"

static glm::vec3 quatTransform(glm::quat q, glm::vec3 v)
{
	glm::quat tmp = q * glm::quat(0.f, v) * glm::conjugate(q);
	return glm::vec3(tmp.x, tmp.y, tmp.z);
}

namespace Engine
{
	DEFINE_META_INHERIT(Camera, Node);

	Camera::Camera(Node* parent) :
	Node(parent),
	direction(0.f, 0.f, -1.f),
	up(0.f, 1.f, 0.f),
	right(1.f, 0.f, 0.f)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::update()
	{
		Node::update();
		direction = quatTransform(orientationQuaternion, direction);
		up = quatTransform(orientationQuaternion, up);
		right = glm::cross(direction, up);
		viewMatrix = glm::lookAt(position, position + direction, up);
	}

	void Camera::moveForward(float amount)
	{
		translate(direction * amount);
	}

	void Camera::moveBackward(float amount)
	{
		translate(direction * (-amount));
	}

	void Camera::moveUp(float amount)
	{
		translate(up * amount);
	}

	void Camera::moveDown(float amount)
	{
		translate(up * (-amount));
	}

	void Camera::moveLeft(float amount)
	{
		translate(right * (-amount));
	}

	void Camera::moveRight(float amount)
	{
		translate(right * amount);
	}

	const glm::mat4& Camera::getViewMatrix() const
	{
		return viewMatrix;
	}

}