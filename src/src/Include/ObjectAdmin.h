#pragma once

#include "CharacterObject.h"
#include "Define.h"
#include <memory>

using namespace std;
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
class ObjectAdmin
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
	
	//�G���ޓx
	int NumofRepeledEnemy;
	//
	double HIGHtension_ElapsedFrame;
	double FrameLeft;
	//�G�̐�
	int EnemyCount;
	//�G�̐��𐧌䂷��
	int CurEnemyLimit;

	Vector2D Cannon_Aimpos;
	
public:
	//�R���X�g���N�^
	
	void(*enemy_density);//�G���x�̃R���g���[��������֐��̃|�C���^

	
	ObjectAdmin(char*);
	
	
	//�ő�256�̂̃I�u�W�F�N�g�i0�ԃv���C���[�A1~255�ԓG�j�̃|�C���^�z��
	
	//CharacterObject�ɂ�0�Ԃɂ̓v���C���[�̗̈�A1~255�Ԃ�G�̗̈�𓮓I�m�ۂ���̂Ń|�C���^�z������B
	//CharacterObject�͒��ۃN���X�Ȃ̂Ŏ��̂����Ȃ��̂ŁA�|�C���^�z��ɂ���
    //���l:http://www.himajin2001.com/fswiki/wiki.cgi?page=%B5%BB%BD%D1%C5%AA%BB%A8%C3%CC%2D%A5%DD%A5%A4%A5%F3%A5%BF%C7%DB%CE%F3%A1%A2vector%A4%CE%CD%EE%A4%C8%A4%B7%B7%EA
	

	unique_ptr<CharacterObject> Object[OBJECT_MAXNUM];
	
	
	EnemyNumDensity Density;
	
	
	//�v���C���[�̃L�[���͂̊m�F��char�|�C���^���g��
	~ObjectAdmin();

	bool GetGameoverFlag() { return gameoverflag; }
	bool GetGameClearFlag() { return gameclearflag; }
	int Get_Score() { return score; }
	int Get_NumofRepeledEnemy() { return NumofRepeledEnemy; }
	void InitGame();

	void Update();

	//UI�`��
	void DrawUI();
	
	//�e�̓����蔻����s��
	void Check_Collision_BullettoCharacterObject();

	//����
	void InstantiateEnemy();

	//EnemyNumDensity�𐧌�
	void Controll_EnemyNumDensity();

	//��ԋ߂��I�u�W�F�N�g��Ԃ�
	Vector2D GetClosetPosition(const GameObject& closet);
	
	//�C��̃^�[�Q�b�g��Ԃ�
	Vector2D GetCannon_TargetPos();

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

	double Get_HIGHTension_ElapsedFrame()
	{
		return HIGHtension_ElapsedFrame;
	}

	void Set_HIGHTension_ElapsedFrame(double _Frame)
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
	
	void SetFrameLeft(double Frame)
	{
		FrameLeft = Frame;
	}

	void Set_Cannon_TargetPos(const Vector2D& pos);
	
	//�G���x���R���g���[������
	int GetEnemyNumDensity();

	void DecreaseEnemyCount()
	{
		EnemyCount--;
	}
};

