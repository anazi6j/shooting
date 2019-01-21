#pragma once
class Vector2D
{
public:
	double x, y;
	Vector2D();
	Vector2D(double  x, double y);
	~Vector2D();

	void set(float x, float y);

	//長さを求める
	double GetLength()const;

	//

	//二点間のベクトルの距離を求める

	static double Distance(const Vector2D& from, const Vector2D& to);

	//ベクトルの内積を求める
	static inline double Dot(const Vector2D& from,const Vector2D& to);

	//二点間のベクトルの角度を求める

	static double Angle(const Vector2D& from, const Vector2D& to);

	Vector2D forward() { set(0, 1); }
	Vector2D Right() { set(1, 0); }

	 Vector2D operator+(const Vector2D v);
	bool operator==(const Vector2D& v)const;
	bool operator!=(const Vector2D& v)const;
};

