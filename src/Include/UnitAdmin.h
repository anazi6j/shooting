#pragma once

#include "CharacterObject.h"
#include "Define.h"
#include <memory>

using namespace std;
class BarrierObject;
class ItemBase;
//メインループから、初期化、更新、描画関数を実行するためのクラス

//敵の数密度。スコアが伸びるに応じて増していく
enum class EnemyNumDensity
{
	Low = 5,
	Middle = 10,
    High = 20,
    
};
enum class Tension
{
	LOW,
	MIDDLE,
	HIGH
};
class UnitAdmin
{
private:
	//characterObjectの0番（プレイヤーの事）のexistがfalseになったらtrueを返す
	bool gameoverflag;
	int score;
	//各オブジェクト（プレイヤー・敵・弾・バリア・アイテム）のグラフィックハンドルをこちらで管理する
	int player_graphic_handle;
	int enemy_graphic_handle;
	int bullet_graphic_handle;
	int barrier_graphic_handle;
	int Cannon_graphic_handle;
	int HPRecover_graphic_handle;
	//敵撃退度
	int NumofRepeledEnemy;
	//
	int HIGHtension_ElapsedFrame;
	int FrameLeft;
public:
	//コンストラクタ
	UnitAdmin() {};

	UnitAdmin(char*);
	
	//敵の数
	int EnemyCount;
	//敵の数を制御する
	int CurEnemyLimit;
	//最大256体のオブジェクト（0番プレイヤー、1~255番敵）のポインタ配列
	
	//CharacterObjectには0番にはプレイヤーの領域、1~255番を敵の領域を動的確保するのでポインタ配列を作る。
	//CharacterObjectは抽象クラスなので実体を作れないので、ポインタ配列にする
    //備考:http://www.himajin2001.com/fswiki/wiki.cgi?page=%B5%BB%BD%D1%C5%AA%BB%A8%C3%CC%2D%A5%DD%A5%A4%A5%F3%A5%BF%C7%DB%CE%F3%A1%A2vector%A4%CE%CD%EE%A4%C8%A4%B7%B7%EA
	//CharacterObject *Object[OBJECT_MAXNUM];
	shared_ptr<CharacterObject> Object[OBJECT_MAXNUM];
	BarrierObject* barrier;//スマートポインタに入れ替える（unique_ptr)
	//ItemBaseは0から2番に砲台アイテムの領域を確保し、3番から5番に体力回復アイテムの領域を確保する。
	//
	ItemBase* item[ITEM_MAXNUM];
	EnemyNumDensity Density;
	
	
	//プレイヤーのキー入力の確認にcharポインタを使う
	~UnitAdmin();

	bool GetGameoverFlag() { return gameoverflag; }

	void InitGame();

	void Update();

	//描画
	void Draw();
	//HP描画
	void DrawHitPoint();

	int GetScore() { return score; }

	//弾の当たり判定を行う
	void Judge();

	//アイテムのあたり判定を行う
	void ItemJudge();

	//一番近いオブジェクトを返す
	Vector2D GetClosetPosition(const GameObject& closet);


	//DestroyedEnemyCountのセッタ関数
	void Set_NumofRepeledEnemy (int num)
	{
		NumofRepeledEnemy = num;
	}

	int Get_NumOfRepeledEnemy()
	{
		return NumofRepeledEnemy;
	}

	//HIGHTension_ElapsedTimeのゲッタ・セッタ関数

	int Get_HIGHTension_ElapsedTime()
	{
		return HIGHtension_ElapsedFrame;
	}

	void Set_HIGHTension_ElapsedTime(int _Frame)
	{
		HIGHtension_ElapsedFrame = _Frame;
	}

	//EnemyNumDensityのゲッタ関数とセッタ関数

	EnemyNumDensity Get_EnemyNumDensity()
	{
		return Density;
	}

	void Set_EnemyNumDensity(EnemyNumDensity _Density)
	{
		Density = _Density;
	}
	
	void SetFrameLeft(int Frame)
	{
		FrameLeft = Frame;
	}
	//敵密度をコントロールする
	int GetEnemyNumDensity();
};

