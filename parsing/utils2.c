/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 04:15:46 by root              #+#    #+#             */
/*   Updated: 2025/03/31 11:46:19 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_obj(t_obj *obj, t_obj_id id, t_minirt *rt)
{
	t_obj	*tmp;

	obj->id = id;
	// printf("obj_id = %d\n", obj->id);
	if (!(rt->obj_list))
		rt->obj_list = obj;
	else
	{
		// printf("Im here to add to the linked list\n");
		tmp = rt->obj_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
	}
}

void	init_txr_bump(t_obj *obj, char **info)
{
	if (obj->id == PLANE || obj->id == SPHERE)
	{
		if (ft_arrlen(info) > 4)
		{
			if (ft_strncmp(info[4], "txr", 3) == 0)
				obj->texture_file = info[4] + 4;
			else if (ft_strncmp(info[4], "bump", 4) == 0)
				obj->bump_file = info[4] + 5;
			if (ft_strncmp(info[5], "bump", 4) == 0)
				obj->bump_file = info[5] + 5;
		}
	}
	else if (obj->id == CYLINDER)
	{
		if (ft_arrlen(info) > 6)
		{
			if (ft_strncmp(info[6], "txr", 3) == 0)
				obj->texture_file = info[6] + 4;
			else if (ft_strncmp(info[6], "bump", 4) == 0)
				obj->bump_file = info[6] + 5;
			if (ft_strncmp(info[7], "bump", 4) == 0)
				obj->bump_file = info[7] + 5;
			// printf("info[5] = %s\n", obj->bump_file); //debug
		}
	}
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
