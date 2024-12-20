/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:47:40 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/20 17:53:14 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_ray	ray(t_tuple point, t_tuple vector)
{
	return ((t_ray){
		.origin = point,
		.direction = vector
	});
}

t_tuple	position(t_ray ray, double distance)
{
	return (tuple_add(ray.origin, tuple_scalar_mult(ray.direction, distance)));
}

t_sphere	sphere(int id)
{
	return ((t_sphere){
		id,
		(t_tuple){{0, 0, 0, 1}},
		1,
		id_matrix(),
		material(),
	});
}

void	set_transform(t_sphere *s, t_mat4 m)
{
	s->transform = matrix_mult(m, s->transform);
}

t_ray	transform_ray(t_ray ray, t_mat4 transform)
{
	return ((t_ray){
		matrix_tuple_mult(transform, ray.origin),
		matrix_tuple_mult(transform, ray.direction),
	});
}
