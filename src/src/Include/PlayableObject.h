#pragma once
#include "CharacterObject.h"
#include "BarrierObject.h"
#include "CannonArtilally.h"
#include <memory>
using namespace std;

class PlayableObject:public CharacterObject
{
private:
	char* input;//�L�[�̏����󂯎��
	int invisibletime;//���G�t���[��
	int CurOwnCannon;//�g�p�ł���C��̏��L��
	
protected:
	
	unique_ptr<BarrierObject> barrier;//unique_ptr�ɕς���
	unique_ptr<CannonArtilally> cannon[2];
	
	//unorderd_map�ɕς���H
public:
	
	//(�v���C���[�̉摜�n���h��,�e�̉摜�n���h��,�L�[�|�C���^�j

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

