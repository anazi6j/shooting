#pragma once
//�G�ƃv���C���[�A�e�ۂ̊��N���X
#include "Vector2D.h"
#include "CircleCollision.h"
#include <memory>


using namespace std;
class UnitAdmin;

enum class Tag {
	Player,
	PlayerArtilally,
	Enemy,
};

 class GameObject
{
	

protected:
	Tag tag;
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
	CircleCollision collision;
	
public:
	int GraphicHandle;//DX���C�u�������摜��ǂݍ��ލۂ̃n���h���ϐ�
	Vector2D position;
	
	GameObject();
	virtual ~GameObject() {};
	//�h�����̃N���X�̃|�C���^��UnitAdmin�I�u�W�F�N�g�������ăX�}�[�g�|�C���^�ł���A
	//�܂�UnitAdmin�I�u�W�F�N�g�����ꂼ��̃N���X�œ��I�m�ۂ��Ă���̂ł͂Ȃ��A
	//UnitAdmin�N���X����this�|�C���^��n���Ă邽�߁A�v��Ȃ��Ǝv�����O�̂���
	virtual void Update() = 0;

	virtual void DrawObject();//�`��


	//�e�Q�[���I�u�W�F�N�g�i�G�A���@�A�e�ہj��Update�Ɏ�������B
	//�����ł͎������Ȃ�
	

	//�ȉ��Q�b�^�E�Z�b�^�֐�
	bool GetisActive()const { return isActive; }
	double GetAngle()const { return Angle; }
	
	bool GetIsEnemy() const{ return isEnemy; }

	CircleCollision GetCircleCollision() const{ return collision; }

	void SetCollsion_radius(double value) { collision.radius = value; }

	bool GetisInSight()const { return isInSight; }

	void SetActive(bool isactive) { isActive = isactive; }

	double GetDistance()const { return distance; }

	Tag GetTag()const { return tag; }


	
};

