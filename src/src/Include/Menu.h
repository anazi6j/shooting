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
	//���j���[������\��
	//1�̏ꍇ"�Q�[���X�^�[�g"
	//2�̏ꍇ"�ݒ�"
	//3�̏ꍇ"�Q�[���I��"
	void Draw_MenuChara();
	MENUSTATE Get_Menu_State();

	//menunum���𑝌�������
	void add_menunum();
	void sub_menunum();
};

