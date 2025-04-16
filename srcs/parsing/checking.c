/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:31:41 by root              #+#    #+#             */
/*   Updated: 2025/04/16 17:39:33 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	check_arrlen(char **arr, int length)
{
	printf("arr_len in check_arrlen = %d\n", ft_arrlen(arr));
	if (ft_arrlen(arr) != length)
		return (1);
	return (0);
}

int	check_coords_vector(char **info, char ***vector, char ***coords)
{
	if (coords)
	{
		*coords = ft_split(info[1], ',');
		if (check_arrlen(*coords, 3))
		{
			free_arr(*coords);
			return (1);
		}
	}
	if (vector)
	{
		*vector = ft_split(info[2], ',');
		if (check_arrlen(*vector, 3))
		{
			free_arr(*vector);
			if (coords)
				free_arr(*coords);
			return (1);
		}
	}
	return (0);
}

int	check_color(char **info, char ***color, char ***coords, char ***vector)
{
	if (ft_strcmp(info[0], "pl") == 0 || ft_strcmp(info[0], "L") == 0
		|| ft_strcmp(info[0], "sp") == 0)
		*color = ft_split(info[3], ',');
	else if (ft_strcmp(info[0], "cy") == 0 || ft_strcmp(info[0], "sc") == 0
		|| ft_strcmp(info[0], "dc") == 0)
		*color = ft_split(info[5], ',');
	if (check_arrlen(*color, 3))
	{
		if (vector)
			free_arr(*vector);
		if (coords)
			free_arr(*coords);
		free_arr(*color);
		return (1);
	}
	return (0);
}

int	check_bump_file(t_parse_obj *obj)
{
	if (obj->bump_file)
	{
		if (access(obj->bump_file, F_OK) == -1)
		{
			print_error("Bump file not found");
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
