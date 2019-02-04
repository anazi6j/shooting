#include "Include\EnemyObject.h"
#include "DxLib.h"
#include "Include\Ammo.h"
#include "Include\Admin.h"
#include "Include\Define.h"
#include <math.h>

EnemyObject::EnemyObject(int m_unit_graphic_handle, int m_bullet_graphic_handle, UnitAdmin* m_Uadmin,EnemyType EType,Tag m_tag)
	:DestroyedEnemyNum(0)
{
	GraphicHandle = m_unit_graphic_handle;
	unit_admin = m_Uadmin;
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
//敵を出現させる
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
	/*Move()*/
		//移動
		//Air1の場合は突進してくる
	if (Type == EnemyType::Air1)
	{
		//参考:三角関数の使い方#COS,SIN関数
		 //http://wiki.hosiken.jp/petc/?Mame%2F%BB%B0%B3%D1%B4%D8%BF%F4%A4%CE%BB%C8%A4%A4%CA%FD
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
				if (distance < DISTANCE_RANGE)//距離内に入ったら
					ammo[i]->Shot(position.x, position.y, Angle);
				break;
			}
		}
	}
}

void EnemyObject::Set_AngleBetweenEnemyandPlayer()
{
	/*Set_Angle()*/
	Vector2D target_positon = unit_admin->GetClosetPosition(*this);
	distance = Vector2D::Distance(this->position, target_positon);
	if (target_positon != Vector2D(0, 0))
	{
		//https://qiita.com/kimi_dropc/items/edce3911b74d8bd324da
		//atan2で角度を求める。ベクトルの成分同士を引き算して数値を生成
		//-はいらない
		Angle = atan2(target_positon.y - this->position.y, target_positon.x - this->position.x);
	}
}
void EnemyObject::Death()
{
	unit_admin->DecreaseEnemyCount();
	
}