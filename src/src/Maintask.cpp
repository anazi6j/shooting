#include "Include/Maintask.h"
#include "Include/Menu.h"
#include "DxLib.h"
#include "Include/Input.h"
using namespace std;

Maintask::Maintask()
{
	unit_admin = make_unique<ObjectAdmin>(key);
	menu = make_unique<Menu>(key);
	bg1Handle = LoadGraph("Image\\Title.png");
	bg2Handle = LoadGraph("Image\\CLEAR.png");
	int count = 0;
}


Maintask::~Maintask()
{
}

void Maintask::Update()
{
	switch (status)
	{
	case STATUS::TITLE:
		DrawGraph(0, 0, bg1Handle, 0);
		
		if(Input::GetKeyDown(Getkey(),KEY_INPUT_Z)){
			unit_admin->InitGame();
			status = STATUS::GAME;
		}
		break;
	case STATUS::CONFIG:
		//XV‚·‚é
		//
	case STATUS::GAME:
		unit_admin->Check_Collision_BullettoCharacterObject();

		unit_admin->Update();
		//unit_admin->Draw();
		
		if (unit_admin->GetGameoverFlag()) {
			status = STATUS::RESULT;
		}
		if (unit_admin->GetGameClearFlag())
		{
			status = STATUS::CLEAR;
		}
		break;
	case STATUS::RESULT:
		DrawFormatString(50, 50, GetColor(100, 100, 100), "%d", unit_admin->Get_Score());
		break;
	case STATUS::CLEAR:
			DrawGraph(0, 0, bg2Handle, 0);
			break;
	}
}