#pragma once
#include "GameObject.h"
#include "Define.h"
#include <vector>
#include <memory>
using namespace std;

class UnitAdmin;
class Ammo;
class CharacterObject:public GameObject
{
protected:
	shared_ptr<Ammo> ammo[MAX_AMMO];
	
	//BarrierObject* barrier;
	//体力
	int health;
	int rapid;
	int EnemyCount;

	//
public:
	
	CharacterObject();
	virtual void Instantiate(double, double, double) = 0;
	//弾に被弾した時の処理
	void Hit(shared_ptr<Ammo>);//クラスを渡すので負荷を小さくするためにポインタ渡しする

	shared_ptr<Ammo> GetAmmo(int i) { return ammo[i]; }
	//EnemyObjectとPlayerObjectで実装を書く。ここでは書かない

	virtual void Update() = 0;
	//オブジェクトを描画する
	void Draw();

	//体力を描画する
	void DrawHealth();

	
private:


};

