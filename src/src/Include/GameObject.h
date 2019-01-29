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
	
	UnitAdmin* unit_admin;//なぜ生ポインタを使ってるのかというと、
	///UnitAdminクラス側からこのクラスを継承したクラスオブジェクトをインスタンス化する際、UnitAdminのthisポインタが必要に
	//なるからである
    
	//当たり判定（円）
	double hitzone;

	
public:
	int GraphicHandle;//DXライブラリが画像を読み込む際のハンドル変数
	Vector2D position;
	
	GameObject();
	
	virtual void Update() = 0;

	virtual void DrawObject();//描画


	//各ゲームオブジェクト（敵、自機、弾丸）のUpdateに実装する。
	//ここでは実装しない
	

	//以下ゲッタ・セッタ関数
	bool GetisActive()const { return isActive; }
	double GetAngle()const { return Angle; }
	
	bool GetIsEnemy() const{ return isEnemy; }

	double GetHitZone() const{ return hitzone; }

	void SetHitzone(double value) { hitzone = value; }

	bool GetisInSight()const { return isInSight; }

	void SetActive(bool isactive) { isActive = isactive; }

	double GetDistance()const { return distance; }

	


	
};

