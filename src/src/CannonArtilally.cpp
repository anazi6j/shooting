#include "include/CannonArtilally.h"
#include "Include/Vector2D.h"
#include "Include/ObjectAdmin.h"
#include "Include/Define.h"
#include "Include/Ammo.h"
#include <iostream>
#include "DxLib.h"
CannonArtilally::CannonArtilally(int m_ghandle, int m_bullet_graphic_handle, ObjectAdmin* m_admin,Tag m_tag)
{
	
	ammo_rapid = 0;
	//“G‚ðŽæ“¾‚·‚é
	GraphicHandle = m_ghandle;
	tag = m_tag;
	unit_admin = m_admin;
	for (int i = 0; i < MAX_AMMO; i++)
	{
		try {
			ammo[i] = make_unique<Ammo>(m_bullet_graphic_handle, m_tag);
		}
		catch (const std::bad_alloc& error)
		{
			std::cout << "ƒƒ‚ƒŠ‚ÌŠm•Û‚ÉŽ¸”s‚µ‚Ü‚µ‚½" << error.what() << '\n';
		}
	}
}


CannonArtilally::~CannonArtilally()
{
}

void CannonArtilally::IncreaseAmmo_rapid()
{
	ammo_rapid++;
}

void CannonArtilally::DevideAmmo_rapid(int rate)
{
	ammo_rapid %= rate;
}
void CannonArtilally::Instantiate(double m_Angle,double m_x,double m_y)
{
	Angle = m_Angle;
	position.x = m_x;
	position.y = m_y;

	isActive = true;
}

void CannonArtilally::Update()
{
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i]->Update();
	}

	//’e‚É“–‚½‚Á‚½“G‚ª‚¢‚È‚¢‚È‚ç(ThereisEnemyHit‚ªfalsejVector2D(0,0)‚ð•Ô‚·
	Vector2D target_position = unit_admin->GetCannon_TargetPos();

	if (target_position != Vector2D(0, 0))
	{
		Angle =atan2(target_position.y-this->position.y,target_position.x-this->position.x);
	}

	IncreaseAmmo_rapid();
	DevideAmmo_rapid(RAPID_RATE);




	if (GetAmmo_rapid() == 9)
	{
		for (int i = 0; i < MAX_AMMO; i++)
		{
			if (!ammo[i]->GetisActive())
			{
				if (target_position != Vector2D(0, 0)) {
					ammo[i]->Shot(position.x, position.y, Angle);

					break;
				}
			}
		}
	}
}

void CannonArtilally::DrawObject()
{
	if (isActive)
	{
		DrawRotaGraph(static_cast<int>(position.x), static_cast<int> (position.y), 1.0, Angle + PI / 2, GraphicHandle, static_cast<int>(1));
	}

	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i]->DrawObject();
	}
}

