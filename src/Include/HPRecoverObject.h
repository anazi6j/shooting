#pragma once
#include "Include/UnitAdmin.h"
#include "Include/ItemBase.h"
class HPRecoverObject:public ItemBase
{

public:
	HPRecoverObject(int m_unit_graphic_handle, UnitAdmin* m_Uadmin);
	~HPRecoverObject();

	virtual void Update()override;

	virtual void DoEffect()override;
};

