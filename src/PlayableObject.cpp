#include "Include\PlayableObject.h"
#include "DxLib.h"
#include "Include\Ammo.h"
#include "Include\Admin.h"
#include "Include\BarrierObject.h"
#include "Include/CannonArtilally.h"
#include <iostream>
#include <cassert>
#include "Include/Input.h"
PlayableObject::PlayableObject(int m_chara_graphic_handle, int m_ammo_graphic_handle,
	int m_barrier_graphic_handle, int m_cannon_graphic_handle, char m_input[256], UnitAdmin* m_Uadmin, Tag m_tag)
	:input(m_input), invisibletime(0), CurOwnCannon(2), keyinputframe(0)
{
	input = m_input;
	GraphicHandle = m_chara_graphic_handle;
	
	//�����蔻��̐ݒ�
	collision.radius = RADIUS;
	tag = m_tag;
	
	health = PLAYABLEOB_HEALTH;
	for (int i = 0; i < MAX_AMMO; i++)
	{
		
		try {
			ammo[i] = make_unique<Ammo>(m_ammo_graphic_handle, m_tag);
		}
		catch (bad_alloc)
		{
			cout << "�e�I�u�W�F�N�g�̗̈�m�ۂɎ��s���܂����B������������Ȃ��\��������܂�";
		}
	}

	for (int j = 0; j < MAX_CANNON; j++)
	{
		
		try {
			cannon[j] = make_unique<CannonArtilally>(m_cannon_graphic_handle, m_ammo_graphic_handle,m_Uadmin, m_tag);
		}
		catch (bad_alloc)
		{
			cout << "�C��I�u�W�F�N�g�̗̈�m�ۂɎ��s���܂����B������������Ȃ��\��������܂�";
		}

		try {
			barrier = make_shared<BarrierObject>(m_barrier_graphic_handle);
		}
		catch (bad_alloc)
		{
			cout << "�o���A�I�u�W�F�N�g�̗̈�m�ۂɎ��s���܂����B������������Ȃ��\��������܂�";
		}
	
		tag = m_tag;
	}
}

	PlayableObject::~PlayableObject()
	{}

//�v���C���[���o��������
void PlayableObject::Instantiate(double m_xpos, double m_ypos, double m_angle)
{
	 position.x= m_xpos;
	position.y = m_ypos;
	Angle = m_angle;
	isActive = true;

}
void PlayableObject::Update()
{
	collision.position = position;
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i]->Update();
	}

	
	for (int j = 0; j < MAX_CANNON; j++)
	{
		cannon[j]->Update();
		cannon[j]->DrawObject();
	}
	
	
	Move();
	Attack();
	InstantiateCannon();
	/*SetBarrier*/
	if (Input::GetKeyPressed(input, KEY_INPUT_B)) {
		barrier->SetActive(true);
		barrier->DrawObject();
		barrier->SetBarrierPos(position.x, position.y);
	}
}

void PlayableObject::Move()
{
	//assert������ix��y�̈ʒu�ɐ������|����j
	//clamp�֐�����萧����������
	if (Input::GetKeyPressed(input,KEY_INPUT_UP))
	{
		if (position.y > 0)
		{
			position.y -= 5;
			//posY -= 5;
		}
	}

	if (Input::GetKeyPressed(input, KEY_INPUT_DOWN))
	{
		if (position.y < SCREEN_WIDTH_MAX)
		{
			position.y += 5;
			
		}
	}

	if (Input::GetKeyPressed(input,KEY_INPUT_LEFT))
	{
		if (position.x > 0) {

			position.x -= 5;
		}
	}

	if (Input::GetKeyPressed(input,KEY_INPUT_RIGHT))
	{
		if (position.x < SCREEN_WIDTH_MAX)
		{
			position.x += 5;

		}
	}
}

void PlayableObject::Attack()
{
	
	if(Input::GetKeyPressed(input,KEY_INPUT_Z))
	{
		
		//rapid�̒l��RAPID_SPEED�ȏ�ɂȂ����甭��
		 
			rapid++;
			rapid %= RAPID_RATE;
			if (rapid == 1) {
				for (int i = 0; i < MAX_AMMO; i++)//z�L�[�������ƁA�܂����˂��Ă��Ȃ��e��T���āAshot�֐��Ɍ��݂̍��W��^����
				{
					if (!ammo[i]->GetisActive()) {//���˂��Ă��Ȃ��e����������(i�Ԗڂ̒e�́u�摜��\�����Ă���v��false��������
						ammo[i]->Shot(position.x, position.y, Angle);//�e�𔭎�
						break;
					}
				}
			}
		
	}
}

void PlayableObject::InstantiateCannon()
{
	if (Input::GetKeyDown(input, KEY_INPUT_SPACE))
	{
		if (CurOwnCannon >= 0) {
			for (int i = 0; i < MAX_CANNON; i++)
			{
				if(!cannon[i]->GetisActive())
				cannon[i]->Instantiate(Angle, position.x, position.y -PLAYER_FORWARDPOS_Y);
				
			}
		}
	}
}



//barrier�Acannon����drawobject�����ڏ�����ĂȂ��ƕ`�悳��Ȃ�