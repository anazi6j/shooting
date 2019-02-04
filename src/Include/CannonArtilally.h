#pragma once
#include "GameObject.h"
#include "Define.h"
#include <memory>

using namespace std;
class Vector2D;
class UnitAdmin;
class EnemyObject;
class Ammo;
class CannonArtilally:public GameObject
{

	
private:
	int ammo_rapid;
	
	Tag tag;
protected:
	unique_ptr<Ammo> ammo[MAX_AMMO];
public:
	
	 Vector2D TargetPos;
	CannonArtilally(int m_ghandle, int m_bullet_graphic_handle,UnitAdmin* m_admin,Tag m_tag);
	~CannonArtilally();
	
	void IncreaseAmmo_rapid();
	void DevideAmmo_rapid(int rate);
	int GetAmmo_rapid() { return ammo_rapid; }
	
	//çXêVÇ∑ÇÈ
	void Update()override;
	void DrawObject()override;
	void Instantiate(double m_Angle, double m_x, double m_y);

};


