#include "Include\EnemyObject.h"
#include "DxLib.h"
#include "Include\Ammo.h"
#include "Include\ObjectAdmin.h"
#include "Include\Define.h"
#include <math.h>

EnemyObject::EnemyObject(int m_object_graphic_handle, int m_bullet_graphic_handle, ObjectAdmin* m_Oadmin,EnemyType EType,Tag m_tag)
	:DestroyedEnemyNum(0)
{
	GraphicHandle = m_object_graphic_handle;
	unit_admin = m_Oadmin;
	Type = EType;
	
	collision.radius = RADIUS;
	
	tag = m_tag;
	
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i] = make_shared<Ammo>(m_bullet_graphic_handle,m_tag);   
	}

}


EnemyObject::~EnemyObject()
{
		
}

void EnemyObject::Instantiate(double m_x, double m_y, double m_angle)
{
	position.x = m_x;
	position.y = m_y;

	Angle= m_angle;

	isActive = true;
	health = ENEMYOB_HEALTH;
	
}

void EnemyObject::Update()
{
	collision.position = position;
	if (GetisActive())
	{
		
		for (int i = 0; i < MAX_AMMO; i++) {
			ammo[i]->Update();
		}

		Move();
		Attack();
		Set_AngleBetweenEnemyandPlayer();
		
	}

	if (health < 0)
	{
		Death();
		
	}

}
void EnemyObject::Move()
{
	
	if (Type == EnemyType::Air1)
	{
		
		position.x += cos(Angle) * ENEMY_SPEED;
		position.y += sin(Angle) * ENEMY_SPEED;
	}

}

void EnemyObject::Attack()
{
	rapid++;
	rapid %= RAPID_RATE;
	if (rapid == 9) {
		for (int i = 0; i < MAX_AMMO; i++)
		{
			if (!ammo[i]->GetisActive())
			{
				if (distance < DISTANCE_RANGE)
					ammo[i]->Shot(position.x, position.y, Angle);
				break;
			}
		}
	}
}

void EnemyObject::Set_AngleBetweenEnemyandPlayer()
{
	
	Vector2D target_positon = unit_admin->GetClosetPosition(*this);
	distance = Vector2D::Distance(this->position, target_positon);
	if (target_positon != Vector2D(0, 0))
	{
		
		Angle = atan2(target_positon.y - this->position.y, target_positon.x - this->position.x);
	}
}
void EnemyObject::Death()
{
	unit_admin->DecreaseEnemyCount();
	
}


//�Q�l:�O�p�֐��̎g����#COS,SIN�֐�
//http://wiki.hosiken.jp/petc/?Mame%2F%BB%B0%B3%D1%B4%D8%BF%F4%A4%CE%BB%C8%A4%A4%CA%FD
//https://qiita.com/kimi_dropc/items/edce3911b74d8bd324da
		//atan2�Ŋp�x�����߂�B�x�N�g���̐������m�������Z���Đ��l�𐶐�
		//-�͂���Ȃ�