#ifndef TUPLES_H
# define TUPLES_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);
void	print_tuple(t_tuple tuple);
bool	tuple_equal(t_tuple t1, t_tuple t2);

t_tuple	tuple_add(t_tuple t1, t_tuple t2);
t_tuple	tuple_subtract(t_tuple t1, t_tuple t2);
t_tuple	tuple_negate(t_tuple tup);
t_tuple	tuple_scalar_mult(t_tuple tup, double scalar);
t_tuple	tuple_scaler_div(t_tuple tup, double scalar);

#endif
