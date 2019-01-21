#include "Include\Vector2D.h"
#include <math.h>
#include "Include\Define.h"

Vector2D::Vector2D()
{
}

Vector2D::Vector2D(double x, double y) :x(x), y(y)
{

}


Vector2D::~Vector2D()
{
}

void Vector2D::set(float _x, float _y)
{
	x = _x;
	y = _y;
}

double Vector2D::Distance(const Vector2D& from, const Vector2D& to)
{
	double Disx = (from.x > to.x) ? (from.x - to.x)*(from.x - to.x) : (to.x-from.x)* (to.x - from.x);
	double Disy = (from.y > to.y) ? (from.y - to.y)*(from.y - to.y) : (to.y - from.y)*(to.y - from.y);

	return sqrt(Disx*Disy);

}
inline double Vector2D::Dot(const Vector2D& from ,const Vector2D& to)
{
	return from.x*to.x + from.y*to.y;
}

double Vector2D::Angle(const Vector2D& from, const Vector2D& to)
{
	double dot = Vector2D::Dot(from, to);

	double Amag = sqrt(from.GetLength());
	double Bmag = sqrt(to.GetLength());
	double cos = dot / (Amag*Bmag);
	double radian = acos(cos);
	double degree = radian * RAD_TO_DEG;

	return degree;
	
}

double Vector2D::GetLength()const
{
	return x * x + y * y;
}

Vector2D Vector2D::operator+(const Vector2D v)
{
	return Vector2D(x + v.x, y + v.y);
}

bool Vector2D::operator==(const Vector2D& v)const
{
	return x == v.x&&y == v.y;
}

bool Vector2D::operator!=(const Vector2D& v)const
{
	return x != v.x || y != v.y;
}
