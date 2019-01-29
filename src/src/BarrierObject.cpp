#include "Include\BarrierObject.h"
#include "Include\PlayableObject.h"
#include "Include\Define.h"
#include "DxLib.h"


BarrierObject:: BarrierObject(int m_unit_graphic_handle, UnitAdmin* m_Uadmin) :temp(0), BARRIER_DURATION(BARRIER_DURATION_MAX), Barrier_mode(0)
{
	//unique_ptr�̓R�s�[�ł��Ȃ��B������邱�Ƃ͂ł��Ȃ�
	GraphicHandle = m_unit_graphic_handle;
	unit_admin = m_Uadmin;

	hitzone = BARRIER_RANGE;

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
	{//�o���A���`�悳��Ă�����
		
		DecreaseBarrier();//�o���A�Q�[�W�������Ă���
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
	if (BARRIER_DURATION > 0) {
		BARRIER_DURATION--;//�o���A�Q�[�W�������Ă���

	}
}

//�o���A�Q�[�W
void BarrierObject::IncreaseBarrier()
{
	if (BARRIER_DURATION > BARRIER_DURATION_MAX)
	{
		BARRIER_DURATION++;
	}
}

void BarrierObject::SetBarrierPos(int x, int y)
{
    position.x = x;
	position.y = y;
}
