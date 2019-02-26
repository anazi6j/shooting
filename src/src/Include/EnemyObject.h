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
	
	EnemyObject(int m_object_graphic_handle, int m_bullet_graphic_handle, ObjectAdmin* m_Oadmin,EnemyType EType,Tag m_tag);
	
	~EnemyObject();
	void Instantiate(double, double, double)override;
	void Move()override;
	void Attack();
	void Set_AngleBetweenEnemyandPlayer();
	void Death();
	void Update();


	
};

