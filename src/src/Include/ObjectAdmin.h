#pragma once

#include "CharacterObject.h"
#include "Define.h"
#include <memory>

using namespace std;
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
class ObjectAdmin
{
private:
	//characterObjectの0番（プレイヤーの事）のexistがfalseになったらtrueを返す
	bool gameoverflag;
	bool gameclearflag;
	int score;
	//各オブジェクト（プレイヤー・敵・弾・バリア・アイテム）のグラフィックハンドルをこちらで管理する
	int player_graphic_handle;
	int enemy_graphic_handle;
	int bullet_graphic_handle;
	int barrier_graphic_handle;
	int Cannon_graphic_handle;
	
	//敵撃退度
	int NumofRepeledEnemy;
	//
	double HIGHtension_ElapsedFrame;
	double FrameLeft;
	//敵の数
	int EnemyCount;
	//敵の数を制御する
	int CurEnemyLimit;

	Vector2D Cannon_Aimpos;
	
public:
	//コンストラクタ
	
	void(*enemy_density);//敵密度のコントロールをする関数のポインタ

	
	ObjectAdmin(char*);
	
	
	//最大256体のオブジェクト（0番プレイヤー、1~255番敵）のポインタ配列
	
	//CharacterObjectには0番にはプレイヤーの領域、1~255番を敵の領域を動的確保するのでポインタ配列を作る。
	//CharacterObjectは抽象クラスなので実体を作れないので、ポインタ配列にする
    //備考:http://www.himajin2001.com/fswiki/wiki.cgi?page=%B5%BB%BD%D1%C5%AA%BB%A8%C3%CC%2D%A5%DD%A5%A4%A5%F3%A5%BF%C7%DB%CE%F3%A1%A2vector%A4%CE%CD%EE%A4%C8%A4%B7%B7%EA
	

	unique_ptr<CharacterObject> Object[OBJECT_MAXNUM];
	
	
	EnemyNumDensity Density;
	
	
	//プレイヤーのキー入力の確認にcharポインタを使う
	~ObjectAdmin();

	bool GetGameoverFlag() { return gameoverflag; }
	bool GetGameClearFlag() { return gameclearflag; }
	int Get_Score() { return score; }
	int Get_NumofRepeledEnemy() { return NumofRepeledEnemy; }
	void InitGame();

	void Update();

	//UI描画
	void DrawUI();
	
	//弾の当たり判定を行う
	void Check_Collision_BullettoCharacterObject();

	//生成
	void InstantiateEnemy();

	//EnemyNumDensityを制御
	void Controll_EnemyNumDensity();

	//一番近いオブジェクトを返す
	Vector2D GetClosetPosition(const GameObject& closet);
	
	//砲台のターゲットを返す
	Vector2D GetCannon_TargetPos();

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

	double Get_HIGHTension_ElapsedFrame()
	{
		return HIGHtension_ElapsedFrame;
	}

	void Set_HIGHTension_ElapsedFrame(double _Frame)
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
	
	void SetFrameLeft(double Frame)
	{
		FrameLeft = Frame;
	}

	void Set_Cannon_TargetPos(const Vector2D& pos);
	
	//敵密度をコントロールする
	int GetEnemyNumDensity();

	void DecreaseEnemyCount()
	{
		EnemyCount--;
	}
};

