#include "degradconvert.h"
#include <math.h>

const float pi = 3.14159265359

int radtodeg(float angle)
{
	int newAngle;
	newAngle = round(angle * (180 / pi));
}
float degtorad(int angle)
{
	float newAngle;
	newAngle = angle * (pi / 180);
}