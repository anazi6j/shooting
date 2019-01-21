#pragma once
#include "GameObject.h"
class CharacterObject;
class Ammo:public GameObject
{
private:
	int damage;

public:
	//Ammoオブジェクトにグラフィック、あたり判定、攻撃力、弾を発射した機体が敵か味方かを代入
	Ammo(int,bool);
	void Shot(int, int, double);
	void Update();
	int GetDamage() { return damage; }

	//弾が当たったオブジェクトを返す
	CharacterObject* ReturnHitObject();
	void DestroyAmmo();
};

