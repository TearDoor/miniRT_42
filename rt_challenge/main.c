#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define EPSILON 0.00001

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	else
		return (false);
}

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

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

t_tuple	tuple_add(t_tuple t1, t_tuple t2)
{
	t_tuple	res;

	res.x = t1.x + t2.x;
	res.y = t1.y + t2.y;
	res.z = t1.z + t2.z;
	res.w = t1.w + t2.w;
	if (res.w > 1)
		printf("Warning: adding two points.\n");
	return (res);
}

t_tuple	tuple_subtract(t_tuple t1, t_tuple t2)
{
	t_tuple	res;

	res.x = t1.x - t2.x;
	res.y = t1.y - t2.y;
	res.z = t1.z - t2.z;
	res.w = t1.w - t2.w;
	if (res.w < 0)
		printf("Warning: subtracting point from vector\n");
	return (res);
}

t_tuple	tuple_negate(t_tuple tup)
{
	t_tuple	res;

	res.x = tup.x * -1;
	res.y = tup.y * -1;
	res.z = tup.z * -1;
	res.w = tup.w * -1;
	return (res);
}

int	main(void)
{
	t_tuple t1, t2, t3;

	t1 = vector(3, 2, 1);
	t2 = vector(5, 6, 7);
	t3 = tuple_subtract(t1, t2);
	t3 = tuple_negate(t3);

	print_tuple(t3);
	return (0);
}
