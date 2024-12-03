#include <stdio.h>
#include "include/tuples.h"
#include "include/utils.h"

t_tuple	point(double x, double y, double z)
{
	t_tuple new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = z;
	new_point.w = 1;
	return (new_point);
}

t_tuple	vector(double x, double y, double z)
{
	t_tuple new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = z;
	new_point.w = 0;
	return (new_point);
}

void	print_tuple(t_tuple tuple)
{
	if (equal(tuple.w, 0))
		printf("Vector: ");
	else
		printf("Point: ");
	printf("x:%.4f y:%.4f z:%.4f\n", tuple.x, tuple.y, tuple.z);
}

bool	tuple_equal(t_tuple t1, t_tuple t2)
{
	if (!equal(t1.x, t2.x))
		return (false);
	if (!equal(t1.y, t2.y))
		return (false);
	if (!equal(t1.z, t2.z))
		return (false);
	if (!equal(t1.w, t2.w))
		return (false);
	return (true);
}

