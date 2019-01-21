#pragma once

//円周率
const double PI = 3.141592;
//生成可能なcannonItemの数
const int CANNON_MAXNUM = 2;
//生成可能なObjectの数
const int OBJECT_MAXNUM = 256;
//生成可能なItemの数
const int ITEM_MAXNUM = 10;
//弾のダメージ
const int DAMAGE = 1;
//自機の無敵フレーム
const int INVISIBLEFRAME = 100;
//キャラクターのあたり判定（円形）
const int HITDETECTIONZONE = 10;
//それぞれ、スクリーンの縦横のパラメータ
const double SCREEN_HEIGHT_MAX = 640;
const double SCREEN_HEIGHT_MIN = 0;
const double SCREEN_WIDTH_MIN = 0;
const double SCREEN_WIDTH_MAX = 480;
//ここまで

//生成する弾の数
const int MAX_AMMO = 50;
//弾の撃つ速度
const int RAPID_RATE = 10;
//弾の速度
const double AMMOVELOCITY = 10.0;
//ラジアンから度への変換
const double RAD_TO_DEG = 57.3248407643;
//敵機の攻撃開始距離。これより小さければ攻撃開始
const double DISTANCE_RANGE = 100;
//バリアのあたり判定距離（円形）
const int BARRIER_RANGE = 30;
//バリアの最大作動時間
const int BARRIER_DURATION_MAX = 100;
//画面内に生成できる敵機の数
const int ENEMY_INSTANTIABLE_MAX = 1;

//以下、敵の生成密度

const int ENEMYDENSITY_LOW = 2;

const int ENEMYDENSITY_MIDDLE = 5;

const int ENEMYDENSITY_HIGH = 10;

//以上、敵の生成密度

const double HIGHTENSION_ELAPSEDFRAME = 100;

//回復量
const int HP_RECOVER = 100;
