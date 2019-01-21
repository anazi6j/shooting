#include "Include\BarrierObject.h"
#include "Include\PlayableObject.h"
#include "Include\Define.h"
#include "DxLib.h"

BarrierObject:: BarrierObject(int m_unit_graphic_handle, UnitAdmin* m_Uadmin)
{
	//unique_ptrはコピーできない。代入することはできない
	GraphicHandle = m_unit_graphic_handle;
	unit_admin = m_Uadmin;

	hitzone = BARRIER_RANGE;
	//敵かどうかをtrueにする
	isEnemy = false;
}

BarrierObject::BarrierObject(int  m_unit_graphic_handle)
{
	GraphicHandle = m_unit_graphic_handle;
	hitzone = BARRIER_RANGE;

	isEnemy = false;
}

BarrierObject::~BarrierObject()
{}

void BarrierObject::Update()
{
	Barrier_mode = SetBarrierMode();

	if (Barrier_mode >= 1) {
		isActive = true;
		
		
	}
	else if (Barrier_mode == 0)
	{
		isActive = false;
	}

	if (GetisActive()) 
	{//バリアが描画されていたら
		
		DecreaseBarrier();//バリアゲージが減っていく
	}
	else
	{
		IncreaseBarrier();
	}
	
	
}

int BarrierObject::SetBarrierMode() 
{
	
	if (CheckHitKey(KEY_INPUT_B) == 1)
	{
		if (temp == 0 && GetisActive() == false) {
			temp++;
	  }
		else if (temp >= 1 && GetisActive() == true) {
			temp = 0;
		}
    }

	return temp;
}



void BarrierObject::DecreaseBarrier()
{
	if (!BARRIER_DURATION < 0) {
		BARRIER_DURATION--;//バリアゲージが減っていく

	}
}

//バリアゲージ
void BarrierObject::IncreaseBarrier()
{
	if (!BARRIER_DURATION >= BARRIER_DURATION_MAX)
	{
		BARRIER_DURATION++;
	}
}

void BarrierObject::SetBarrierPos(int x, int y)
{
    position.x = x;
	position.y = y;
}
