/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:52:59 by root              #+#    #+#             */
/*   Updated: 2025/04/18 11:07:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

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
		// printf("free tmp_light = %d\n", tmp_light->id); //debug
		light = light->next;
		free(tmp_light);
	}
	obj = rt->obj_list;
	while (obj)
	{
		tmp = obj;
		if (tmp->texture_file
				&& access(tmp->texture_file, F_OK) != -1)
			free(tmp->texture_file);
		if (tmp->bump_file
				&& access(tmp->bump_file, F_OK) != -1)
			free(tmp->bump_file);
		obj = obj->next;
		// printf("free id = %d\n", tmp->id); // debug
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

int	print_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	return (1);
}
