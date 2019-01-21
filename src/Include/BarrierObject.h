#pragma once

#include "UnitAdmin.h"
class Ammo;
using namespace std;

class BarrierObject:public GameObject
{
private:
	
	int Barrier_mode;
	int temp;
	
protected:
	int BARRIER_DURATION;//�o���A�̎�������
	
public:
	BarrierObject() {};
	BarrierObject(int m_unit_graphic_handle);
	BarrierObject(int m_unit_graphic_handle, UnitAdmin* m_Uadmin);
	~BarrierObject();
	virtual void Update();
	
	void DecreaseBarrier();//�o���A���W�J���̏ꍇ�A�o���A�������Ă���
	void IncreaseBarrier();//�o���A�̃Q�[�W���ő�܂ő���������
	int SetBarrierMode();//�o���A���[�h��ω�������
	void SetBarrierPos(int x, int y);//�o���A�̈ʒu���v���C���[�̈ʒu�ɃZ�b�g����


	
};

