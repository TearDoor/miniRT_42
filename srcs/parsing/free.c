/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-11 14:52:59 by root              #+#    #+#             */
/*   Updated: 2025/04/11 14:47:32 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	typecast_shape(t_parse_obj *tmp)
{
	if (tmp->id == PLANE)
	{
		free(tmp->shape.plane.coordinate);
		free(tmp->shape.plane.vector);
	}
	else if (tmp->id == CYLINDER)
	{
		free(tmp->shape.cylinder.coordinate);
		free(tmp->shape.cylinder.vector);
		free(tmp->shape.cylinder.color);
	}
	else if (tmp->id == SPHERE)
	{
		free(tmp->shape.sphere.coordinate);
	}
}

void	free_shape(t_parse *rt)
{
	t_parse_obj		*obj;
	t_parse_obj		*tmp;
	t_parse_light	*light;
	t_parse_light	*tmp_light;

	light = rt->light_list;
	while (light)
	{
		tmp_light = light;
		printf("free tmp_light = %d\n", tmp_light->id); //debug
		light = light->next;
		free(tmp_light);
	}
	obj = rt->obj_list;
	while (obj)
	{
		tmp = obj;
		obj = obj->next;
		typecast_shape(tmp);
		free(tmp);
	}
	free(rt);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
