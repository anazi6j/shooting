#include "Include\ItemBase.h"
#include "Include/Define.h"
#include "DxLib.h"


ItemBase::ItemBase():isActive(false)
{
}


ItemBase::~ItemBase()
{
}

void ItemBase::Instantiate(double m_x, double m_y, double m_Angle)
{
	position.x = m_x;
	position.y = m_y;

	Angle = m_Angle;

	isActive = true;
}

void ItemBase::ItemMove()
{
	position.y += 5;
}

void ItemBase::DrawItem()
{
	if (GetActive())
	{
		DrawRotaGraph(static_cast<int>(position.x), static_cast<int>(position.y), 1.0, Angle + PI / 2, graphicHandle, 1, 0);
	}
}
//�A�C�e�����X�N���[���̊O�ɂ��邩�ǂ����`�F�b�N����
bool ItemBase::IsOutOfScreen()
{
	return SCREEN_HEIGHT_MIN > position.y;
}