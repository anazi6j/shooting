#pragma once
#include <memory>
#include "Include/ObjectAdmin.h"
#include "Menu.h"
class Maintask
{

	enum class STATUS {
		TITLE,
		CONFIG,
		GAME,
		RESULT,
		CLEAR
	}status = STATUS::TITLE;//初期値をタイトルとして宣言する
public:
	Maintask();
	~Maintask();
	unique_ptr<ObjectAdmin> unit_admin;
	unique_ptr<Menu>menu;
	void Update();
	char* Getkey() { return key; }
	bool GetQuitGame() { return quitgame; }
private:
	char key[256];
	int bg1Handle;
	int bg2Handle;
	int BG_count;
	bool quitgame;
};

