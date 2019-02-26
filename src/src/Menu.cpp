#include "Include/Menu.h"
#include "Include/Input.h"
#include "DxLib.h"
#include "Include/Define.h"
#include "Include/MathUtilityF.h"
#include "Include/Maintask.h"
Menu::Menu():menunum(0),black(GetColor(0,0,0))
{
	main_task = make_unique<Maintask>();
}


Menu::~Menu()
{
}

void  Menu::Update()
{
	menunum = MathUtilityF::clamp<int>(menunum, 0, 2);
	state = Get_Menu_State();
	Draw_MenuChara();
	
	if (Input::GetKeyDown(main_task->Getkey(), KEY_INPUT_DOWN))
	{
		add_menunum();
	}
	else if(Input::GetKeyDown(main_task->Getkey(),KEY_INPUT_UP))
	
	{
		sub_menunum();
	}
	

}

MENUSTATE Menu::Get_Menu_State()
{
	switch (menunum)
	{
	case 0:
		return MENUSTATE::GAMESTART;
	case 1:
		return MENUSTATE::CONFIG;
	case 2:
		return MENUSTATE::QUITGAME;
	}
}

void Menu::Draw_MenuChara()
{
	switch (state)
	{
	case MENUSTATE::GAMESTART:
		DrawString(SCREEN_HEIGHT_MAX/2,SCREEN_WIDTH_MAX/2, "GAME START", black);
		break;
	case MENUSTATE::CONFIG:
		DrawString(SCREEN_HEIGHT_MAX / 2, (SCREEN_WIDTH_MAX / 2)+20, "CONFIG", black);
		break;
	case MENUSTATE::QUITGAME:
		DrawString(SCREEN_HEIGHT_MAX / 2 , (SCREEN_WIDTH_MAX / 2) + 40, "CONFIG", black);
		break;
	default:
		break;
	}

}

void Menu::add_menunum()
{
	menunum++;
}

void Menu::sub_menunum()
{
	menunum--;
}