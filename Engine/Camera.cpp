/* 
 * File:   Camera.cpp
 * Author: larso
 * 
 * Created on 29. desember 2015, 21:17
 */

#include "Camera.h"

using namespace glm;

static vec3 quatTransform(quat q, vec3 v)
{
	quat tmp = q * quat(0.f, v) * conjugate(q);
	return vec3(tmp.x, tmp.y, tmp.z);
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
		INHERIT_META_PTR(Camera);
	}

	Camera::~Camera()
	{
	}

	void Camera::update()
	{
		quat pitchYaw = angleAxis(pitchYawRoll.y, vec3(0.f, 1.f, 0.f)) *
			angleAxis(pitchYawRoll.x, vec3(1.f, 0.f, 0.f));
		rotationQuaternion = angleAxis(pitchYawRoll.z, direction) * pitchYaw;
		Node::update();
		direction = quatTransform(orientationQuaternion, vec3(0.f, 0.f, -1.f));
		up = quatTransform(orientationQuaternion, vec3(0.f, 1.f, 0.f));
		right = normalize(cross(direction, up));
		viewMatrix = lookAt(position, position + direction, up);
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

	void Camera::motion(float x, float y)
	{
		pitchYawRoll.x -= y;
		pitchYawRoll.y -= x;
		update();
	}

	const mat4& Camera::getViewMatrix() const
	{
		return viewMatrix;
	}

}