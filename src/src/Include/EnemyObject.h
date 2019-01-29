#pragma once
#include "CharacterObject.h"
class UnitAdmin;
using namespace std;
 enum class EnemyType 
{
		Air1,
		Air2
};

class EnemyObject:public CharacterObject
{
private:
	
	EnemyType Type;
	int DestroyedEnemyNum;
	
public:
	//�O���t�B�b�N�A�e�A�Q�[���I�u�W�F�N�g�̊Ǘ��|�C���^�A�G�̃^�C�v����
	EnemyObject(int m_unit_graphic_handle, int m_bullet_graphic_handle, UnitAdmin* m_Uadmin,EnemyType EType,Tag m_tag);
	
	~EnemyObject();
	void Instantiate(double, double, double)override;
	void Move()override;
	void Attack();
	void Set_AngleBetweenEnemyandPlayer();
	void Death();
	void Update();


	
};

