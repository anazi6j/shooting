#pragma once
class Input
{
	
	//Input�V�X�e�������
	//��񉟂��ƃ����t���[������true��Ԃ��֐�
	//�����Ă��true��Ԃ��֐������
protected:
	int Frame;
	char* input;
public:
	
	Input();
	~Input();
	//�L�[�{�[�h����
	static bool GetKeyDown(char*);
	static bool GetKeepKeyPushing(char*);

};

