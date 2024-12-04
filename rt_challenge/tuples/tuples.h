/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:16:09 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/04 17:00:18 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include <stdio.h>

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
int		tuple_equal(t_tuple t1, t_tuple t2);

t_tuple	tuple_add(t_tuple t1, t_tuple t2);
t_tuple	tuple_subtract(t_tuple t1, t_tuple t2);
t_tuple	tuple_negate(t_tuple tup);
t_tuple	tuple_scalar_mult(t_tuple tup, double scalar);
t_tuple	tuple_scaler_div(t_tuple tup, double scalar);

double	vector_magnitude(t_tuple vec);
t_tuple	vector_normalize(t_tuple vec);
double	vector_dot_product(t_tuple v1, t_tuple v2);
t_tuple	vector_cross_product(t_tuple v1, t_tuple v2);

int		equal(double a, double b);

#endif
