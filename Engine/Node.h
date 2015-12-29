/* 
 * File:   Node.h
 * Author: larso
 *
 * Created on 29. desember 2015, 00:51
 */

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Metadata.h"

namespace Engine
{
	DECLARE_META(Node);
	class Node
	{
		DECLARE_META_PTR(Node);
	public:
		Node(Node* parent = nullptr);
		virtual ~Node();

		void setParent(Node* parent);
		void add(Node* child);

		//Transform the node relative to current transformations.
		void translate(float x, float y, float z);
		void translate(glm::vec3 t);
		void rotate(float x, float y, float z);
		void rotate(glm::vec3 angles);
		void rotate(glm::vec3 axis, float angle);

		//Transform the node relative to the default transformations.
		void setTranslation(float x, float y, float z);
		void setTranslation(glm::vec3 t);
		void setRotation(float x, float y, float z);
		void setRotation(glm::vec3 angles);
		void setRotation(glm::vec3 axis, float angle);

		//Set the default transformations for the node.
		void setDefaultTranslation(float x, float y, float z);
		void setDefaultTranslation(glm::vec3 t);
		void setDefaultRotation(float x, float y, float z);
		void setDefaultRotation(glm::vec3 angles);
		void setDefaultRotation(glm::vec3 axis, float angle);

		//Reset to the default transformations.
		void resetTranslation();
		void resetRotation();

		const glm::vec3& getPosition() const;
		const glm::mat4& getTransformationMatrix() const;

	protected:
		Node* parent;
		std::vector<Node*> children;

		glm::vec3 position;
		glm::quat orientationQuaternion;
		glm::mat4 transformationMatrix;
		
		virtual void update();

	private:
		glm::mat4 worldMatrix;

		glm::quat rotationQuaternion;
		glm::vec3 translationVector;

		glm::quat defaultRotationQuaternion;
		glm::vec3 defaultTranslationVector;
	};
}

#endif /* NODE_H */

