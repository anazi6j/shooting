#pragma once

#include "Vector2D.h"

class CircleCollision
{
	
	//�����蔻��
public:
	double radius;
	Vector2D position;
	CircleCollision();
	~CircleCollision();
	static bool Circle_isCollide(const CircleCollision& from, const CircleCollision& to);
	
};

