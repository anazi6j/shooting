#pragma once
#include "GameObject.h"
#include "Define.h"
class Vector2D;
class UnitAdmin;
class EnemyObject;
class CannonArtilally:public GameObject
{
private:
	

	static Vector2D TargetPos;
	 
public:
	CannonArtilally(UnitAdmin*);
	~CannonArtilally();
	//���E�̊T�O�𓱓�����
	bool CheckEnemyIsinSight();

	//�v���C���[�̎����C�ɁA�G�̈ʒu��m�点��
	static void SetArtilally_AimingPos(const Vector2D& pos)
	{
		TargetPos.x = pos.x;
		TargetPos.y = pos.y;
	}
	//�X�V����
	void Update();
};


