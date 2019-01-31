#pragma once
#include "GameObject.h"
#include "Define.h"
#include <vector>
#include <memory>
using namespace std;

class UnitAdmin;
class Ammo;
class BarrObject;
class CannonArtilally;
class BarrierObject;


class CharacterObject:public GameObject
{

protected:
	shared_ptr<Ammo> ammo[MAX_AMMO];
	int health=100;
	int rapid=0;
	int EnemyCount;
	bool Barrierisenabled;
	int Ammo_rapid;
	
public:
	
	CharacterObject();
	virtual void Instantiate(double, double, double) = 0;
	//�e�ɔ�e�������̏���
	void Hit(shared_ptr<Ammo>);
	shared_ptr<Ammo> GetAmmo(int i)const { return ammo[i]; }
	//EnemyObject��PlayerObject�Ŏ����������B�����ł͏����Ȃ�

	virtual void Update() = 0;
	virtual void Move() = 0;
	virtual void Attack() = 0;
	//�I�u�W�F�N�g��`�悷��
	void Draw();

	//�̗͂�`�悷��
	void DrawHealth();
	void IncreaseAmmo_rapid();
	void DevideAmmo_rapid(int rate);
	int GetAmmo_rapid()const { return Ammo_rapid; }
	Tag GetTag()const { return tag; }

};

