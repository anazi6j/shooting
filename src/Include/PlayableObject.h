#pragma once
#include "CharacterObject.h"
#include "BarrierObject.h"
#include "CannonItemObject.h"
#include <memory>
using namespace std;

class BarrierObject;
class CannonObject;
class PlayableObject:public CharacterObject
{
private:
	char* input;//キーの情報を受け取る
	int invisibletime;//無敵フレーム
	int CurOwnCannon;//使用できる砲台の所有数

protected:
	BarrierObject* barrier;//unique_ptrに変える
	CannonObject* CannonOwn[2];
public:
	
	//(プレイヤーの画像ハンドル,弾の画像ハンドル,キーポインタ）
	PlayableObject() {};
	 PlayableObject(int m_chara_graphic_handle, int m_ammo_graphic_handle, int m_barrier_graphic_handle, char m_input[256], UnitAdmin* m_Uadmin);
	~PlayableObject();
	void Instantiate(double, double, double);
	
	void Update();
	int Getinvisibletime() { return invisibletime; }
	void increaseinvisibletime() { invisibletime++; }
	int GetCannonOwn() { return CurOwnCannon; }
	void IncreseCannonOwn() { CurOwnCannon++; }
	
};

