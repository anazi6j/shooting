#include "Include/Collision.h"
#include "Include/Vector2D.h"


Collision::Collision()
{
}


Collision::~Collision()
{
}
bool Collision::Circle_isCollide(const Vector2D& bullet, const Vector2D& target,double HitzoneA,double HitzoneB)
{
	double bullet_x = bullet.x;
	double bullet_y = bullet.y;
	double bullet_area = HitzoneA;

	double target_x = target.x;
	double target_y = target.y;
	double target_area = HitzoneB;



	return ((bullet_x - target_x)* (bullet_x - target_x)) + ((bullet_y - target_y)*(bullet_y - target_y)) 
		< 
		(bullet_area + target_area)*(bullet_area + target_area);
	
}

/*
                                 double bullet_x = Object[i]->GetAmmo(b)->position.x;
								double bullet_y = Object[i]->GetAmmo(b)->position.y;
								double bullet_area = Object[i]->GetAmmo(b)->GetHitZone();

								double target_x = Object[t]->position.x;
								double target_y = Object[t]->position.y;
								double target_area = Object[t]->GetHitZone();


								//�e�Ɣ�e����Unit�Ƃ̋�����肱���̔��a�̍��v���傫���A�^�C�v����s�^�C�v�Ȃ��e���Ă��鎖�ɂȂ�
								if ((bullet_x - target_x)*(bullet_x - target_x) + (bullet_y - target_y)*(bullet_y - target_y)
									< (bullet_area + target_area)*(bullet_area + target_area)) {*/

 