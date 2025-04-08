/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_arith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:11:12 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/05 16:34:23 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

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

t_tuple	tuple_scalar_mult(t_tuple tup, double scalar)
{
	t_tuple	res;

	res.x = tup.x * scalar;
	res.y = tup.y * scalar;
	res.z = tup.z * scalar;
	res.w = tup.w * scalar;
	return (res);
}

t_tuple	tuple_scaler_div(t_tuple tup, double scalar)
{
	t_tuple	res;

	if (scalar == 0)
	{
		printf("Error: dividing by zero.\n");
		exit(1);
	}
	res.x = tup.x / scalar;
	res.y = tup.y / scalar;
	res.z = tup.z / scalar;
	res.w = tup.w / scalar;
	return (res);
}
