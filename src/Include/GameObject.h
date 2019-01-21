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
	int GraphicHandle;//DX���C�u�������摜��ǂݍ��ލۂ̃n���h���ϐ�
	UnitAdmin* unit_admin;
    
	//�����蔻��i�~�j
	double hitzone;
public:
	Vector2D position;
	GameObject();//�C���X�^���X���������Ɏ����ŌĂ΂��
	
	virtual void Update() = 0;
	//�e�Q�[���I�u�W�F�N�g�i�G�A���@�A�e�ہj��Update�Ɏ�������B
	//�����ł͎������Ȃ�
	/*�Q�b�^�֐�*/
	bool GetisActive()const { return isActive; }
	
	double GetAngle()const { return Angle; }
	
	bool GetIsEnemy() const{ return isEnemy; }
	double GetHitZone() { return hitzone; }
	virtual void DrawObject();//�`��
	double GetPosX()const { return position.x; }
	double GetPosY()const { return position.y; }
	void SetActive(bool isactive) { isActive = isactive; }

	inline double GetLength();//����

	
};

