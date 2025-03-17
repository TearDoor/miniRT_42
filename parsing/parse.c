/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-10 06:34:22 by root              #+#    #+#             */
/*   Updated: 2025-03-10 06:34:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt	*parse_file(int fd)
{
	t_minirt	*rt;
	char		*line;
	char		**info;

	rt = ft_calloc(1, sizeof(t_minirt));
	line = get_next_line(fd);
	while (line)
	{
		filter_line(line, &info);
		store_info(info, rt);
		free(line);
		free_arr(info);
		line = get_next_line(fd);
	}
	return (rt);
}

void	store_info(char **info, t_minirt *rt)
{
	printf("info[0] = %s\n", info[0]); // debug
	if (!info || !info[0])
		return ;
	else if (ft_strcmp(info[0], "A") == 0)
		parse_ambient(info, rt);
	else if (ft_strcmp(info[0], "C") == 0)
		parse_camera(info, rt);
	else if (ft_strcmp(info[0], "L") == 0)
		parse_light(info, rt);
	else if (ft_strcmp(info[0], "pl") == 0)
		parse_plane(info, rt);
	else if (ft_strcmp(info[0], "sp") == 0)
		parse_sphere(info, rt);
	else if (ft_strcmp(info[0], "cy") == 0)
		parse_cylinder(info, rt);	
}

void	parse_ambient(char **info, t_minirt *rt)
{
	t_ambient	*ambient;
	char		**color;
	int			i;

	i = -1;
	ambient = malloc(sizeof(t_ambient));
	ambient->ratio = ft_atof(info[1]);
	printf("info[1] = %f\n", ambient->ratio); // debug
	ambient->color = malloc(sizeof(int) * COLOR_RGB);
	color = ft_split(info[2], ',');
	while (++i < COLOR_RGB)
	{
		ambient->color[i] = ft_atoi(color[i]);
		// printf("color = %d\n", ambient->color[i]); // debug
	}
	rt->ambient = ambient;
	free_arr(color);
}

void	parse_camera(char **info, t_minirt *rt)
{
	t_camera	*camera;
	char		**coords;
	char		**vector;
	int			i;

	i = -1;
	camera = malloc(sizeof(t_camera));
	camera->coordinate = malloc(sizeof(float) * COORDS_XYZ);
	camera->vector = malloc(sizeof(float) * VECTORS);
	coords = ft_split(info[1], ',');
	while (++i < COORDS_XYZ)
	{
		camera->coordinate[i] = ft_atof(coords[i]);
		// printf("coords = %f\n", camera->coordinate[i]);
	}
	vector = ft_split(info[2], ',');
	i = -1;
	while (++i < VECTORS)
	{
		camera->vector[i] = ft_atof(vector[i]);
		// printf("vector = %f\n", camera->vector[i]);
	}
	camera->fov = ft_atoi(info[3]);
	// printf("fov = %d\n", camera->fov); //debug
	rt->camera = camera;
	free_arr(coords);
	free_arr(vector);
}

void	parse_light(char **info, t_minirt *rt)
{
	t_light	*light;
	char	**color;
	char	**coords;
	int		i;

	i = -1;
	light = malloc(sizeof(t_light));
	light->coordinate = malloc(sizeof(float) * COORDS_XYZ);
	coords = ft_split(info[1], ',');
	while (++i < COORDS_XYZ)
	{
		light->coordinate[i] = ft_atof(coords[i]);
		// printf("coords = %f\n", light->coordinate[i]);
	}
	light->ratio = ft_atof(info[2]);
	light->color = malloc(sizeof(int) * COLOR_RGB);
	color = ft_split(info[3], ',');
	i = -1;
	while (++i < COLOR_RGB)
	{
		light->color[i] = ft_atoi(color[i]);
		// printf("coords = %d\n", light->color[i]);
	}
	rt->light = light;
	free_arr(coords);
	free_arr(color);
}
