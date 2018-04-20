#pragma once
#include "degradconvert.h"
#include <math.h>

const double pi = 3.14159265359;

int radtodeg(double angle)
{
	int newAngle;
	newAngle = round(angle * (180 / pi));
	return newAngle;
}
double degtorad(int angle)
{
	double newAngle;
	newAngle = angle * (pi / 180);
	return newAngle;
}