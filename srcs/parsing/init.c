/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 04:15:46 by root              #+#    #+#             */
/*   Updated: 2025/04/24 18:41:13 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void	init_obj(t_parse_obj *obj, t_obj_id id, t_parse *rt)
{
	t_parse_obj	*tmp;

	obj->id = id;
	if (!(rt->obj_list))
		rt->obj_list = obj;
	else
	{
		tmp = rt->obj_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
	}
}

void	init_txr_bump(t_parse_obj *obj, char **info)
{
	if (obj->id == PLANE || obj->id == SPHERE)
	{
		if (ft_arrlen(info) > 4)
		{
			if (ft_strncmp(info[4], "txr:", 4) == 0)
				obj->texture_file = ft_strdup(info[4] + 4);
			else if (ft_strncmp(info[4], "bump:", 5) == 0)
				obj->bump_file = ft_strdup(info[4] + 5);
			if (info[5])
				if (ft_strncmp(info[5], "bump:", 5) == 0)
					obj->bump_file = ft_strdup(info[5] + 5);
		}
	}
	init_txr_bump2(obj, info);
}

void	init_txr_bump2(t_parse_obj *obj, char **info)
{
	if (obj->id == CYLINDER || obj->id == SINGLE_CONE || obj->id == DOUBLE_CONE)
	{
		if (ft_arrlen(info) > 6)
		{
			if (ft_strncmp(info[6], "txr:", 4) == 0)
				obj->texture_file = ft_strdup(info[6] + 4);
			else if (ft_strncmp(info[6], "bump:", 5) == 0)
				obj->bump_file = ft_strdup(info[6] + 5);
			if (info[7])
				if (ft_strncmp(info[7], "bump:", 5) == 0)
					obj->bump_file = ft_strdup(info[7] + 5);
		}
	}
}

void	init_camera(char **coords, char **vector,
			t_parse_camera *camera, t_parse *rt)
{
	int	i;

	i = -1;
	while (++i < NUM_ARG_FIXED)
	{
		camera->coordinate.elems[i] = ft_atod(coords[i], rt);
		camera->vector.elems[i] = ft_atod(vector[i], rt);
	}
}
