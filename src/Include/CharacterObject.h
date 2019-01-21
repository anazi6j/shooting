#pragma once
#include "GameObject.h"
#include "Define.h"
#include <vector>
#include <memory>
using namespace std;

class UnitAdmin;
class Ammo;
class CharacterObject:public GameObject
{
protected:
	shared_ptr<Ammo> ammo[MAX_AMMO];
	
	//BarrierObject* barrier;
	//�̗�
	int health;
	int rapid;
	int EnemyCount;

	//
public:
	
	CharacterObject();
	virtual void Instantiate(double, double, double) = 0;
	//�e�ɔ�e�������̏���
	void Hit(shared_ptr<Ammo>);//�N���X��n���̂ŕ��ׂ����������邽�߂Ƀ|�C���^�n������

	shared_ptr<Ammo> GetAmmo(int i) { return ammo[i]; }
	//EnemyObject��PlayerObject�Ŏ����������B�����ł͏����Ȃ�

	virtual void Update() = 0;
	//�I�u�W�F�N�g��`�悷��
	void Draw();

	//�̗͂�`�悷��
	void DrawHealth();

	
private:


};

