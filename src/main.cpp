#include "DxLib.h"
#include "Include\Admin.h"
#include "Include/Maintask.h"
#include <iostream>
#include "Include/Define.h"
using namespace std;


int Process(char key[256])
{
	if (ScreenFlip() != 0)return false;//�\��ʂƗ���ʂ����ւ���
	if (ProcessMessage() != 0)return false;//���b�Z�[�W�̎�������
	if (ClearDrawScreen() != 0)return false;//�`�悵�Ă����ʂ���������
	if (GetHitKeyStateAll(key) != 0)return false;//�L�[�{�[�h�̓��͂�����

	return true;

	//false�Ȃ烋�[�v���甲����B


}

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	ChangeWindowMode(true);//true�ɂ���ƃE�C���h�E��\������
	SetGraphMode(SCREEN_HEIGHT_MAX, SCREEN_WIDTH_MAX, 16);//(���̒����A�c�̒����A�J���[�r�b�g�j
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
		"maintask�̃������̈�̊m�ۂɎ��s���܂���";
	}
	while (Process(maintask->Getkey())) {//���C�����[�v

		maintask->Update();
			
										 /*
		switch (status)
		{
		case STATUS::TITLE:
			DrawGraph(0, 0, bg1handle, 0);
			if (maintask->Getkey()[KEY_INPUT_Z] == 1) {
				unit_admin->InitGame();
				status = STATUS::GAME;
			}
			break;
		case STATUS::CONFIG:
			//�X�V����
			//
		case STATUS::GAME:
			/*MainTask�N���X�����

			unit_admin->Check_Collision_BullettoCharacterObject();
			
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
			DrawFormatString(50, 50, GetColor(100, 100, 100), "%d", unit_admin->Get_Score());
			break;
		case STATUS::CLEAR:
				DrawGraph(0, 0, bg2handle, 0);
				break;
		}
	*/
	}

	DxLib_End();

	return 0;
}