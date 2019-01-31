#include "Include\Ammo.h"
#include <math.h>
#include "Include\Define.h"
#include "Include\CharacterObject.h"
//Ammo�I�u�W�F�N�g�ɃO���t�B�b�N�A�����蔻��A�U���́A�e�𔭎˂����@�̂��G������������
Ammo::Ammo(int m_ammo_graphic_handle, bool m_isEnemy)
{
	GraphicHandle = m_ammo_graphic_handle;


	collision.radius = RADIUS;
	damage = DAMAGE;
	isEnemy = m_isEnemy;
}

//�e������
void Ammo::Shot(double m_x, double m_y, double m_angle)
{
	position.x= m_x;
	position.y = m_y;
	Angle = m_angle;
	//�u�摜��\������v��
	isActive = true;
}


//�e�̈ړ���p�x�v�Z����R�}���Ƃɍs��
//�e�̈ړ��ƒe�̏���
void Ammo::Update()
{
	
	//�@�̂̊p�x�ɉ����Ēe�̕������ς��
	position.x += cos(Angle)*AMMOVELOCITY;
	position.y += sin(Angle)*AMMOVELOCITY;
	if (position.x < SCREEN_HEIGHT_MIN || SCREEN_HEIGHT_MAX < position.x
		|| position.y < SCREEN_WIDTH_MIN || SCREEN_WIDTH_MAX < position.y) {
		isActive = false;
	}
	collision.position = position;
}

//�e������

void Ammo::DestroyAmmo()
{
	isActive = false; 
}
