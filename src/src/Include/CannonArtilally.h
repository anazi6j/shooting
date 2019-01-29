#pragma once
#include "GameObject.h"
#include "Define.h"
#include <memory>

using namespace std;
class Vector2D;
class UnitAdmin;
class EnemyObject;
class Ammo;
class CannonArtilally:public GameObject
{

	
private:
	int ammo_rapid;
	bool ThereisEnemy_Hit;
	 
protected:
	unique_ptr<Ammo> ammo[MAX_AMMO];
public:
	
	 Vector2D TargetPos;
	CannonArtilally(int m_ghandle, int m_bullet_graphic_handle,bool isEnemy);
	~CannonArtilally();
	
	void IncreaseAmmo_rapid();
	void DevideAmmo_rapid(int rate);
	int GetAmmo_rapid() { return ammo_rapid; }
	//プレイヤーの自走砲に、敵の位置を知らせる
     void SetArtilally_AimingPos(const Vector2D& pos)
	{
		TargetPos.x = pos.x;
		TargetPos.y = pos.y;
	}
	//更新する
	void Update()override;
	void DrawObject()override;
	void Instantiate(double m_Angle, int m_x, int m_y);
};


