#pragma once
class Vector2D
{
public:
	double x, y;
	Vector2D();
	Vector2D(double  x, double y);
	~Vector2D();

	void set(float x, float y);

	//���������߂�
	double GetLength()const;

	//

	//��_�Ԃ̃x�N�g���̋��������߂�

	static double Distance(const Vector2D& from, const Vector2D& to);

	//�x�N�g���̓��ς����߂�
	static inline double Dot(const Vector2D& from,const Vector2D& to);

	//��_�Ԃ̃x�N�g���̊p�x�����߂�

	static double Angle(const Vector2D& from, const Vector2D& to);

	Vector2D forward() { set(0, 1); }
	Vector2D Right() { set(1, 0); }

	 Vector2D operator+(const Vector2D v);
	bool operator==(const Vector2D& v)const;
	bool operator!=(const Vector2D& v)const;
};

