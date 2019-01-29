#pragma once
#include "CharacterObject.h"
#include "BarrierObject.h"
#include "CannonArtilally.h"
#include <memory>
using namespace std;

class PlayableObject:public CharacterObject
{
private:
	char* input;//キーの情報を受け取る
	int invisibletime;//無敵フレーム
	int CurOwnCannon;//使用できる砲台の所有数
	
protected:
	
	unique_ptr<BarrierObject> barrier;//unique_ptrに変える
	unique_ptr<CannonArtilally> cannon[2];
	
	//unorderd_mapに変える？
public:
	
	//(プレイヤーの画像ハンドル,弾の画像ハンドル,キーポインタ）

	 PlayableObject(int m_chara_graphic_handle, int m_ammo_graphic_handle,
		 int m_barrier_graphic_handle,int m_cannon_graphic_handle, char m_input[256], 
		 UnitAdmin* m_Uadmin,Tag tag);
	~PlayableObject();
	void Instantiate(double, double, double);
	
	void Update();
	void Move()override;
	void Attack()override;
	int Getinvisibletime()const { return invisibletime; }
	void increaseinvisibletime() { invisibletime++; }
	void Set_Artilally_Aimingpos(const Vector2D& pos);
	int GetCannonOwn() { return CurOwnCannon; }
	void IncreseCannonOwn() { CurOwnCannon++; }
	
};

