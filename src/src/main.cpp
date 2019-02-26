#include "DxLib.h"
#include "Include\ObjectAdmin.h"
#include "Include/Maintask.h"
#include <iostream>
#include "Include/Define.h"
using namespace std;


int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	ChangeWindowMode(true);//true�ɂ���ƃE�C���h�E��\������
	SetGraphMode(static_cast<int>(SCREEN_HEIGHT_MAX), static_cast<int>(SCREEN_WIDTH_MAX), 16);//(���̒����A�c�̒����A�J���[�r�b�g�j
	DxLib_Init();//DxLib�̏�����
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("�����Ⴄ����V���[�e�B���O");//�E�C���h�E�^�C�g��



	unique_ptr<Maintask> maintask;

	try {
		maintask = make_unique<Maintask>();
	}
	catch (bad_alloc)
	{
		"maintask�������̈�̊m�ۂɎ��s���܂���";
	}
	while (Process(maintask->Getkey())||maintask->GetQuitGame()==true)
	{//���C�����[�v

		maintask->Update();


	}

	DxLib_End();

	return 0;
}

int Process(char key[256])
{
	if (ScreenFlip() != 0)return false;//�\��ʂƗ���ʂ����ւ���
	if (ProcessMessage() != 0)return false;//���b�Z�[�W�̎�������
	if (ClearDrawScreen() != 0)return false;//�`�悵�Ă����ʂ���������
	if (GetHitKeyStateAll(key) != 0)return false;//�L�[�{�[�h�̓��͂�����
	
	return true;

	//false�Ȃ烋�[�v���甲����B


}

