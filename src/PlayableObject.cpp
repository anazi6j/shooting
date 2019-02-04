#include "Include\PlayableObject.h"
#include "DxLib.h"
#include "Include\Ammo.h"
#include "Include\Admin.h"
#include "Include\BarrierObject.h"
#include "Include/CannonArtilally.h"
#include <iostream>
#include <cassert>
#include "Include/Input.h"
PlayableObject::PlayableObject(int m_chara_graphic_handle, int m_ammo_graphic_handle,
	int m_barrier_graphic_handle, int m_cannon_graphic_handle, char m_input[256], UnitAdmin* m_Uadmin, Tag m_tag)
	:input(m_input), invisibletime(0), CurOwnCannon(2), keyinputframe(0)
{
	input = m_input;
	GraphicHandle = m_chara_graphic_handle;
	
	//当たり判定の設定
	collision.radius = RADIUS;
	tag = m_tag;
	
	health = PLAYABLEOB_HEALTH;
	for (int i = 0; i < MAX_AMMO; i++)
	{
		
		try {
			ammo[i] = make_unique<Ammo>(m_ammo_graphic_handle, m_tag);
		}
		catch (bad_alloc)
		{
			cout << "弾オブジェクトの領域確保に失敗しました。メモリが足りない可能性があります";
		}
	}

	for (int j = 0; j < MAX_CANNON; j++)
	{
		
		try {
			cannon[j] = make_unique<CannonArtilally>(m_cannon_graphic_handle, m_ammo_graphic_handle,m_Uadmin, m_tag);
		}
		catch (bad_alloc)
		{
			cout << "砲台オブジェクトの領域確保に失敗しました。メモリが足りない可能性があります";
		}

		try {
			barrier = make_shared<BarrierObject>(m_barrier_graphic_handle);
		}
		catch (bad_alloc)
		{
			cout << "バリアオブジェクトの領域確保に失敗しました。メモリが足りない可能性があります";
		}
	
		tag = m_tag;
	}
}

	PlayableObject::~PlayableObject()
	{}

//プレイヤーを出現させる
void PlayableObject::Instantiate(double m_xpos, double m_ypos, double m_angle)
{
	 position.x= m_xpos;
	position.y = m_ypos;
	Angle = m_angle;
	isActive = true;

}
void PlayableObject::Update()
{
	collision.position = position;
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i]->Update();
	}

	
	for (int j = 0; j < MAX_CANNON; j++)
	{
		cannon[j]->Update();
		cannon[j]->DrawObject();
	}
	
	
	Move();
	Attack();
	InstantiateCannon();
	/*SetBarrier*/
	if (Input::GetKeyPressed(input, KEY_INPUT_B)) {
		barrier->SetActive(true);
		barrier->DrawObject();
		barrier->SetBarrierPos(position.x, position.y);
	}
}

void PlayableObject::Move()
{
	//assertを入れる（xとyの位置に制限を掛ける）
	//clamp関数を作り制限をかける
	if (Input::GetKeyPressed(input,KEY_INPUT_UP))
	{
		if (position.y > 0)
		{
			position.y -= 5;
			//posY -= 5;
		}
	}

	if (Input::GetKeyPressed(input, KEY_INPUT_DOWN))
	{
		if (position.y < SCREEN_WIDTH_MAX)
		{
			position.y += 5;
			
		}
	}

	if (Input::GetKeyPressed(input,KEY_INPUT_LEFT))
	{
		if (position.x > 0) {

			position.x -= 5;
		}
	}

	if (Input::GetKeyPressed(input,KEY_INPUT_RIGHT))
	{
		if (position.x < SCREEN_WIDTH_MAX)
		{
			position.x += 5;

		}
	}
}

void PlayableObject::Attack()
{
	
	if(Input::GetKeyPressed(input,KEY_INPUT_Z))
	{
		
		//rapidの値がRAPID_SPEED以上になったら発射
		 
			rapid++;
			rapid %= RAPID_RATE;
			if (rapid == 1) {
				for (int i = 0; i < MAX_AMMO; i++)//zキーを押すと、まだ発射していない弾を探して、shot関数に現在の座標を与える
				{
					if (!ammo[i]->GetisActive()) {//発射していない弾があったら(i番目の弾の「画像を表示している」がfalseだったら
						ammo[i]->Shot(position.x, position.y, Angle);//弾を発射
						break;
					}
				}
			}
		
	}
}

void PlayableObject::InstantiateCannon()
{
	if (Input::GetKeyDown(input, KEY_INPUT_SPACE))
	{
		if (CurOwnCannon >= 0) {
			for (int i = 0; i < MAX_CANNON; i++)
			{
				if(!cannon[i]->GetisActive())
				cannon[i]->Instantiate(Angle, position.x, position.y -PLAYER_FORWARDPOS_Y);
				
			}
		}
	}
}



//barrier、cannon共にdrawobjectが直接書かれてないと描画されない