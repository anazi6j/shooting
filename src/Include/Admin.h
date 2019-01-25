#pragma once

#include "CharacterObject.h"
#include "Define.h"
#include <memory>

using namespace std;
class BarrierObject;
class ItemBase;
//���C�����[�v����A�������A�X�V�A�`��֐������s���邽�߂̃N���X

//�G�̐����x�B�X�R�A���L�т�ɉ����đ����Ă���
enum class EnemyNumDensity
{
	Low = 5,
	Middle = 10,
    High = 20,
    
};
enum class Tension
{
	LOW,
	MIDDLE,
	HIGH
};
class UnitAdmin
{
private:
	//characterObject��0�ԁi�v���C���[�̎��j��exist��false�ɂȂ�����true��Ԃ�
	bool gameoverflag;
	bool gameclearflag;
	int score;
	//�e�I�u�W�F�N�g�i�v���C���[�E�G�E�e�E�o���A�E�A�C�e���j�̃O���t�B�b�N�n���h����������ŊǗ�����
	int player_graphic_handle;
	int enemy_graphic_handle;
	int bullet_graphic_handle;
	int barrier_graphic_handle;
	int Cannon_graphic_handle;
	int HPRecover_graphic_handle;
	//�G���ޓx
	int NumofRepeledEnemy;
	//
	int HIGHtension_ElapsedFrame;
	int FrameLeft;
	//�G�̐�
	int EnemyCount;
	//�G�̐��𐧌䂷��
	int CurEnemyLimit;
	ItemBase* item[ITEM_MAXNUM];
public:
	//�R���X�g���N�^
	UnitAdmin() {};

	UnitAdmin(char*);
	
	
	//�ő�256�̂̃I�u�W�F�N�g�i0�ԃv���C���[�A1~255�ԓG�j�̃|�C���^�z��
	
	//CharacterObject�ɂ�0�Ԃɂ̓v���C���[�̗̈�A1~255�Ԃ�G�̗̈�𓮓I�m�ۂ���̂Ń|�C���^�z������B
	//CharacterObject�͒��ۃN���X�Ȃ̂Ŏ��̂����Ȃ��̂ŁA�|�C���^�z��ɂ���
    //���l:http://www.himajin2001.com/fswiki/wiki.cgi?page=%B5%BB%BD%D1%C5%AA%BB%A8%C3%CC%2D%A5%DD%A5%A4%A5%F3%A5%BF%C7%DB%CE%F3%A1%A2vector%A4%CE%CD%EE%A4%C8%A4%B7%B7%EA
	//CharacterObject *Object[OBJECT_MAXNUM];

	shared_ptr<CharacterObject> Object[OBJECT_MAXNUM];

	BarrierObject* barrier;//�X�}�[�g�|�C���^�ɓ���ւ���iunique_ptr)
	//ItemBase��0����2�ԂɖC��A�C�e���̗̈���m�ۂ��A3�Ԃ���5�Ԃɑ̗͉񕜃A�C�e���̗̈���m�ۂ���B
	//
	
	EnemyNumDensity Density;
	
	
	//�v���C���[�̃L�[���͂̊m�F��char�|�C���^���g��
	~UnitAdmin();

	bool GetGameoverFlag() { return gameoverflag; }
	bool GetGameClearFlag() { return gameclearflag; }

	void InitGame();

	void Update();

	//�`��
	void Draw();
	//HP�`��
	void DrawHitPoint();

	int GetScore() { return score; }


	//�e�̓����蔻����s��
	void Judge();

	//�A�C�e���̂����蔻����s��
	void ItemJudge();

	//��ԋ߂��I�u�W�F�N�g��Ԃ�
	Vector2D GetClosetPosition(const GameObject& closet);
	

	//DestroyedEnemyCount�̃Z�b�^�֐�
	void Set_NumofRepeledEnemy (int num)
	{
		NumofRepeledEnemy = num;
	}

	int Get_NumOfRepeledEnemy()
	{
		return NumofRepeledEnemy;
	}

	//HIGHTension_ElapsedTime�̃Q�b�^�E�Z�b�^�֐�

	int Get_HIGHTension_ElapsedTime()
	{
		return HIGHtension_ElapsedFrame;
	}

	void Set_HIGHTension_ElapsedTime(int _Frame)
	{
		HIGHtension_ElapsedFrame = _Frame;
	}

	//EnemyNumDensity�̃Q�b�^�֐��ƃZ�b�^�֐�

	EnemyNumDensity Get_EnemyNumDensity()
	{
		return Density;
	}

	void Set_EnemyNumDensity(EnemyNumDensity _Density)
	{
		Density = _Density;
	}
	
	void SetFrameLeft(int Frame)
	{
		FrameLeft = Frame;
	}
	//�G���x���R���g���[������
	int GetEnemyNumDensity();

	void DecreaseEnemyCount()
	{
		EnemyCount--;
	}
};

