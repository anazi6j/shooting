#include "Include/CannonItemObject.h"
#include "Include/UnitAdmin.h"


CannonItemObject::CannonItemObject(int m_unit_graphic_handle, int m_bullet_graphic_handle, UnitAdmin* m_Uadmin)
{
	graphicHandle = m_unit_graphic_handle;
	unit_admin = m_Uadmin;
	SetActive(false);
	
}


CannonItemObject::~CannonItemObject()
{
	
}

void CannonItemObject::Update()
{
	//アイテムがスクリーン外に出てるかチェックする
	CheckObjectisOutofscreen = IsOutOfScreen();
	if (CheckObjectisOutofscreen)
	{
		SetActive(false);
	}
	else
	{
		SetActive(true);
	}
	ItemMove();
}

void CannonItemObject::DoEffect()
{
	//プレイヤーの砲台所有数を一つ増やす
}
