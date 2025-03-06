/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:23:10 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/08 17:19:13 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_world	new_world(void)
{
	t_world	new;

	new.objs = NULL;
	new.obj_arr = NULL;
	new.light = point_light(color(1, 1, 1), point(-10, 10, -10));
	return (new);
}

t_world	default_world(void)
{
	t_world		new;
	t_obj		*s1;
	t_obj		*s2;

	new.objs = NULL;
	new.light = point_light(color(1, 1, 1), point(-10, 10, -10));
	s1 = sphere();
	s1->material.color = color(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	ft_lstadd_back(&new.objs, ft_lstnew(s1));
	s2 = sphere();
	set_transform(s2, scaling_mat(0.5, 0.5, 0.5));
	ft_lstadd_back(&new.objs, ft_lstnew(s2));
	return (new);
}

#include <stdio.h>
t_obj*	list_to_array_obj(t_list *list)
{
	t_obj* obj_arr;
	size_t list_size;

	printf("size = %d\n", ft_lstsize(list));
	list_size = ft_lstsize(list);
	obj_arr = malloc(sizeof(t_obj) * (list_size + 1));
	return (obj_arr);
}

/* checks if the ray intersects with all the objects in the world */
t_list	*intersect_world(t_ray ray, t_world world)
{
	t_list	*xs;
	t_list	*curr;
	t_obj	*obj;

	xs = NULL;
	curr = world.objs;
	while (curr)
	{
		obj = curr->content;
		check_intersect(*obj, ray, &xs);
		curr = curr->next;
	}
	return (xs);
}
