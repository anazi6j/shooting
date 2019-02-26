#pragma once
#include <memory>

class Maintask;
enum class MENUSTATE
{
	GAMESTART,
	CONFIG,
	QUITGAME
};
class Menu
{
	

private:
	int menunum;
	std::unique_ptr<Maintask> main_task;
	MENUSTATE state;
	unsigned int black;
public:
	Menu();
	~Menu();

	void Update();
	//メニュー文字を表示
	//1の場合"ゲームスタート"
	//2の場合"設定"
	//3の場合"ゲーム終了"
	void Draw_MenuChara();
	MENUSTATE Get_Menu_State();

	//menunumをを増減させる
	void add_menunum();
	void sub_menunum();
};

