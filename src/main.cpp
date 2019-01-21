#include "DxLib.h"
#include "Include\UnitAdmin.h"

int Process(char key[256])
{
	if (ScreenFlip() != 0)return false;//�\��ʂƗ���ʂ����ւ���
	if (ProcessMessage() != 0)return false;//���b�Z�[�W�̎�������
	if (ClearDrawScreen() != 0)return false;//�`�悵�Ă����ʂ���������
	if (GetHitKeyStateAll(key) != 0)return false;//�L�[�{�[�h�̓��͂�����

	return true;

	//false�Ȃ烋�[�v���甲����B


}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);//true�ɂ���ƃE�C���h�E��\������
	SetGraphMode(640, 480, 16);//(���̒����A�c�̒����A�J���[�r�b�g�j
	DxLib_Init();//DxLib�̏�����
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("�����Ⴄ����V���[�e�B���O");//�E�C���h�E�^�C�g��
	int bg1handle = LoadGraph("Image\\Title.png");

	int count = 0;
	enum {
		TITLE,
		GAME,
		RESULT
	}status = TITLE;//�����l���^�C�g���Ƃ��Đ錾����

	char key[256];

	UnitAdmin* unit_admin = new UnitAdmin(key);
	while (Process(key)) {//���C�����[�v
		switch (status)
		{
		case TITLE:
			DrawGraph(0, 0, bg1handle, 0);
			if (key[KEY_INPUT_Z] == 1) {
				unit_admin->InitGame();
				status = GAME;
			}
			break;
		case GAME:
			unit_admin->Judge();
			unit_admin->ItemJudge();
			unit_admin->Update();
			unit_admin->Draw();
			unit_admin->DrawHitPoint();
			if (unit_admin->GetGameoverFlag()) {
				status = RESULT;
			}
			break;
		case RESULT:
			DrawFormatString(50, 50, GetColor(100, 100, 100), "%d", unit_admin->GetScore());
			break;

		}
	}

	DxLib_End();

	return 0;
}