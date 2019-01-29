#pragma once
#include "GameObject.h"
#include "Define.h"
#include <vector>
#include <memory>
using namespace std;

class UnitAdmin;
class Ammo;
enum class Tag {
	Player,
	PlayerArtilally,
	Enemy,
};

class CharacterObject:public GameObject
{

protected:
	shared_ptr<Ammo> ammo[MAX_AMMO];
	
	int health=100;
	int rapid=0;
	int EnemyCount;
	bool Barrierisenabled;
	int Ammo_rapid;
	Tag tag;
public:
	
	CharacterObject();
	virtual void Instantiate(double, double, double) = 0;
	//弾に被弾した時の処理
	void Hit(shared_ptr<Ammo>);//スマートポインタ渡しを使う。

	shared_ptr<Ammo> GetAmmo(int i) { return ammo[i]; }
	//EnemyObjectとPlayerObjectで実装を書く。ここでは書かない

	virtual void Update() = 0;
	virtual void Move() = 0;
	virtual void Attack() = 0;
	//オブジェクトを描画する
	void Draw();

	//体力を描画する
	void DrawHealth();
	void IncreaseAmmo_rapid();
	void DevideAmmo_rapid(int rate);

	int GetAmmo_rapid() { return Ammo_rapid; }
	
	Tag GetTag() { return tag; }

};

