#include "Include\GameObject.h"
#include "DxLib.h"
#include "Include\Define.h"
#include <math.h>
#include "Include/UnitAdmin.h"


GameObject::GameObject():isActive(false)
{
}

//GameObject‚Ì•`‰æ‚ð‚·‚é
//

void GameObject::DrawObject()
{
	if (isActive)
	{
		
		DrawRotaGraph(position.x, position.y, 1.0, Angle + PI / 2, GraphicHandle, 1, 0);
	}
}

inline double GameObject::GetLength()
{
	
	//return posX * posX + posY * posY;
}



