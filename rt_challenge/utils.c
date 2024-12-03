#include <math.h>
#include <stdbool.h>
#include "include/utils.h"

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	else
		return (false);
}
