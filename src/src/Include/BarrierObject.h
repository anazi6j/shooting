#pragma once

#include "ObjectAdmin.h"
class Ammo;
using namespace std;

class BarrierObject:public GameObject
{
private:
	
	
	
protected:
	int BARRIER_DURATION;//�o���A�̎�������
	
public:
	//http://www7b.biglobe.ne.jp/~robe/cpphtml/html02/cpp02027.html
	BarrierObject(int m_unit_graphic_handle);
	
	~BarrierObject();
	virtual void Update();
	
	void DecreaseBarrier();//�o���A���W�J���̏ꍇ�A�o���A�������Ă���
	void IncreaseBarrier();//�o���A�̃Q�[�W���ő�܂ő���������
	//int SetBarrierMode();//�o���A���[�h��ω�������
	void SetBarrierPos(double x, double y);//�o���A�̈ʒu���v���C���[�̈ʒu�ɃZ�b�g����


	
};

