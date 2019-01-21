#include "Include\Ammo.h"
#include <math.h>
#include "Include\Define.h"
#include "Include\CharacterObject.h"
//Ammoオブジェクトにグラフィック、あたり判定、攻撃力、弾を発射した機体が敵か味方かを代入
Ammo::Ammo(int m_ammo_graphic_handle, bool m_isEnemy)
{
	GraphicHandle = m_ammo_graphic_handle;


	hitzone = HITDETECTIONZONE;
	damage = DAMAGE;
	isEnemy = m_isEnemy;
}

//弾を撃つ
void Ammo::Shot(int m_x, int m_y, double m_angle)
{
	position.x= m_x;
	position.y = m_y;
	Angle = m_angle;
	//「画像を表示する」が
	isActive = true;
}


//弾の移動や角度計算を一コマごとに行う
//弾の移動と弾の消滅
void Ammo::Update()
{
	//機体の角度に応じて弾の方向が変わる
	position.x = (position.x + cos(Angle)*AMMOVELOCITY);
	position.y = (position.y + sin(Angle)*AMMOVELOCITY);
	if (position.x < SCREEN_HEIGHT_MIN || SCREEN_HEIGHT_MAX < position.x
		|| position.y < SCREEN_WIDTH_MIN || SCREEN_WIDTH_MAX < position.y) {
		isActive = false;
	}
	
}

//弾を消す

void Ammo::DestroyAmmo()
{
	isActive = false; 
}
