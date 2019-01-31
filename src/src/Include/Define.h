#pragma once

//円周率
const double PI = 3.141592;
//生成可能なcannonItemの数
const int CANNON_MAXNUM = 2;
//生成可能なObjectの数
const int OBJECT_MAXNUM = 256;
//弾のダメージ
const int DAMAGE = 1;
//敵に弾を当てた時のスコア
const int ADD_SCORE = 20;
//自機の無敵フレーム
const int INVISIBLEFRAME = 100;
//キャラクターのあたり判定（円形）
const int RADIUS = 10;
//スクリーンの高さ（最大）
const double SCREEN_HEIGHT_MAX = 640;
//スクリーンの高さ（最小）
const double SCREEN_HEIGHT_MIN = 0;
//スクリーンの広さ（最小）
const double SCREEN_WIDTH_MIN = 0;
//スクリーンの広さ（最大）
const double SCREEN_WIDTH_MAX = 480;
//ここまでスクリーンの縦横のパラメータ


//生成する弾の数
const int MAX_AMMO = 50;
//生成する味方大砲の数
const int MAX_CANNON = 2;
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


//敵密度低
const int ENEMYDENSITY_LOW = 2;

//敵密度中
const int ENEMYDENSITY_MIDDLE = 5;

//敵密度高
const int ENEMYDENSITY_HIGH = 10;
//敵密度高
//以上、敵の生成密度

const int NUMOF_REPELEDENEMY_LOW = 100;
//撃退度「低」
const int NUMOF_REPELEDENEMY_HIGH = 300;
//撃退度「高」
//敵密度が「高」を維持する最大フレーム数
const double HIGHTENSION_ELAPSEDFRAME_MAX = 100;

//クリアに必要なスコア
const int NECESSARY_SCORE_TO_BE_CLEARED =1000;


const double ENEMY_SPEED = 3;
//敵の移動スピード
//プレイヤーの目の前のY座標の位置
const double PLAYER_FORWARDPOS_Y = 100;



