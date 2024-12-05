/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_advanced.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:59:38 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/05 16:34:50 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* the size/length of a vector
 * calculated using pythagoras' theorem
 * c^2 = a^2 + b^2 */
double	vector_magnitude(t_tuple vec)
{
	double	magnitude;

	if (!equal(vec.w, 0))
	{
		printf("Warning: Magnitude operation on non-vector.\n");
		return (0);
	}
	magnitude = pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2) + pow(vec.w, 2);
	magnitude = sqrt(magnitude);
	return (magnitude);
}

/* turns the size of a vector to 1 but keeps its direction
 * done by dividing all elements of a vector by its magnitude*/
t_tuple	vector_normalize(t_tuple vec)
{
	t_tuple	res;
	double	mag;

	mag = vector_magnitude(vec);
	if (equal(mag, 0))
	{
		printf("Warning: Normalizing vector with magnitude of 0\n");
		exit(1);
	}
	res.x = vec.x / mag;
	res.y = vec.y / mag;
	res.z = vec.z / mag;
	res.w = vec.w / mag;
	return (res);
}

double	vector_dot_product(t_tuple v1, t_tuple v2)
{
	return ((v1.x * v2.x)
		+ (v1.y * v2.y)
		+ (v1.z * v2.z)
		+ (v1.w * v2.w));
}

/* returns a vector (v1 x v2) that is both perpendicular to both v1 and v2 
 * Using right hand rule, if the index finger is v1, middle finger is v2,
 * then the thumb is the direction of v1 x v2
 * the operation is anticommutative, meaning v1 x v2 = -(v2 x v1) */
t_tuple	vector_cross_product(t_tuple v1, t_tuple v2)
{
	t_tuple	cross;

	cross.w = 0;
	cross.x = (v1.y * v2.z) - (v1.z * v2.y);
	cross.y = (v1.z * v2.x) - (v1.x * v2.z);
	cross.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (cross);
}
