/* 
 * File:   Main.cpp
 * Author: larso
 *
 * Created on 28. desember 2015, 17:41
 */

#include <gtest/gtest.h>
#include "Node.h"

using Engine::Node;

TEST(NodeTest, Translation)
{
	Node n1;
	Node n2(&n1);
	Node n3(&n2);
	n1.translate(5.f, 0.f, 0.f);
	n2.translate(glm::vec3(0.f, 1.f, 0.f));
	n3.translate(0.f, 0.f, -2.f);
	n1.update();
	EXPECT_NEAR(5.f, n1.getPosition().x, 0.00001f);
	EXPECT_NEAR(0.f, n1.getPosition().y, 0.00001f);
	EXPECT_NEAR(0.f, n1.getPosition().z, 0.00001f);

	EXPECT_NEAR(5.f, n2.getPosition().x, 0.00001f);
	EXPECT_NEAR(1.f, n2.getPosition().y, 0.00001f);
	EXPECT_NEAR(0.f, n2.getPosition().z, 0.00001f);

	EXPECT_NEAR(5.f, n3.getPosition().x, 0.00001f);
	EXPECT_NEAR(1.f, n3.getPosition().y, 0.00001f);
	EXPECT_NEAR(-2.f, n3.getPosition().z, 0.00001f);
}

TEST(NodeTest, Rotation)
{
	Node n1;
	Node n2(&n1);
	
	n1.rotate(0.f, 0.f, 3.141592f/2.f);
	n2.translate(0.f, 1.f, 0.f);
	
	n1.update();
	
	EXPECT_NEAR(-1.f, n2.getPosition().x, 0.00001f);
	EXPECT_NEAR(0.f, n2.getPosition().y, 0.00001f);
	EXPECT_NEAR(0.f, n2.getPosition().z, 0.00001f);
}