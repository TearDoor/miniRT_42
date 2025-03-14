/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:07:09 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/14 16:06:10 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "minirt.h"
#include <stdio.h>

t_tuple	color_to_normal(t_color clr)
{
	double	x;
	double	y;
	double	z;

	x = (clr.r * 2.0) - 1.0;
	y = (clr.g * 2.0) - 1.0;
	z = (clr.b * 2.0) - 1.0;
	return (vector(x, y, z));
}

t_tuple	**colormap_to_normalmap(t_canvas *cvs)
{
	t_tuple	**normals;
	int		i;
	int		j;

	normals = malloc(sizeof(t_tuple *) * (cvs->height + 1));
	j = 0;
	while (j < cvs->height)
	{
		normals[j] = malloc(sizeof(t_tuple) * cvs->width);
		i = 0;
		while (i < cvs->width)
		{
			normals[j][i] = color_to_normal(cvs->pixels[j][i]);
			i++;
		}
		j++;
	}
	normals[j] = NULL;
	return (normals);
}

t_tuple	**normal_map(char *filename)
{
	char		*file_exten;
	t_canvas	cvs;
	t_tuple		**normalmap;

	file_exten = ft_strrchr(filename, '.');
	if (!file_exten || ft_strcmp(file_exten, ".ppm") != 0)
		error_exit("normal map must be from ppm file.");
	cvs = canvas_from_ppm(filename);
	normalmap = colormap_to_normalmap(&cvs);
	free_canvas(cvs);
	return (normalmap);
}
