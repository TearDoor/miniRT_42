/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:11:19 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/05 16:29:44 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

t_tuple	point(double x, double y, double z)
{
	t_tuple	new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = z;
	new_point.w = 1;
	return (new_point);
}

t_tuple	vector(double x, double y, double z)
{
	t_tuple	new_point;

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
	printf("x:%.5f y:%.5f z:%.5f\n", tuple.x, tuple.y, tuple.z);
}

int	tuple_equal(t_tuple t1, t_tuple t2)
{
	if (!equal(t1.x, t2.x))
		return (0);
	if (!equal(t1.y, t2.y))
		return (0);
	if (!equal(t1.z, t2.z))
		return (0);
	if (!equal(t1.w, t2.w))
		return (0);
	return (1);
}
