/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:44:56 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/02 17:51:40 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

int	is_shadowed(t_world w, t_tuple point)
{
	t_tuple		direction;
	double		distance;
	t_ray		shadow_ray;
	t_intersect	*hit;

	direction = tuple_subtract(w.light.position, point);
	distance = vector_magnitude(direction);
	direction = vector_normalize(direction);
	shadow_ray = ray(point, direction);
	hit = checkhit(intersect_world(shadow_ray, w));
	if (hit && hit->t < distance)
		return (1);
	else
		return (0);
}
