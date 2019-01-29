#include "Include\GameObject.h"
#include "DxLib.h"
#include "Include\Define.h"
#include <math.h>
#include "Include/Admin.h"


GameObject::GameObject() :isActive(false)
{
	isEnemy = false;
	Angle = 0;
	isInSight = false;

}

void GameObject::DrawObject()
{
	if (isActive)
	{
		DrawRotaGraph(static_cast<int>(position.x), static_cast<int>(position.y), 1.0, Angle + PI / 2, GraphicHandle, 1, 0);
	}
}




