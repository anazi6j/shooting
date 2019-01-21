#pragma once
#include "CharacterObject.h"
class UnitAdmin;
using namespace std;
typedef enum class EnemyType 
{
		Air1,
		Air2
};

class EnemyObject:public CharacterObject
{
private:
	char* input;//キーの情報を受け取る
	EnemyType Type;
	int DestroyedEnemyNum;
	
public:
	//グラフィック、弾、ゲームオブジェクトの管理ポインタ、敵のタイプを代入
	EnemyObject(int m_unit_graphic_handle, int m_bullet_graphic_handle, UnitAdmin* m_Uadmin,EnemyType EType);
	
	~EnemyObject();
	void Instantiate(double, double, double);
	void Death();
	void Update();


	
};

