#include "Include/CircleCollision.h"
#include "Include/Vector2D.h"
#include <math.h>

CircleCollision::CircleCollision()
{
}


CircleCollision::~CircleCollision()
{
}


bool CircleCollision::Circle_isCollide(const CircleCollision& from, const CircleCollision& to)
{
	return Vector2D::Distance(from.position, to.position) < pow((from.radius + to.radius), 2);
}

 