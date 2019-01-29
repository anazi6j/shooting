#pragma once
class Input
{
	
	//Inputシステムを作る
	//一回押すとワンフレームだけtrueを返す関数
	//押してる間trueを返す関数を作る
protected:
	int Frame;
	char* input;
public:
	
	Input();
	~Input();
	//キーボード入力
	static bool GetKeyDown(char*);
	static bool GetKeepKeyPushing(char*);

};

