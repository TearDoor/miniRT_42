/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:44:56 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/18 17:40:51 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

//like checkhit from intersect.c but ignores objects that don't cast shadow
static t_intersect	*checkhit_shadow(t_list *intersects)
{
	t_list		*curr;
	t_intersect	*curr_xs;

	curr = intersects;
	while (curr)
	{
		curr_xs = curr->content;
		if (curr_xs->t >= 0 && curr_xs->obj->material.cast_shadow == 1)
			return (curr->content);
		curr = curr->next;
	}
	return (NULL);
}

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
	hit = checkhit_shadow(xs);
	if (hit && hit->t < distance - EPSILON)
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
