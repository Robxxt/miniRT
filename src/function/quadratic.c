#include "../../includes/miniRT.h"

float	delta(float a, float b, float c)
{
	return (b * b - 4 * a * c);
}

float	root_minus(float a, float b, float c)
{
	float re;

	re = -b - sqrtf(delta(a,b,c));
	re = re * 0.5f / a;
	return (re);
}

float	root_plus(float a, float b, float c)
{
	float re;

	re = -b + sqrtf(delta(a,b,c));
	re = re * 0.5f / a;
	return (re);
}
