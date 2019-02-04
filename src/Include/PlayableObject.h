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
	char* input;//�L�[�̏����󂯎��
	int invisibletime;//���G�t���[��
	int CurOwnCannon;//�g�p�ł���C��̏��L��
	int keyinputframe;
	//�L�[�������Ă���t���[����
	shared_ptr<CannonArtilally>cannon[MAX_CANNON];
	shared_ptr<BarrierObject>barrier;

	
	
public:
	
	//(�v���C���[�̉摜�n���h��,�e�̉摜�n���h��,�L�[�|�C���^�j

	 PlayableObject(int m_chara_graphic_handle, int m_ammo_graphic_handle,
		 int m_barrier_graphic_handle,int m_cannon_graphic_handle, char m_input[256], 
		 UnitAdmin* m_Uadmin,Tag tag);
	~PlayableObject();
	void Instantiate(double, double, double);
	
	void Update();
	//���@�̈ړ�����
	void Move()override;
	//���@�̍U������
	void Attack()override;
	//�C��𐶐�
	void InstantiateCannon();

	//�Q�b�^�E�Z�b�^�֐�
	int Getinvisibletime()const { return invisibletime; }
	
	int GetCannonOwn() { return CurOwnCannon; }
	shared_ptr<BarrierObject> GetBarrier() { return barrier; }
	shared_ptr<CannonArtilally> GetCannon(int i) { return cannon[i]; }
	void IncreseCannonOwn() { CurOwnCannon++; }

	
};

