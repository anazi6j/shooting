#pragma once

class Vector2D;
class Collision
{

	//�����蔻��
public:
	Collision();
	~Collision();

	static bool Circle_isCollide(const Vector2D& a,const Vector2D& b,double HitzoneA,double HitzoneB);
};

