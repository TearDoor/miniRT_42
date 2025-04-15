/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:30:58 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/12 16:56:07 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_mat4	rotation_x(double radians)
{
	return (
		(t_mat4){{
			{1, 0, 0, 0},
			{0, cos(radians), -sin(radians), 0},
			{0, sin(radians), cos(radians), 0},
			{0, 0, 0, 1},
		}}
	);
}

t_mat4	rotation_y(double radians)
{
	return (
		(t_mat4){{
			{cos(radians), 0, sin(radians), 0},
			{0, 1, 0, 0},
			{-sin(radians), 0, cos(radians), 0},
			{0, 0, 0, 1},
		}}
	);
}

t_mat4	rotation_z(double radians)
{
	return (
		(t_mat4){{
			{cos(radians), -sin(radians), 0, 0},
			{sin(radians), cos(radians), 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1},
		}}
	);
}

t_mat4	rot_vector_to_vector(t_tuple v1, t_tuple v2)
{
	t_tuple			axis;
	const double	cos_a = vector_dot_product(v1, v2);
	const double	k = 1.0 / (1.0 + cos_a);

	if (equal(fabs(cos_a), 1))
		return (id_matrix());
	axis = vector_cross_product(v1, v2);
	return ((t_mat4){{
			{(axis.x * axis.x * k) + cos_a,
				(axis.y * axis.x * k) - axis.z,
				(axis.z * axis.x * k) + axis.y, 0,
			},
			{(axis.x * axis.y * k) + axis.z,
				(axis.y * axis.y * k) + cos_a,
				(axis.z * axis.y * k) - axis.x, 0,
			},
			{(axis.x * axis.z * k) - axis.y,
				(axis.y * axis.z * k) + axis.x,
				(axis.z * axis.z * k) + cos_a, 0,
			}, {0, 0, 0, 1},
		}});
}
