#include "Include/Input.h"
#include "DxLib.h"
#include <cassert>
#include <vector>

Input::Input()
{
}


Input::~Input()
{
}

bool Input::GetKeyPressed(char* input,const int key)
{
	
	return input[key] == 1;
}

bool Input::GetKeyUp(const char* input, const int key)
{
	return input[key] == 0;
}

bool Input::GetKeyDown(const char* input, const int key)
{
	assert(0 <= key && key < 256);
	static std::vector<int> tempframe(256);

	if (input[key] == 1)
	{
		tempframe[key]++;
	}
	else 
	{
		tempframe[key] = 0;
	}

	return tempframe[key] == 1;
}
