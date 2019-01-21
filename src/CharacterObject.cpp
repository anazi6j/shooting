#include "Include\CharacterObject.h"
#include "Include\Define.h"
#include "DxLib.h"
#include <iostream>
#include "Include\UnitAdmin.h"
#include "Include/Ammo.h"
//#include <memory>
using namespace std;
//�e�ɔ�e�������̏���
CharacterObject::CharacterObject()
{
	
}

void CharacterObject::Hit(shared_ptr<Ammo> ammo)
{
	health -= ammo->GetDamage();
	
	//�e�����������I�u�W�F�N�g�̗񋓎q��Ԃ��B
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
		DrawRotaGraph(position.x, position.y, 1.0, Angle + PI / 2, GraphicHandle,1.0);
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
		if (isEnemy)
		{
			Color = GetColor(255, 0, 0);
			//GetColor�֐���RGB���擾����
		}
		else
		{
			Color = GetColor(0, 255, 0);
		}

		DrawBox(position.x - 10, position.y - 20, position.x + 10, position.y - 17, GetColor(0, 0, 255), 0);
		DrawBox(position.x - 10, position.y - 20, position.x - 10 + health / 5, position.y - 17, Color, 1);
	}
}

/*
inline double CharacterObject::Dot(const CharacterObject* a, const CharacterObject* b)
{
	return a->posX*b->posX + a->posY*b->posY;
}

double CharacterObject::GetAngle(const CharacterObject* a, const CharacterObject* b)
{
	double dot = CharacterObject::Dot(a, b);
	double Amag = sqrt(a->posX*a->posX + a->posY*a->posY);//a�̑傫�������߂�
	double Bmag = sqrt(b->posX*b->posX + b->posY*b->posY);//b�̑傫�������߂�
	double cos = dot / (Amag*Bmag);//cos�Ƃ����߂�
	double radian = acos(cos);//cos�Ƃ̃��W�A�������߂�
	double degree = radian * RAD_TO_DEG;

	return degree;
}

double CharacterObject::Distance( const CharacterObject* a,  const CharacterObject* b)
{
	float Disx = (a->posX > b->posX) ? (a->posX - b->posX)*(a->posX - b->posX) : (b->posX - a->posX)*(b->posX - a->posX);
	float Disy = (a->posY > b->posY) ? (a->posY - b->posY)*(a->posY - b->posY) : (b->posY - a->posY)*(b->posY - a->posY);

	return sqrt(Disx*Disy);
}
*/