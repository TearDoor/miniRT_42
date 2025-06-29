/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:04:22 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/02 15:53:11 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

t_intersect	*intersection(double t, t_obj *obj)
{
	t_intersect	*inter;

	inter = malloc(sizeof(t_intersect));
	inter->t = t;
	inter->obj = obj;
	return (inter);
}

/* transforms the ray using the inverse of the object's
 * transformation matrix
 * then checks if the transformed ray intersects the object
 * by using the object's local_intersect function */
void	check_intersect(t_obj *obj, t_ray ray, t_list **xs)
{
	t_ray	local_ray;

	local_ray = transform_ray(ray, obj->inverse_transform);
	obj->local_intersect(obj, local_ray, xs);
}

/* checks if the ray intersects with all the objects in the world */
t_list	*intersect_world(t_ray ray, t_world world)
{
	t_list	*xs;
	t_list	*obj_ptr;

	xs = NULL;
	obj_ptr = world.objs;
	while (obj_ptr)
	{
		check_intersect((t_obj *)obj_ptr->content, ray, &xs);
		obj_ptr = obj_ptr->next;
	}
	return (xs);
}

/* returns the first non-negative intersection if any */
t_intersect	*checkhit(t_list *intersects)
{
	t_list		*curr;
	t_intersect	*curr_xs;

	curr = intersects;
	while (curr)
	{
		curr_xs = curr->content;
		if (curr_xs->t >= 0)
			return (curr->content);
		curr = curr->next;
	}
	return (NULL);
}

/*
void	print_xs(t_list *xs)
{
	t_intersect	*x;

	while (xs)
	{
		x = xs->content;
		printf("%f\n", x->t);
		xs = xs->next;
	}
}
*/
