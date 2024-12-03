#include "tuples.h"

int	main(void)
{
	t_tuple t1, t2, t3, t4;

	t1 = vector(1, 2, 3);
	t2 = vector(2, 3, 4);
	t3 = vector_cross_product(t1, t2);
	t4 = vector_cross_product(t2, t1);

	print_tuple(t3);
	print_tuple(t4);
	printf("magnitude: %f\n", vector_magnitude(t3));
	printf("dot product: %f\n", vector_dot_product(t1, t2));
	return (0);
}
