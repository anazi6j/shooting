#pragma once
class Input
{
	
	//Input�V�X�e�������
	//��񉟂��ƃ����t���[������true��Ԃ��֐�
	//�����Ă��true��Ԃ��֐������
protected:
	
public:
	
	Input();
	~Input();
	//�L�[�{�[�h����
	static bool GetKeyPressed(char* input,const int key);
	static bool GetKeyUp(const char* input, const int key);
	static bool GetKeyDown(const char* input, const int key);

};

