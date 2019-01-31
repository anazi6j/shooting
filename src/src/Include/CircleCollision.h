#pragma once

#include "Vector2D.h"

class CircleCollision
{
	
	//“–‚½‚è”»’è
public:
	double radius;
	Vector2D position;
	CircleCollision();
	~CircleCollision();
	static bool Circle_isCollide(const CircleCollision& from, const CircleCollision& to);
	
};

