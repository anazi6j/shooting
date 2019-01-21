#include "Include\PlayableObject.h"
#include "DxLib.h"
#include "Include\Ammo.h"
#include "Include\UnitAdmin.h"
#include "Include\BarrierObject.h"

PlayableObject::PlayableObject(int m_chara_graphic_handle, int m_ammo_graphic_handle, int m_barrier_graphic_handle,char m_input[256], UnitAdmin* m_Uadmin)
{
	input = m_input;
	GraphicHandle = m_chara_graphic_handle;
	//当たり判定の設定
	hitzone = HITDETECTIONZONE;
	//「敵かどうか」をfalseにする
	isEnemy = false;

	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i] = make_unique<Ammo>(m_ammo_graphic_handle,!isEnemy);
	}
	barrier = new BarrierObject(m_barrier_graphic_handle);
	health = 10000;
}


PlayableObject::~PlayableObject()
{
	
	
	delete barrier;
}

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
	
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i]->Update();
	}
	

	if (input[KEY_INPUT_UP] == 1)
	{
		if (position.y > 0)
		{
			position.y -= 5;
			//posY -= 5;
		}
	}

	if (input[KEY_INPUT_DOWN] == 1)
	{
		if (position.y < SCREEN_WIDTH_MAX)
		{
			position.y += 5;
			//posY += 5;
		}
	}

	if (input[KEY_INPUT_LEFT] == 1) {
		if (position.x > 0) {
		
			position.x -= 5;
		}
	}

	if (input[KEY_INPUT_RIGHT] == 1)
	{
		if (position.x < SCREEN_WIDTH_MAX)
		{
			position.x += 5;
			
		}
	}

	if (input[KEY_INPUT_Z])
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
	if (input[KEY_INPUT_B]) {
		barrier->SetActive(true);
		barrier->DrawObject();
		barrier->SetBarrierPos(position.x, position.y);
	}

}