/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_acl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-11 14:52:59 by root              #+#    #+#             */
/*   Updated: 2025-03-11 14:52:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	typecast_shape(t_obj *tmp)
{
	if (tmp->id == PLANE)
	{
		free(tmp->shape.plane.coordinate);
		free(tmp->shape.plane.color);
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
		free(tmp->shape.sphere.color);
	}	
}

void	free_shape(t_minirt *rt)
{
	t_obj	*obj;
	t_obj	*tmp;

	free(rt->ambient.color);
	free(rt->camera.coordinate);
	free(rt->camera.vector);
	free(rt->light.color);
	free(rt->light.coordinate);
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
