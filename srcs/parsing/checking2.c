/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:42:01 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/04/23 18:43:09 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	check_arrlen(char **arr, int length)
{
	if (ft_arrlen(arr) != length)
		return (1);
	return (0);
}

int	check_bump_file(t_parse_obj *obj)
{
	if (obj->bump_file)
	{
		if (access(obj->bump_file, F_OK) == -1)
		{
			print_error("Bump file not found");
			free(obj->bump_file);
			obj->bump_file = NULL;
			return (1);
		}
		if (ft_strlen(obj->bump_file) < 4
			|| ft_strcmp(obj->bump_file
				+ ft_strlen(obj->bump_file) - 4, ".ppm") != 0)
		{
			print_error("Bump file must be .ppm");
			return (1);
		}
	}
	return (0);
}

int	check_texture_file(t_parse_obj *obj)
{
	if (obj->texture_file)
	{
		if (access(obj->texture_file, F_OK) == -1)
		{
			print_error("Texture file not found");
			free(obj->texture_file);
			obj->texture_file = NULL;
			return (1);
		}
		if (ft_strlen(obj->texture_file) < 4
			|| ft_strcmp(obj->texture_file
				+ ft_strlen(obj->texture_file) - 4, ".ppm") != 0)
		{
			print_error("Texture file must be .ppm");
			return (1);
		}
	}
	return (0);
}
