#include "Include/CannonItemObject.h"
#include "Include/Admin.h"


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
	//�A�C�e�����X�N���[���O�ɏo�Ă邩�`�F�b�N����
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
	//�v���C���[�̖C�䏊�L��������₷
}
