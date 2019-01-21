#include "Include\EnemyObject.h"
#include "DxLib.h"
#include "Include\Ammo.h"
#include "Include\UnitAdmin.h"
#include "Include\Define.h"
#include <math.h>


EnemyObject::EnemyObject(int m_unit_graphic_handle, int m_bullet_graphic_handle, UnitAdmin* m_Uadmin,EnemyType EType)
{
	GraphicHandle = m_unit_graphic_handle;
	unit_admin = m_Uadmin;
	Type = EType;
	hitzone = HITDETECTIONZONE;
	//敵かどうかをtrueにする
	isEnemy = true;

	
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i] = make_shared<Ammo>(m_bullet_graphic_handle,isEnemy);
	    
	}
	
}


EnemyObject::~EnemyObject()
{
	/*
		for (int i = 0; i <MAX_AMMO; i++)
	{
		delete ammo[i];
	}
	*/
		
}
//敵を出現させる
void EnemyObject::Instantiate(double m_x, double m_y, double m_angle)
{
	position.x = m_x;
	position.y = m_y;

	

	Angle= m_angle;

	isActive = true;
	health = 2;
	//ここはメンバ変数が丸裸になっているので問題がある。どうにかする必要がある
	//Instantiate関数のオーバーロード（敵の数を第四引数にするかどうか）
	
	//unit_admin->EnemyCount++;
}

void EnemyObject::Update()
{
   
	if (isActive)
	{
		
		for (int i = 0; i < MAX_AMMO; i++) {
			ammo[i]->Update();
		}

		
		
		Vector2D target_positon = unit_admin->GetClosetPosition(*this);
		
		distance = Vector2D::Distance(this->position, target_positon);
		if (target_positon != Vector2D(0,0))
		{
			double targetX = target_positon.x;
			double targetY = target_positon.y;
			//この箇所を行列による回転で回転させる
			Angle = atan2(targetY-position.y, targetX-position.x);
		}

		//移動
		//Air1の場合は突進してくる
		if (Type == EnemyType::Air1) 
		{
			position.x = (position.x + cos(Angle) * 3);
			position.y = (position.y + sin(Angle) * 3);
		}
		//Air2の場合は反比例のグラフを描きながら
		/*if (Type == EnemyType::Air2)
		{
			position.x--;
			position.y = position.x / 6;
		}*/

		

		rapid++;
			rapid %= RAPID_RATE;
			if (rapid == 9) {
				for (int i = 0; i < MAX_AMMO; i++)
				{
					if (!ammo[i]->GetisActive())
					{
						if(distance<DISTANCE_RANGE)//距離内に入ったら
						ammo[i]->Shot(position.x, position.y, Angle);
						break;
					}
				}
			}
	}

	if (health < 0)
	{
		Death();
		
	}
}

void EnemyObject::Death()
{
	unit_admin->EnemyCount--;
	
}