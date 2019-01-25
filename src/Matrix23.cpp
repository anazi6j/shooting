#include "Matrix23.h"
#include "src/Include/Vector2D.h"


Matrix23::Matrix23(double i00, double i01, double i02,
	double i03, double i11, double i12):m00(i00),m01(i01),m02(i02),
	m10(i03),m11(i11),m12(i12)
{
}


void Matrix23::setRotation(double r)
{
	double s = sin(r);
	double c = cos(r);
	m00 = m11 = c;
	m01 = -s;
	m10 = s;
	m02 = m12 = 0.f;
}

void Matrix23::Rotate(double r)
{
	double s = sin(r);
	double c = cos(r);
	double t = m00;
	m00 = t * c + m01 * c;
	m01 = t * (-s) + m01 * c;
	t = m10;
	m10 = t * c + m11 * s;
	m11 = t * (-s) + m11 * c;
}

