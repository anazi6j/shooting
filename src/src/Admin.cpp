#include "Include\Admin.h"
#include "DxLib.h"
#include "Include\PlayableObject.h"
#include "Include\BarrierObject.h"
#include "Include\EnemyObject.h"
#include "Include\Ammo.h"
#include "Include\CharacterObject.h"
#include "Include\Vector2D.h"
#include "Include/HPRecoverObject.h"
#include "Include/CannonArtilally.h"
#include "Include/Collision.h"
#include <iostream>
//�A�C�e���֘A
//�����蔻�肪�Ȃ�

UnitAdmin::UnitAdmin(char* m_key) :gameoverflag(false), gameclearflag(false), score(0), Density(EnemyNumDensity::Low),
NumofRepeledEnemy(0), CurEnemyLimit(0)
, EnemyCount(0), HIGHtension_ElapsedFrame(HIGHTENSION_ELAPSEDFRAME_MAX), FrameLeft(HIGHTENSION_ELAPSEDFRAME_MAX)

{
	///�摜�̃��[�h
	player_graphic_handle = LoadGraph("Image\\p.png", 0);
	enemy_graphic_handle = LoadGraph("Image\\e.png", 0);
	bullet_graphic_handle = LoadGraph("Image\\b.png", 0);
	barrier_graphic_handle = LoadGraph("Image\\Barrier.png", 0);
	Cannon_graphic_handle = LoadGraph("Image\\Cannon.png", 0);
	
	try {
		Object[0] = make_unique<PlayableObject>(player_graphic_handle, bullet_graphic_handle,
			barrier_graphic_handle, Cannon_graphic_handle, m_key, this, Tag::Player);
	}
	catch (bad_alloc)
	{
		cout << "�v���C���[�I�u�W�F�N�g�̗̈���m�ۂł��܂���\n";
	}
	for (int i = 1; i < OBJECT_MAXNUM; i++) {
		try {
			Object[i] = make_unique<EnemyObject>(enemy_graphic_handle, bullet_graphic_handle, this, EnemyType::Air1, Tag::Enemy);
		}
		catch(bad_alloc)
		{
			cout << "�G�I�u�W�F�N�g�̗̈���m�ۂł��܂���\n";
		}
	}
	}
	
	
	

//
UnitAdmin::~UnitAdmin()
{
	
	
}
//�������i�v���C���[�𐶐�����j
void UnitAdmin::InitGame()
{
	Object[0]->Instantiate(SCREEN_HEIGHT_MAX/2, SCREEN_WIDTH_MAX/2, -PI / 2);
	
}

void UnitAdmin::Update()
{
	int RandomNum = GetEnemyNumDensity();

	//�v���C���[(Object��0�ԁj�ƓG�iOBJECT_MAXNUM���j��Update���Ăяo��
	for (int i = 0; i < OBJECT_MAXNUM ; i++)
	{
		Object[i]->Update();
	}
	Controll_EnemyNumDensity();
	//��������InstantiateEnemy�֐��ɓ����\��̃R�[�h

	int spwan = GetRand(RandomNum - 2) + 1;
	int dice = GetRand(10);

	if (EnemyCount < ENEMY_INSTANTIABLE_MAX) {
		if (dice == 1) {
			//spwan�Ԗځi����ׂɌĂ΂ꂽ�ԍ��j�̗v�f��Object����\����������
			if (!Object[spwan]->GetisActive())
			{
				//����Object���o��������
				Object[spwan]->Instantiate(GetRand(640), 20, PI / 2);
			}
		}
	}

	//�������܂�InstantiateEnemy�֐��ɓ����\��̃R�[�h
	
	//�v���C���[�����񂾂�iObject0�Ԃ�isActive��false��������)�Q�[���I��
	if (!Object[0]->GetisActive())
	{
		gameoverflag = true;
	}
	
	if (Get_Score() > NECESSARY_SCORE_TO_BE_CLEARED)
	{
		gameclearflag = true;
	}
	

}

void UnitAdmin::Draw()
{
	for (int i = 0; i < OBJECT_MAXNUM ; i++)
	{
		Object[i]->Draw();
	}
	

	DrawFormatString(50, 50, GetColor(255, 255, 255), "Score:%d", Get_Score());
	DrawFormatString(50, 70, GetColor(255, 255, 255), "���ޓx:%d", Get_NumofRepeledEnemy());
	DrawFormatString(50, 90, GetColor(255, 255, 255), "�����ْ��x�̌p������:%d", static_cast<int>(Get_HIGHTension_ElapsedFrame()));
}

void UnitAdmin::DrawHitPoint()
{
	for (int i = 0; i < OBJECT_MAXNUM ; i++)
	{
		Object[i]->DrawHealth();
	}
}

//bullet��Unit�̑������蔻������āA���ʂ�unit��bullet�ɕԂ�
//(Hit�֐����Ăяo���j
void UnitAdmin::Judge()
{
	for ( int attackernum = 0;  attackernum <OBJECT_MAXNUM; attackernum++) {
		if (Object[attackernum]->GetisActive()) {
			for (int bulletnum = 0; bulletnum <MAX_AMMO; bulletnum++) {
				if (Object[attackernum]->GetAmmo(bulletnum)->GetisActive()) {

					for (int targetnum = 0; targetnum <OBJECT_MAXNUM; targetnum++) {
						if (Object[targetnum]->GetisActive()) {

							if (Object[attackernum]->GetIsEnemy() != Object[targetnum]->GetIsEnemy()) {

								double bullet_area = Object[attackernum]->GetAmmo(bulletnum)->GetHitZone();
								
								double target_area = Object[targetnum]->GetHitZone();


								//�e�Ɣ�e����Unit�Ƃ̋�����肱���̔��a�̍��v���傫���A�^�C�v����s�^�C�v�Ȃ��e���Ă��鎖�ɂȂ�
								
								if(Collision::Circle_isCollide(Object[attackernum]->GetAmmo(bulletnum)->position,
									Object[targetnum]->position,bullet_area,target_area)){
									
									Object[targetnum]->Hit(Object[attackernum]->GetAmmo(bulletnum));
									Object[attackernum]->GetAmmo(bulletnum)->DestroyAmmo();
									//�^�O���uEnemy�v�Ȃ瓾�_������
									if (Object[targetnum]->GetTag() == Tag::Enemy) {
									score += 20;
									NumofRepeledEnemy += 20;
									
									}
								}


								
							}

						}
					}

				}
			}
		}
	}
}
void UnitAdmin::Controll_EnemyNumDensity()
{
	/*Admin_EnemyNumDensity()*/
	if (Get_NumOfRepeledEnemy() <= 100) {
		Set_EnemyNumDensity(EnemyNumDensity::Low);

	}
	else if (Get_NumOfRepeledEnemy() >= 100 && Get_NumOfRepeledEnemy() <= 300)
	{
		Set_EnemyNumDensity(EnemyNumDensity::Middle);

	}
	else if (Get_NumOfRepeledEnemy() >= 300)
	{
		Set_EnemyNumDensity(EnemyNumDensity::High);
		Set_HIGHTension_ElapsedFrame(HIGHTENSION_ELAPSEDFRAME_MAX);
	}

	if (Get_EnemyNumDensity() == EnemyNumDensity::High)
	{
		FrameLeft--;
		Set_HIGHTension_ElapsedFrame(FrameLeft);

	}
	/*�����܂�Set_EnemyNumDensity*/


	if (Get_HIGHTension_ElapsedFrame() < 1)
	{
		Set_EnemyNumDensity(EnemyNumDensity::Low);

		SetFrameLeft(HIGHTENSION_ELAPSEDFRAME_MAX);
		NumofRepeledEnemy = 0;
	}
	if (Density == EnemyNumDensity::Low)
	{
		Set_HIGHTension_ElapsedFrame(HIGHTENSION_ELAPSEDFRAME_MAX);
	}
}

//Vector2D�ɕς���
Vector2D UnitAdmin::GetClosetPosition(const GameObject& closet)
{
	Vector2D returnpos= Vector2D(0,0);
	double range = -1;

	/*
	double returnobj_x = closet.position.x;
	double returnobj_y = closet.position.y;
	*/
	for (int i= 0; i< OBJECT_MAXNUM ; i++) {
		if (Object[i]->GetisActive()) {
			//returnoobj��i�Ԗڂ�Object��isenemy�t���O����v���Ȃ�������
			if (closet.GetIsEnemy() != Object[i]->GetIsEnemy())
			{
				//�v�Z�������₷�����邽�߃��[�J���ϐ��𐻍�
				double target_x = Object[i]->position.x;
				double target_y = Object[i]->position.y;
				//tmp_range�ɂ�target��returnobj�̋���������
			   //double tmp_range = (target_x - returnobj_x)*(target_x - returnobj_x) + (target_y - returnobj_y)*(target_y - returnobj_y);
				double tmp_range = Vector2D::Distance(Object[i]->position, closet.position);
				if (range != -1)
				{
					if (tmp_range < range) {
						range = tmp_range;
						returnpos = Object[i]->position;
					}
				}
				else
				{
					range = tmp_range;
					returnpos = Object[i]->position;
				}
			}
		}
	}
	return returnpos;
}

int UnitAdmin::GetEnemyNumDensity()
{
	switch (Density)
	{

	case EnemyNumDensity::Low:
		return ENEMYDENSITY_LOW;
		break;
	case EnemyNumDensity::Middle:
		return ENEMYDENSITY_MIDDLE;
		break;
	case EnemyNumDensity::High:
		return ENEMYDENSITY_HIGH;
		break;
	default:
		return ENEMYDENSITY_LOW;
	}
}