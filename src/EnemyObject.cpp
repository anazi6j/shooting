#include "Include\EnemyObject.h"
#include "DxLib.h"
#include "Include\Ammo.h"
#include "Include\Admin.h"
#include "Include\Define.h"
#include <math.h>


EnemyObject::EnemyObject(int m_unit_graphic_handle, int m_bullet_graphic_handle, UnitAdmin* m_Uadmin,EnemyType EType,Tag m_tag)
{
	GraphicHandle = m_unit_graphic_handle;
	unit_admin = m_Uadmin;
	Type = EType;
	hitzone = HITDETECTIONZONE;
	//�G���ǂ�����true�ɂ���
	isEnemy = true;
	tag = m_tag;
	
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
//�G���o��������
void EnemyObject::Instantiate(double m_x, double m_y, double m_angle)
{
	position.x = m_x;
	position.y = m_y;

	

	Angle= m_angle;

	isActive = true;
	health = 2;
	//�����̓����o�ϐ����ۗ��ɂȂ��Ă���̂Ŗ�肪����B�ǂ��ɂ�����K�v������
	//Instantiate�֐��̃I�[�o�[���[�h�i�G�̐����l�����ɂ��邩�ǂ����j
	
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
			//���̉ӏ����s��ɂ���]�ŉ�]������
			Angle = atan2(targetY-position.y, targetX-position.x);
		}

		//�ړ�
		//Air1�̏ꍇ�͓ːi���Ă���
		if (Type == EnemyType::Air1) 
		{
			position.x = (position.x + cos(Angle) * 3);
			position.y = (position.y + sin(Angle) * 3);
		}
		//Air2�̏ꍇ�͔����̃O���t��`���Ȃ���
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
						if(distance<DISTANCE_RANGE)//�������ɓ�������
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
	unit_admin->DecreaseEnemyCount();
	
}