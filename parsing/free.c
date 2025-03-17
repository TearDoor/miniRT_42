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

void	free_acl_plane(t_minirt *rt)
{
	if (rt->ambient)
	{
		free(rt->ambient->color);
		free(rt->ambient);
	}
	if (rt->camera)
	{
		free(rt->camera->coordinate);
		free(rt->camera->vector);
		free(rt->camera);
	}
	if (rt->light)
	{
		free(rt->light->coordinate);
		free(rt->light->color);
		free(rt->light);
	}
	if (rt->plane)
	{
		free(rt->plane->coordinate);;
		free(rt->plane->color);
		free(rt->plane->vector);
		free(rt->plane);
	}
}

void	free_shape(t_minirt *rt)
{
	if (rt->sphere)
	{
		free(rt->sphere->coordinate);
		free(rt->sphere->color);
		free(rt->sphere);
	}
	if (rt->cylinder)
	{
		free(rt->cylinder->coordinate);
		free(rt->cylinder->color);
		free(rt->cylinder->vector);
		free(rt->cylinder);
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
