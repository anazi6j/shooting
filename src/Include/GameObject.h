#pragma once
//敵とプレイヤー、弾丸の基底クラス
#include "Vector2D.h"


using namespace std;
class UnitAdmin;
class GameObject
{
protected:
	
	bool isActive;//trueなら描画、falseなら描画しない
	bool isInSight;//trueなら攻撃、falseなら攻撃しない


	//距離
	double distance;
	//角度
	double Angle;
	

	bool isEnemy;//自機だったらfalse,敵はtrue
	             //立っているフラグが違うオブジェクト同士
	             //に対して攻撃が有効になる
	int GraphicHandle;//DXライブラリが画像を読み込む際のハンドル変数
	UnitAdmin* unit_admin;
    
	//当たり判定（円）
	double hitzone;
public:
	Vector2D position;
	GameObject();//インスタンス化した時に自動で呼ばれる
	
	virtual void Update() = 0;
	//各ゲームオブジェクト（敵、自機、弾丸）のUpdateに実装する。
	//ここでは実装しない
	/*ゲッタ関数*/
	bool GetisActive()const { return isActive; }
	
	double GetAngle()const { return Angle; }
	
	bool GetIsEnemy() const{ return isEnemy; }
	double GetHitZone() { return hitzone; }
	virtual void DrawObject();//描画
	double GetPosX()const { return position.x; }
	double GetPosY()const { return position.y; }
	void SetActive(bool isactive) { isActive = isactive; }

	inline double GetLength();//長さ

	
};

