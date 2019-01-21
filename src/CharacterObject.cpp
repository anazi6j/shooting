#include "Include\CharacterObject.h"
#include "Include\Define.h"
#include "DxLib.h"
#include <iostream>
#include "Include\UnitAdmin.h"
#include "Include/Ammo.h"
//#include <memory>
using namespace std;
//弾に被弾した時の処理
CharacterObject::CharacterObject()
{
	
}

void CharacterObject::Hit(shared_ptr<Ammo> ammo)
{
	health -= ammo->GetDamage();
	
	//弾が当たったオブジェクトの列挙子を返す。
	if (health < 0) {
		isActive = false;
		

		
	}
}
//キャラクターの描画を行う
void CharacterObject::Draw()
{
	//「キャラクターを表示するかどうか」がtrueなら
	if (GetisActive())
	{
		//その画像を表示
		DrawRotaGraph(position.x, position.y, 1.0, Angle + PI / 2, GraphicHandle,1.0);
		//弾を最大50発分描画する（
		for (int i = 0; i < MAX_AMMO; i++)
		{
			ammo[i]->DrawObject();
		}
		
		
	}
}

void CharacterObject::DrawHealth()
{
	if (isActive)
	{
		int Color;
		if (isEnemy)
		{
			Color = GetColor(255, 0, 0);
			//GetColor関数でRGBを取得する
		}
		else
		{
			Color = GetColor(0, 255, 0);
		}

		DrawBox(position.x - 10, position.y - 20, position.x + 10, position.y - 17, GetColor(0, 0, 255), 0);
		DrawBox(position.x - 10, position.y - 20, position.x - 10 + health / 5, position.y - 17, Color, 1);
	}
}

/*
inline double CharacterObject::Dot(const CharacterObject* a, const CharacterObject* b)
{
	return a->posX*b->posX + a->posY*b->posY;
}

double CharacterObject::GetAngle(const CharacterObject* a, const CharacterObject* b)
{
	double dot = CharacterObject::Dot(a, b);
	double Amag = sqrt(a->posX*a->posX + a->posY*a->posY);//aの大きさを求める
	double Bmag = sqrt(b->posX*b->posX + b->posY*b->posY);//bの大きさを求める
	double cos = dot / (Amag*Bmag);//cosθを求める
	double radian = acos(cos);//cosθのラジアンを求める
	double degree = radian * RAD_TO_DEG;

	return degree;
}

double CharacterObject::Distance( const CharacterObject* a,  const CharacterObject* b)
{
	float Disx = (a->posX > b->posX) ? (a->posX - b->posX)*(a->posX - b->posX) : (b->posX - a->posX)*(b->posX - a->posX);
	float Disy = (a->posY > b->posY) ? (a->posY - b->posY)*(a->posY - b->posY) : (b->posY - a->posY)*(b->posY - a->posY);

	return sqrt(Disx*Disy);
}
*/