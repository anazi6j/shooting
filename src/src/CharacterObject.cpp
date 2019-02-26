#include "Include\CharacterObject.h"
#include "Include\Define.h"
#include "DxLib.h"
#include <iostream>
#include "Include\ObjectAdmin.h"
#include "Include/Ammo.h"
#include "Include/BarrierObject.h"
#include "Include/CannonArtilally.h"
//#include <memory>
using namespace std;
//�e�ɔ�e�������̏���


CharacterObject::CharacterObject()
{
	EnemyCount = 0;
	Barrierisenabled = false;
	Ammo_rapid = 0;
	tag = Tag::Player;
}
void CharacterObject::IncreaseAmmo_rapid()
{
	Ammo_rapid++;
}

void CharacterObject::DevideAmmo_rapid(int rate)
{
	Ammo_rapid %= rate;
}

void CharacterObject::Hit(shared_ptr<Ammo> ammo)
{
	if (tag == Tag::Player) {
		if (Barrierisenabled)
		{
			return;
		}
		else
		{
			health -= ammo->GetDamage();
		}
	}
	
	health -= ammo->GetDamage();
	
	if (health < 0) {
		isActive = false;
	}
}
//�L�����N�^�[�̕`����s��
void CharacterObject::Draw()
{
	//�u�L�����N�^�[��\�����邩�ǂ����v��true�Ȃ�
	if (GetisActive())
	{
		//���̉摜��\��
		DrawRotaGraph(static_cast<int>(position.x), static_cast<int>(position.y), 1.0, Angle + PI / 2, GraphicHandle, static_cast < int>(1));
		//�e���ő�50�����`�悷��i
		for (int i = 0; i < MAX_AMMO; i++)
		{
			ammo[i]->DrawObject();
		}
	
		
	}
}

void CharacterObject::DrawHealth()
{
	if (isActive)
	{
		int Color;
		if (tag ==Tag::Enemy)
		{
			Color = GetColor(255, 0, 0);
			//GetColor�֐���RGB���擾����
		}
		else
		{
			Color = GetColor(0, 255, 0);
		}
		//HP�o�[��`��
		DrawBox(static_cast<int>(position.x - 10), static_cast<int>(position.y - 20), static_cast<int>(position.x + 10), static_cast<int>(position.y - 17), GetColor(0, 0, 255), 0);
		//HP��`��
		DrawBox(static_cast<int>(position.x - 10), static_cast<int>(position.y - 20), static_cast<int>(position.x - 10 + health / 5), static_cast<int>(position.y - 17), Color, 1);
	}
}
