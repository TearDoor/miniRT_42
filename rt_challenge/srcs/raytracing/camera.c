/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:41:12 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/27 21:54:39 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "matrix.h"
#include "raytracing.h"
#include <mlx.h>
#include <math.h>

static t_mat4	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	forward;
	t_tuple	left;
	t_tuple	true_up;
	t_mat4	orientation;

	forward = vector_normalize(tuple_subtract(to, from));
	if (fabs(vector_dot_product(forward, up)) >= 0.99)
		up = vector(1, 0, 0);
	left = vector_cross_product(forward, vector_normalize(up));
	true_up = vector_cross_product(left, forward);
	orientation = (t_mat4){{
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1},
	}};
	return (matrix_mult(orientation, translate_mat(-from.x, -from.y, -from.z)));
}

void	init_view_matrix(t_camera *cam, t_tuple from, t_tuple to, t_tuple up)
{
	cam->transform = view_transform(from, to, up);
	cam->initial_transform = cam->transform;
}

t_camera	new_camera(int hsize, int vsize, double fov)
{
	double	half_view;
	double	aspect;
	double	half_width;
	double	half_height;

	half_view = tan(fov / 2);
	aspect = (double)hsize / (double)vsize;
	if (aspect >= 1)
	{
		half_width = half_view;
		half_height = half_view / aspect;
	}
	else
	{
		half_width = half_view * aspect;
		half_height = half_view;
	}
	return ((t_camera){
		hsize, vsize, fov, id_matrix(), id_matrix(), id_matrix(),
		half_width, half_height,
		(half_width * 2) / hsize,
	});
}
