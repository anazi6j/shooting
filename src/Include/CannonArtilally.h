#pragma once
#include "GameObject.h"
#include "Define.h"
class Vector2D;
class UnitAdmin;
class EnemyObject;
class CannonArtilally:public GameObject
{
private:
	

	static Vector2D TargetPos;
	 
public:
	CannonArtilally(UnitAdmin*);
	~CannonArtilally();
	//視界の概念を導入する
	bool CheckEnemyIsinSight();

	//プレイヤーの自走砲に、敵の位置を知らせる
	static void SetArtilally_AimingPos(const Vector2D& pos)
	{
		TargetPos.x = pos.x;
		TargetPos.y = pos.y;
	}
	//更新する
	void Update();
};


