#pragma once
class MathUtilityF
{
public:
	MathUtilityF();
	~MathUtilityF();
	template<typename T>
	static T clamp(T target, T min, T max);
	//ベクトルの最大値を返す
	//数値の動きを制限する
	
};

