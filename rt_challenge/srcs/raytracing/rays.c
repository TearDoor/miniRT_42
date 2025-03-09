/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:47:40 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/08 16:23:53 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "pattern.h"
#include <unistd.h>

t_ray	ray(t_tuple point, t_tuple vector)
{
	return ((t_ray){
		.origin = point,
		.direction = vector
	});
}

/* position = origin + t * direction */
t_tuple	position(t_ray ray, double distance)
{
	return (tuple_add(ray.origin, tuple_scalar_mult(ray.direction, distance)));
}

void	set_transform(t_obj *o, t_mat4 m)
{
	if (o == NULL)
		return ;
	o->transform = matrix_mult(m, o->transform);
	o->inverse_transform = matrix_invert(o->transform);
}

t_ray	transform_ray(t_ray ray, t_mat4 transform)
{
	return ((t_ray){
		.origin = matrix_tuple_mult(transform, ray.origin),
		.direction = matrix_tuple_mult(transform, ray.direction),
	});
}
