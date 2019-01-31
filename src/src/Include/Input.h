#pragma once
class Input
{
	
	//Inputシステムを作る
	//一回押すとワンフレームだけtrueを返す関数
	//押してる間trueを返す関数を作る
protected:
	
public:
	
	Input();
	~Input();
	//キーボード入力
	static bool GetKeyPressed(char* input,const int key);
	static bool GetKeyUp(const char* input, const int key);
	static bool GetKeyDown(const char* input, const int key);

};

