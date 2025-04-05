/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:44:56 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/05 22:22:56 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

int	is_shadowed(t_world w, t_tuple point, t_light *light)
{
	t_tuple		direction;
	double		distance;
	t_ray		shadow_ray;
	t_list		*xs;
	t_intersect	*hit;

	direction = tuple_subtract(light->position, point);
	distance = vector_magnitude(direction);
	direction = vector_normalize(direction);
	shadow_ray = ray(point, direction);
	xs = intersect_world(shadow_ray, w);
	hit = checkhit(xs);
	if (hit && hit->t < distance)
	{
		ft_lstclear(&xs, free);
		return (1);
	}
	else
	{
		ft_lstclear(&xs, free);
		return (0);
	}
}
