/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:23:10 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/19 20:38:20 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_world	new_world(void)
{
	t_world	new;

	new.objs = NULL;
	new.obj_arr = NULL;
	new.obj_count = 0;
	new.light = point_light(color(1, 1, 1), point(-10, 10, -10));
	return (new);
}

t_world	default_world(void)
{
	t_world		new;
	t_obj		*s1;

	new = new_world();
	s1 = sphere();
	s1->material.color = color(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	add_obj_to_world(&new, s1);
	return (new);
}

void	add_obj_to_world(t_world *w, t_obj *obj)
{
	ft_lstadd_back(&w->objs, ft_lstnew(obj));
	w->obj_count++;
}

t_obj	*list_to_array_obj(t_list *list)
{
	t_obj	*arr;
	t_list	*curr;
	int		i;

	curr = list;
	i = 0;
	arr = malloc(sizeof(t_obj) * ft_lstsize(list));
	while (curr)
	{
		arr[i] = *(t_obj *)(curr->content);
		i++;
		curr = curr->next;
	}
	return (arr);
}

void	free_world(t_world *w)
{
	ft_lstclear(&w->objs, free);
}
