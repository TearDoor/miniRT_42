#include <math.h>
#include "include/utils.h"

int	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}
