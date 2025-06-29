/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:47:40 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/24 21:13:30 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

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

t_ray	transform_ray(t_ray ray, t_mat4 transform)
{
	return ((t_ray){
		.origin = matrix_tuple_mult(transform, ray.origin),
		.direction = matrix_tuple_mult(transform, ray.direction),
	});
}
