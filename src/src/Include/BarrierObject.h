#pragma once

#include "Admin.h"
class Ammo;
using namespace std;

class BarrierObject:public GameObject
{
private:
	
	int Barrier_mode;
	int temp;
	
protected:
	int BARRIER_DURATION;//バリアの持続時間
	
public:
	//http://www7b.biglobe.ne.jp/~robe/cpphtml/html02/cpp02027.html
	BarrierObject(int m_unit_graphic_handle):BARRIER_DURATION(BARRIER_DURATION_MAX),temp(0),Barrier_mode(0)
	{}
	 BarrierObject(int m_unit_graphic_handle, UnitAdmin* m_Uadmin);
	~BarrierObject();
	virtual void Update();
	
	void DecreaseBarrier();//バリアが展開中の場合、バリアが減っていく
	void IncreaseBarrier();//バリアのゲージを最大まで増加させる
	int SetBarrierMode();//バリアモードを変化させる
	void SetBarrierPos(int x, int y);//バリアの位置をプレイヤーの位置にセットする


	
};

