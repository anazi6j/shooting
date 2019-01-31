#include "Include\BarrierObject.h"
#include "Include\PlayableObject.h"
#include "Include\Define.h"
#include "DxLib.h"


BarrierObject:: BarrierObject(int m_unit_graphic_handle) : BARRIER_DURATION(BARRIER_DURATION_MAX)
{
	//unique_ptr�̓R�s�[�ł��Ȃ��B������邱�Ƃ͂ł��Ȃ�
	GraphicHandle = m_unit_graphic_handle;
	

	collision.radius = BARRIER_RANGE;

}


BarrierObject::~BarrierObject()
{}

void BarrierObject::Update()
{
	isActive = true;
	DrawObject();
	
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

void BarrierObject::SetBarrierPos(double m_x, double m_y)
{
	
    position.x = m_x;
	position.y = m_y;

}
