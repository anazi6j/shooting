#include "Include\PlayableObject.h"
#include "DxLib.h"
#include "Include\Ammo.h"
#include "Include\Admin.h"
#include "Include\BarrierObject.h"

PlayableObject::PlayableObject(int m_chara_graphic_handle, int m_ammo_graphic_handle, 
	int m_barrier_graphic_handle,char m_input[256], UnitAdmin* m_Uadmin,Tag m_tag)
{
	input = m_input;
	GraphicHandle = m_chara_graphic_handle;
	//�����蔻��̐ݒ�
	hitzone = HITDETECTIONZONE;
	//�u�G���ǂ����v��false�ɂ���
	isEnemy = false;

	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i] = make_unique<Ammo>(m_ammo_graphic_handle,!isEnemy);
	}
	barrier = new BarrierObject(m_barrier_graphic_handle);
	health = 10000;
	m_tag = tag;
}


PlayableObject::~PlayableObject()
{
	
	
	delete barrier;
}

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
	
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i]->Update();
	}
	

	if (input[KEY_INPUT_UP] == 1)
	{
		if (position.y > 0)
		{
			position.y -= 5;
			//posY -= 5;
		}
	}

	if (input[KEY_INPUT_DOWN] == 1)
	{
		if (position.y < SCREEN_WIDTH_MAX)
		{
			position.y += 5;
			//posY += 5;
		}
	}

	if (input[KEY_INPUT_LEFT] == 1) {
		if (position.x > 0) {
		
			position.x -= 5;
		}
	}

	if (input[KEY_INPUT_RIGHT] == 1)
	{
		if (position.x < SCREEN_WIDTH_MAX)
		{
			position.x += 5;
			
		}
	}

	if (input[KEY_INPUT_Z])
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
	if (input[KEY_INPUT_B]) {
		barrier->SetActive(true);
		barrier->DrawObject();
		barrier->SetBarrierPos(position.x, position.y);
		Barrierisenabled = true;
	}

}