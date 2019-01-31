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
#include "Include/CircleCollision.h"
#include <iostream>

UnitAdmin::UnitAdmin(char* m_key) :gameoverflag(false), gameclearflag(false), score(0), Density(EnemyNumDensity::Low),
NumofRepeledEnemy(0), CurEnemyLimit(0)
, EnemyCount(0), HIGHtension_ElapsedFrame(HIGHTENSION_ELAPSEDFRAME_MAX), FrameLeft(HIGHTENSION_ELAPSEDFRAME_MAX)

{
	///画像のロード
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
		cout << "プレイヤーオブジェクトの領域を確保できません\n";
	}
	for (int i = 1; i < OBJECT_MAXNUM; i++) {
		try {
			Object[i] = make_unique<EnemyObject>(enemy_graphic_handle, bullet_graphic_handle, this, EnemyType::Air1, Tag::Enemy);
		}
		catch(bad_alloc)
		{
			cout << "敵オブジェクトの領域を確保できません\n";
		}
	}
	}
	
	
	

//
UnitAdmin::~UnitAdmin()
{

}
//初期化（プレイヤーを生成する）
void UnitAdmin::InitGame()
{
	Object[0]->Instantiate(SCREEN_HEIGHT_MAX/2, SCREEN_WIDTH_MAX/2, -PI / 2);
	
}

void UnitAdmin::Update()
{
	int RandomNum = GetEnemyNumDensity();

	//プレイヤー(Objectの0番）と敵（OBJECT_MAXNUM分）のUpdateを呼び出す
	for (int i = 0; i < OBJECT_MAXNUM ; i++)
	{
		Object[i]->Update();
	}
	Controll_EnemyNumDensity();
	//ここからInstantiateEnemy関数に入れる予定のコード

	int spwan = GetRand(RandomNum - 2) + 1;
	int dice = GetRand(10);

	if (EnemyCount < ENEMY_INSTANTIABLE_MAX) {
		if (dice == 1) {
			//spwan番目（無作為に呼ばれた番号）の要素のObjectが非表示だったら
			if (!Object[spwan]->GetisActive())
			{
				//そのObjectを出現させる
				Object[spwan]->Instantiate(GetRand(640), 20, PI / 2);
			}
		}
	}

	//↑ここまでInstantiateEnemy関数に入れる予定のコード
	
	//プレイヤーが死んだら（Object0番のisActiveがfalseだったら)ゲーム終了
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
	DrawFormatString(50, 70, GetColor(255, 255, 255), "撃退度:%d", Get_NumofRepeledEnemy());
	DrawFormatString(50, 90, GetColor(255, 255, 255), "高い緊張度の継続時間:%d", static_cast<int>(Get_HIGHTension_ElapsedFrame()));
}

void UnitAdmin::DrawHitPoint()
{
	for (int i = 0; i < OBJECT_MAXNUM ; i++)
	{
		Object[i]->DrawHealth();
	}
}


//bulletとCharcterObjectの当たり判定を総当たりする
//
void UnitAdmin::Check_Collision_BullettoCharacterObject()
{
	
     
		//assert(attackernum,bulletnum,targetnum)

		//for文
		//ゲーム中に描画されている攻撃する側のオブジェクト、その弾、被弾する側のオブジェクトを取得
		//取得した上で当たり判定
	for (int attackernum = 0; attackernum < OBJECT_MAXNUM; attackernum++) {
		if (Object[attackernum]->GetisActive()) {

			for (int bulletnum = 0; bulletnum <MAX_AMMO; bulletnum++) {

				if (Object[attackernum]->GetAmmo(bulletnum)->GetisActive()) {

					for (int targetnum = 0; targetnum <OBJECT_MAXNUM; targetnum++) {
						if (Object[targetnum]->GetisActive()) {
			               //当たり判定
							if (Object[attackernum]->GetTag()!= Object[targetnum]->GetTag()) {

								if(CircleCollision::Circle_isCollide(
									Object[attackernum]->GetAmmo(bulletnum)->GetCircleCollision(),
									Object[targetnum]->GetCircleCollision())
									)
								{
									Object[targetnum]->Hit(Object[attackernum]->GetAmmo(bulletnum));
									Object[attackernum]->GetAmmo(bulletnum)->DestroyAmmo();
									//被弾したオブジェクトのタグが「Enemy」なら得点が入る
									if (Object[targetnum]->GetTag() == Tag::Enemy) {
									score += ADD_SCORE;
									NumofRepeledEnemy += ADD_SCORE;
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

	//100=NUMOF_REPELEDENEMY_LOW
	//300=NUMOF_REPELEDENEMY_HIGH
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

//Vector2Dに変える
Vector2D UnitAdmin::GetClosetPosition(const GameObject& closet)
{
	Vector2D returnpos= Vector2D(0,0);
	double range = -1;

	for (int i= 0; i< OBJECT_MAXNUM ; i++) {
		if (Object[i]->GetisActive()) {
			//タグが一致しなかったら
			if (closet.GetTag() != Object[i]->GetTag())
			{
				double tmp_range = Vector2D::Distance(Object[i]->position, closet.position);
				
				returnpos = Object[i]->position;
				/*

				
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
				*/
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