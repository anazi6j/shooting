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
	int BARRIER_DURATION;//�o���A�̎�������
	
public:
	//http://www7b.biglobe.ne.jp/~robe/cpphtml/html02/cpp02027.html
	BarrierObject(int m_unit_graphic_handle):BARRIER_DURATION(BARRIER_DURATION_MAX),temp(0),Barrier_mode(0)
	{}
	 BarrierObject(int m_unit_graphic_handle, UnitAdmin* m_Uadmin);
	~BarrierObject();
	virtual void Update();
	
	void DecreaseBarrier();//�o���A���W�J���̏ꍇ�A�o���A�������Ă���
	void IncreaseBarrier();//�o���A�̃Q�[�W���ő�܂ő���������
	int SetBarrierMode();//�o���A���[�h��ω�������
	void SetBarrierPos(int x, int y);//�o���A�̈ʒu���v���C���[�̈ʒu�ɃZ�b�g����


	
};

