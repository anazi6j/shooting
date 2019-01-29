#pragma once

class Vector2D;
#include <math.h>
class Matrix23
{
public:
	//i‚Íinput‚Ìi
	Matrix23(double i00,double i01,double i02,
		double i10,double i11,double i12);
	
	void setRotation(double r);
	 void Rotate(double r);
private:
	double m00, m01, m02;
	double m10, m11, m12;
};

