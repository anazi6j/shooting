#pragma once
#include "ItemBase.h"
#include "Ammo.h"
class UnitAdmin;
using namespace std;
class CannonItemObject:public ItemBase
{
private:
	Ammo* ammo[100];
	bool IsEnemy;

public:
	CannonItemObject(int m_unit_graphic_handle, int m_bullet_graphic_handle, UnitAdmin* m_Uadmin);
	~CannonItemObject();

	virtual void Update()override;
	virtual void DoEffect()override;
	Ammo* GetAmmo(int i)
	{
		return ammo[i];
	}
	bool GetIsEnemy() { return IsEnemy; }
	
};

