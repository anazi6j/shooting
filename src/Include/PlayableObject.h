#pragma once
#include "CharacterObject.h"
#include "BarrierObject.h"
#include "CannonArtilally.h"
#include "CircleCollision.h"
#include <memory>
using namespace std;

class PlayableObject:public CharacterObject
{
private:
	char* input;//キーの情報を受け取る
	int invisibletime;//無敵フレーム
	int CurOwnCannon;//使用できる砲台の所有数
	int keyinputframe;
	//キーを押しているフレーム数
	shared_ptr<CannonArtilally>cannon[MAX_CANNON];
	shared_ptr<BarrierObject>barrier;

	
	
public:
	
	//(プレイヤーの画像ハンドル,弾の画像ハンドル,キーポインタ）

	 PlayableObject(int m_chara_graphic_handle, int m_ammo_graphic_handle,
		 int m_barrier_graphic_handle,int m_cannon_graphic_handle, char m_input[256], 
		 UnitAdmin* m_Uadmin,Tag tag);
	~PlayableObject();
	void Instantiate(double, double, double);
	
	void Update();
	//自機の移動処理
	void Move()override;
	//自機の攻撃処理
	void Attack()override;
	//砲台を生成
	void InstantiateCannon();

	//ゲッタ・セッタ関数
	int Getinvisibletime()const { return invisibletime; }
	
	int GetCannonOwn() { return CurOwnCannon; }
	shared_ptr<BarrierObject> GetBarrier() { return barrier; }
	shared_ptr<CannonArtilally> GetCannon(int i) { return cannon[i]; }
	void IncreseCannonOwn() { CurOwnCannon++; }

	
};

