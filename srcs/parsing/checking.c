/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:31:41 by root              #+#    #+#             */
/*   Updated: 2025/04/14 16:56:04 by hni-xuan         ###   ########.fr       */
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
