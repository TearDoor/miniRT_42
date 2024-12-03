#include "include/tuples.h"

int	main(void)
{
	t_tuple t1, t2, t3;

	t1 = vector(1, -2, 3);
	t2 = vector(5, 6, 7);
	t3 = tuple_scaler_div(t1, 0);

	print_tuple(t3);
	return (0);
}
