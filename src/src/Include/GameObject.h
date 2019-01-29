#pragma once
//�G�ƃv���C���[�A�e�ۂ̊��N���X
#include "Vector2D.h"



using namespace std;
class UnitAdmin;
 class GameObject
{
protected:
	
	bool isActive;//true�Ȃ�`��Afalse�Ȃ�`�悵�Ȃ�
	bool isInSight;//true�Ȃ�U���Afalse�Ȃ�U�����Ȃ�


	//����
	double distance;
	//�p�x
	double Angle;
	

	bool isEnemy;//���@��������false,�G��true
	             //�����Ă���t���O���Ⴄ�I�u�W�F�N�g���m
	             //�ɑ΂��čU�����L���ɂȂ�
	
	UnitAdmin* unit_admin;//�Ȃ����|�C���^���g���Ă�̂��Ƃ����ƁA
	///UnitAdmin�N���X�����炱�̃N���X���p�������N���X�I�u�W�F�N�g���C���X�^���X������ہAUnitAdmin��this�|�C���^���K�v��
	//�Ȃ邩��ł���
    
	//�����蔻��i�~�j
	double hitzone;

	
public:
	int GraphicHandle;//DX���C�u�������摜��ǂݍ��ލۂ̃n���h���ϐ�
	Vector2D position;
	
	GameObject();
	
	virtual void Update() = 0;

	virtual void DrawObject();//�`��


	//�e�Q�[���I�u�W�F�N�g�i�G�A���@�A�e�ہj��Update�Ɏ�������B
	//�����ł͎������Ȃ�
	

	//�ȉ��Q�b�^�E�Z�b�^�֐�
	bool GetisActive()const { return isActive; }
	double GetAngle()const { return Angle; }
	
	bool GetIsEnemy() const{ return isEnemy; }

	double GetHitZone() const{ return hitzone; }

	void SetHitzone(double value) { hitzone = value; }

	bool GetisInSight()const { return isInSight; }

	void SetActive(bool isactive) { isActive = isactive; }

	double GetDistance()const { return distance; }

	


	
};

