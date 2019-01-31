#pragma once
#include <memory>
#include "Include/Admin.h"
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
	unique_ptr<UnitAdmin> unit_admin;

	void Update();
	char* Getkey() { return key; }
	
private:
	char key[256];
	int bg1Handle;
	int bg2Handle;
	int BG_count;
};

