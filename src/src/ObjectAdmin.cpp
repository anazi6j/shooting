#include "Include\ObjectAdmin.h"
#include "DxLib.h"
#include "Include\PlayableObject.h"
#include "Include\BarrierObject.h"
#include "Include\EnemyObject.h"
#include "Include\Ammo.h"
#include "Include\CharacterObject.h"
#include "Include\Vector2D.h"
#include "Include/HPRecoverObject.h"
#include "Include/CannonArtilally.h"
#include "Include/CircleCollision.h"
#include <iostream>
#include <cassert>

ObjectAdmin::ObjectAdmin(char* m_key) :gameoverflag(false), gameclearflag(false), score(0), Density(EnemyNumDensity::Low),
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
		Object[PLAYEABLEOB_NUM] = make_unique<PlayableObject>(player_graphic_handle, bullet_graphic_handle,
			barrier_graphic_handle, Cannon_graphic_handle, m_key, this, Tag::Player);
	}
	catch (bad_alloc)
	{
		cout << "�v���C���[�I�u�W�F�N�g�̗̈���m�ۂł��܂���\n";
	}
	for (int i = ENEMYOB_START; i < OBJECT_MAXNUM; i++) {
		
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
ObjectAdmin::~ObjectAdmin()
{

}
//�������i�v���C���[�𐶐�����j
void ObjectAdmin::InitGame()
{
	Object[PLAYEABLEOB_NUM]->Instantiate(SCREEN_HEIGHT_MAX/2, SCREEN_WIDTH_MAX/2, -PI / 2);
	
}

void ObjectAdmin::Update()
{
	

	//�v���C���[(Object��0�ԁj�ƓG�iOBJECT_MAXNUM���j��Update���Ăяo��
	for (int i = 0; i < OBJECT_MAXNUM ; i++)
	{
		
		Object[i]->Update();
		Object[i]->Draw();
		Object[i]->DrawHealth();
	}
	Controll_EnemyNumDensity();
	DrawUI();

	
	InstantiateEnemy();
	//�v���C���[�����񂾂�iObject0�Ԃ�isActive��false��������)�Q�[���I��
	if (!Object[PLAYEABLEOB_NUM]->GetisActive())
	{
		gameoverflag = true;
	}
	
	if (Get_Score() > NECESSARY_SCORE_TO_BE_CLEARED)
	{
		gameclearflag = true;
	}
	
}

void ObjectAdmin::InstantiateEnemy()
{
	int RandomNum = GetEnemyNumDensity();

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

}


void ObjectAdmin::DrawUI()

{
	DrawFormatString(50, 50, GetColor(255, 255, 255), "Score:%d", Get_Score());
	DrawFormatString(50, 70, GetColor(255, 255, 255), "���ޓx:%d", Get_NumofRepeledEnemy());
	DrawFormatString(50, 90, GetColor(255, 255, 255), "�����ْ��x�̌p������:%d", static_cast<int>(Get_HIGHTension_ElapsedFrame()));
}




//bullet��CharcterObject�̑�������ɂ�邠���蔻����s��
//
void ObjectAdmin::Check_Collision_BullettoCharacterObject()
{
	
	for (int attackernum = 0; attackernum < OBJECT_MAXNUM; attackernum++) {
		if (Object[attackernum]->GetisActive()) {
			
			for (int bulletnum = 0; bulletnum <MAX_AMMO; bulletnum++) {

				if (Object[attackernum]->GetAmmo(bulletnum)->GetisActive()) {

					for (int targetnum = 0; targetnum <OBJECT_MAXNUM; targetnum++) {
						if (Object[targetnum]->GetisActive()) {
							if (Object[attackernum]->GetTag()!= Object[targetnum]->GetTag()) {

								CircleCollision attackercol = Object[attackernum]->GetAmmo(bulletnum)->GetCircleCollision();
								CircleCollision targetCol = Object[targetnum]->GetCircleCollision();

								if(CircleCollision::Circle_isCollide(attackercol,targetCol))
								{
									Object[targetnum]->Hit(Object[attackernum]->GetAmmo(bulletnum));
									Object[attackernum]->GetAmmo(bulletnum)->DestroyAmmo();
									
									if (Object[targetnum]->GetTag() == Tag::Enemy) 
									{
									score += ADD_SCORE;
									NumofRepeledEnemy += ADD_SCORE;
									if (Object[attackernum]->GetTag() == Tag::Player)
									{
										Set_Cannon_TargetPos(Object[targetnum]->position);
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
}


void ObjectAdmin::Controll_EnemyNumDensity()
{
	/*Admin_EnemyNumDensity()*/

	if (Get_NumOfRepeledEnemy() <= NUMOF_REPELEDENEMY_LOW) {
		Set_EnemyNumDensity(EnemyNumDensity::Low);

	}
	else if (Get_NumOfRepeledEnemy() >= NUMOF_REPELEDENEMY_LOW && Get_NumOfRepeledEnemy() <= NUMOF_REPELEDENEMY_HIGH)
	{
		Set_EnemyNumDensity(EnemyNumDensity::Middle);

	}
	else if (Get_NumOfRepeledEnemy() >= NUMOF_REPELEDENEMY_HIGH)
	{
		Set_EnemyNumDensity(EnemyNumDensity::High);
		Set_HIGHTension_ElapsedFrame(HIGHTENSION_ELAPSEDFRAME_MAX);
	}

	if (Get_EnemyNumDensity() == EnemyNumDensity::High)
	{
		FrameLeft--;
		Set_HIGHTension_ElapsedFrame(FrameLeft);

	}

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
Vector2D ObjectAdmin::GetClosetPosition(const GameObject& closet)
{
	Vector2D returnpos= Vector2D(0,0);
	
	for (int i= 0; i< OBJECT_MAXNUM ; i++) {
		if (Object[i]->GetisActive()) {
			//�^�O����v���Ȃ�������
			if (closet.GetTag() != Object[i]->GetTag())
			{
				returnpos = Object[i]->position;	
			}
		}
	}
	return returnpos;
}

Vector2D ObjectAdmin::GetCannon_TargetPos()
{
	Vector2D target = Vector2D(0, 0);

	target = Vector2D(Cannon_Aimpos.x, Cannon_Aimpos.y);

	return target;
	//�e�����������G��_���B
}


int ObjectAdmin::GetEnemyNumDensity()
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

void ObjectAdmin::Set_Cannon_TargetPos(const Vector2D& pos)
{
	Cannon_Aimpos.x = pos.x;
	Cannon_Aimpos.y = pos.y;
}