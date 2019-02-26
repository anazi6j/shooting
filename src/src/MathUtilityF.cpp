#include "Include/MathUtilityF.h"



MathUtilityF::MathUtilityF()
{
}


MathUtilityF::~MathUtilityF()
{
}

template <typename T>
T MathUtilityF::clamp(T target, T min, T max)
{
	T targetnumber;
	if (target <= min)
	{
		targetnumber = min;
	}
	else if (target >= max)
	{
		targetnumber = max;
	}

	return targetnumber;
}
