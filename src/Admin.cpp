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


//�A�C�e���֘A
//�����蔻�肪�Ȃ�

UnitAdmin::UnitAdmin(char* m_key) :gameoverflag(false), score(0) {
	///�摜�̃��[�h
	player_graphic_handle = LoadGraph("Image\\p.png", 0);
	enemy_graphic_handle = LoadGraph("Image\\e.png", 0);
	bullet_graphic_handle = LoadGraph("Image\\b.png", 0);
	barrier_graphic_handle = LoadGraph("Image\\Barrier.png", 0);
	Cannon_graphic_handle = LoadGraph("Image\\Cannon.png", 0);
	HPRecover_graphic_handle = LoadGraph("Image\\LIFE_Recovery_Item.png", 0);
	//Unit�̃C���X�^���X��
	Object[0] = make_shared<PlayableObject>(player_graphic_handle, bullet_graphic_handle, barrier_graphic_handle, m_key, this,Tag::Player);
	//Object[0] = new PlayableObject(player_graphic_handle, bullet_graphic_handle,barrier_graphic_handle, m_key,this);
	barrier = new BarrierObject(barrier_graphic_handle, this);
	for (int i = 1; i < OBJECT_MAXNUM; i++) {
		Object[i] = make_shared<EnemyObject>(enemy_graphic_handle, bullet_graphic_handle, this, EnemyType::Air1,Tag::Enemy);
		//Object[i] = new EnemyObject(enemy_graphic_handle, bullet_graphic_handle,this,EnemyType::Air1);
	}
	for (int j = 0 ;j < ITEM_MAXNUM; j++)
	{
		item[j] = new CannonItemObject(Cannon_graphic_handle,bullet_graphic_handle,this);
	}
	
	
}
//
UnitAdmin::~UnitAdmin()
{
	delete barrier;
	for (int j = 0; j < ITEM_MAXNUM; j++)
	{
		delete item[j];
	}
}
//�������i�v���C���[�𐶐�����j
void UnitAdmin::InitGame()
{
	Object[0]->Instantiate(320, 240, -PI / 2);
}

void UnitAdmin::Update()
{
	int RandomNum = GetEnemyNumDensity();
	//Barrier��Update���Ăяo��
	barrier->Update();
	//�v���C���[(Object��0�ԁj�ƓG�iOBJECT_MAXNUM���j��Update���Ăяo��
	for (int i = 0; i < OBJECT_MAXNUM ; i++)
	{
		Object[i]->Update();
	}

	//item(cannon,hprecover)��update���Ă�
	for (int j = 0; j < ITEM_MAXNUM; j++)
	{
		item[j]->Update();
	}

	//��������InstantiateEnemy�֐��ɓ����\��̃R�[�h

	int spwan = GetRand((RandomNum) - 2) + 1;
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
	//��������Iteminstantiate�֐�
	
	int ItemSpwan = GetRand((ITEM_MAXNUM)-2)+1;
	int Itemdice = GetRand(10);
	if (dice == 1) {
		if(!item[spwan]->GetActive())//�����L���ɂ��Ă�ƃA�C�e�����ЂƂ����o�Ă��Ȃ�
			item[spwan]->Instantiate(GetRand(640), 20, PI / 2);
		
		
	}
	
	//�����܂�ItemInstantiate�֐�
	//�v���C���[�����񂾂�iObject0�Ԃ�isActive��false��������)�Q�[���I��
	if (!Object[0]->GetisActive())
	{
		gameoverflag = true;
	}

	if (GetScore() > 5000)
	{
		gameclearflag = true;
	}

	if (Get_NumOfRepeledEnemy() <= 1000) {
	Set_EnemyNumDensity(EnemyNumDensity::Low);
		
	}
	else if (Get_NumOfRepeledEnemy() >= 1000 && Get_NumOfRepeledEnemy() <= 3000)
	{
		Set_EnemyNumDensity(EnemyNumDensity::Middle);
		
	}
	else if (Get_NumOfRepeledEnemy() >= 3000)
	{
		Set_EnemyNumDensity(EnemyNumDensity::High);
		Set_HIGHTension_ElapsedTime(HIGHTENSION_ELAPSEDFRAME);
	}

	if (Get_EnemyNumDensity() == EnemyNumDensity::High)
	{
		FrameLeft--;//����������֐������(DecreseFrameLeft)
		Set_HIGHTension_ElapsedTime(FrameLeft);

	}

	

	if (Get_HIGHTension_ElapsedTime() < 1)
	{
		Set_EnemyNumDensity(EnemyNumDensity::Low);
		
		SetFrameLeft(HIGHTENSION_ELAPSEDFRAME);
		NumofRepeledEnemy = 0;
	}
	if (Density == EnemyNumDensity::Low)
	{
		Set_HIGHTension_ElapsedTime(HIGHTENSION_ELAPSEDFRAME);
	}
}

void UnitAdmin::Draw()
{
	for (int i = 0; i < OBJECT_MAXNUM ; i++)
	{
		Object[i]->Draw();
	}
	for (int j = 0; j < ITEM_MAXNUM; j++)
	{
		item[j]->DrawItem();
	}

	DrawFormatString(50, 50, GetColor(255, 255, 255), "Score:%d", GetScore());
	DrawFormatString(50, 70, GetColor(255, 255, 255), "���ޓx:%d", NumofRepeledEnemy);
	DrawFormatString(50, 90, GetColor(255, 255, 255), "�����ْ��x�̌p������:%d", Get_HIGHTension_ElapsedTime());
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
	for (int i = 0; i<OBJECT_MAXNUM; i++) {
		if (Object[i]->GetisActive()) {
			for (int b = 0; b<MAX_AMMO; b++) {
				if (Object[i]->GetAmmo(b)->GetisActive()) {

					for (int t = 0; t<OBJECT_MAXNUM; t++) {
						if (Object[t]->GetisActive()) {

							if (Object[i]->GetIsEnemy() != Object[t]->GetIsEnemy()) {

								int bullet_x = Object[i]->GetAmmo(b)->GetPosX();
								int bullet_y = Object[i]->GetAmmo(b)->GetPosY();
								double bullet_area = Object[i]->GetAmmo(b)->GetHitZone();

								int target_x = Object[t]->GetPosX();
								int target_y = Object[t]->GetPosY();
								double target_area = Object[t]->GetHitZone();

								//int barrier_x = barrier->GetPosX();
								//int barrier_y = barrier->GetPosY();
								//double barrier_area = barrier->GetHitZone();

								//�e�Ɣ�e����Unit�Ƃ̋�����肱���̔��a�̍��v���傫���A�^�C�v����s�^�C�v�Ȃ��e���Ă��鎖�ɂȂ�
								if ((bullet_x - target_x)*(bullet_x - target_x) + (bullet_y - target_y)*(bullet_y - target_y) 
									< (bullet_area + target_area)*(bullet_area + target_area)) {
									
									Object[t]->Hit(Object[i]->GetAmmo(b));
									Object[i]->GetAmmo(b)->DestroyAmmo();
									if (Object[t]->tag == Tag::Enemy) {
									score += 20;
									NumofRepeledEnemy += 20;
									
										CannonArtilally::SetArtilally_AimingPos(Object[t]->position);
									}
								}

								/*
								if (barrier->GetisActive())
								{
									if ((bullet_x - barrier_x)*(bullet_x - barrier_x) + (bullet_y - barrier_y)*(bullet_y - barrier_y)
										<
										(bullet_area + barrier_area)*(bullet_area + barrier_area))
									{
										Object[i]->GetAmmo(b)->DestroyAmmo();
									}
								}*/

								
							}

						}
					}

				}
			}
		}
	}
}

//�������Ă����蔲����̂ŉ�����������
//�e�𓖂Ă�ƃQ�b�g��������ɕς���ijudge�Ɠ����A���S���Y����g�ށj
void UnitAdmin::ItemJudge()
{
	//�A�C�e���ƃv���C���[�̂����蔻��
	
		if (Object[0]->GetisActive())
		{
			for (int j = 0; j < ITEM_MAXNUM; j++)
			{
				if (item[j]->GetActive())
				{
					if (Object[0]->GetisActive())
					{
						int item_x = item[j]->position.x;
						int item_y = item[j]->position.y;
						double item_area = item[j]->Gethitzone();

						int target_x = Object[0]->position.x;
						int target_y = Object[0]->position.y;
						double target_hitzone = Object[0]->GetHitZone();

						if((item_x-target_x)*(item_x - target_x)+(item_y - target_y)*(item_y - target_y)
							 <(item_area + target_hitzone)*(item_area + target_hitzone))
						{
							item[j]->DoEffect();
							item[j]->SetActive(false);//���������A�C�e��������
						}
					}
				}
			}
		}
	


	
}
//Vector2D�ɕς���
Vector2D UnitAdmin::GetClosetPosition(const GameObject& closet)
{
	Vector2D returnpos= Vector2D(0,0);
	int range = -1;
	//�Ԃ��̂�isEnmey���قȂ��Ă�CharaObject�̂�
	//��������@�͖̂���
	//�S�����������莀��ł����ꍇ��NULL��Ԃ�

	double returnobj_x = closet.position.x;
	double returnobj_y = closet.position.y;

	for (int i = 0; i < OBJECT_MAXNUM ; i++) {
		if (Object[i]->GetisActive()) {
			//returnoobj��i�Ԗڂ�Object��isenemy�t���O����v���Ȃ�������
			if (closet.GetIsEnemy() != Object[i]->GetIsEnemy())
			{
				//�v�Z�������₷�����邽�߃��[�J���ϐ��𐻍�
				int target_x = Object[i]->position.x;
				int target_y = Object[i]->position.y;
				//tmp_range�ɂ�target��returnobj�̋���������
				double tmp_range = (target_x - returnobj_x)*(target_x - returnobj_x) + (target_y - returnobj_y)*(target_y - returnobj_y);
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
		return 5;//DENSITY_LOW
		break;
	case EnemyNumDensity::Middle:
		return 7;//DENSITY_MIDDLE
		break;
	case EnemyNumDensity::High:
		return 11;//DENSITY_HIGH
		break;
	default:
		return 5;
	}
}