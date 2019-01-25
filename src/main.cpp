#include "DxLib.h"
#include "Include\UnitAdmin.h"
using namespace std;
int Process(char key[256])
{
	if (ScreenFlip() != 0)return false;//表画面と裏画面を入れ替える
	if (ProcessMessage() != 0)return false;//メッセージの自動処理
	if (ClearDrawScreen() != 0)return false;//描画している画面を消去する
	if (GetHitKeyStateAll(key) != 0)return false;//キーボードの入力をする

	return true;

	//falseならループから抜ける。


}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);//trueにするとウインドウを表示する
	SetGraphMode(640, 480, 16);//(横の長さ、縦の長さ、カラービット）
	DxLib_Init();//DxLibの初期化
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("うじゃうじゃシューティング");//ウインドウタイトル
	int bg1handle = LoadGraph("Image\\Title.png");
	int bg2handle = LoadGraph("Image\\CLEAR.png");
	int count = 0;
	enum class STATUS {
		TITLE,
		GAME,
		RESULT,
		CLEAR
	}status = STATUS::TITLE;//初期値をタイトルとして宣言する

	char key[256];

	unique_ptr<UnitAdmin> unit_admin = make_unique<UnitAdmin>(key);

	while (Process(key)) {//メインループ
		switch (status)
		{
		case STATUS::TITLE:
			DrawGraph(0, 0, bg1handle, 0);
			if (key[KEY_INPUT_Z] == 1) {
				unit_admin->InitGame();
				status = STATUS::GAME;
			}
			break;
		case STATUS::GAME:
			unit_admin->Judge();
			unit_admin->ItemJudge();
			unit_admin->Update();
			unit_admin->Draw();
			unit_admin->DrawHitPoint();
			if (unit_admin->GetGameoverFlag()) {
				status = STATUS::RESULT;
			}
			if (unit_admin->GetGameClearFlag())
			{
				status = STATUS::CLEAR;
			}
			break;
		case STATUS::RESULT:
			DrawFormatString(50, 50, GetColor(100, 100, 100), "%d", unit_admin->GetScore());
			break;
		case STATUS::CLEAR:
				DrawGraph(0, 0, bg2handle, 0);
				break;
		}
	}

	DxLib_End();

	return 0;
}