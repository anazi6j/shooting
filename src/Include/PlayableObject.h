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
	char* input;//�L�[�̏����󂯎��
	int invisibletime;//���G�t���[��
	int CurOwnCannon;//�g�p�ł���C��̏��L��

protected:
	BarrierObject* barrier;//unique_ptr�ɕς���
	CannonObject* CannonOwn[2];
public:
	
	//(�v���C���[�̉摜�n���h��,�e�̉摜�n���h��,�L�[�|�C���^�j
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

