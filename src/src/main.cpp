#include "DxLib.h"
#include "Include\ObjectAdmin.h"
#include "Include/Maintask.h"
#include <iostream>
#include "Include/Define.h"
using namespace std;


int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	ChangeWindowMode(true);//trueにするとウインドウを表示する
	SetGraphMode(static_cast<int>(SCREEN_HEIGHT_MAX), static_cast<int>(SCREEN_WIDTH_MAX), 16);//(横の長さ、縦の長さ、カラービット）
	DxLib_Init();//DxLibの初期化
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("うじゃうじゃシューティング");//ウインドウタイトル



	unique_ptr<Maintask> maintask;

	try {
		maintask = make_unique<Maintask>();
	}
	catch (bad_alloc)
	{
		"maintaskメモリ領域の確保に失敗しました";
	}
	while (Process(maintask->Getkey())||maintask->GetQuitGame()==true)
	{//メインループ

		maintask->Update();


	}

	DxLib_End();

	return 0;
}

int Process(char key[256])
{
	if (ScreenFlip() != 0)return false;//表画面と裏画面を入れ替える
	if (ProcessMessage() != 0)return false;//メッセージの自動処理
	if (ClearDrawScreen() != 0)return false;//描画している画面を消去する
	if (GetHitKeyStateAll(key) != 0)return false;//キーボードの入力をする
	
	return true;

	//falseならループから抜ける。


}

