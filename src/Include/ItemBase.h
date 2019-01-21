#pragma once
#include "Vector2D.h"
class UnitAdmin;
class ItemBase
{
protected:
	int graphicHandle;
	bool isActive;//trueÇ»ÇÁï`âÊÅAfalseÇ»ÇÁï`âÊÇµÇ»Ç¢


	UnitAdmin* unit_admin;
	//äpìx
	double Angle;
	bool CheckObjectisOutofscreen;
	double hitzone;

public:
	Vector2D position;
	void SetActive(bool m_isactive) { isActive = m_isactive; }
	bool GetActive()const { return isActive; }
	double Gethitzone()const { return hitzone; }
	ItemBase();
	virtual ~ItemBase();
	virtual void DoEffect() = 0;
	virtual void Update() = 0;
	virtual void Instantiate(double m_x, double m_y, double Angle);
	void ItemMove();
	virtual void DrawItem();
	bool IsOutOfScreen();
};

