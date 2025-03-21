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

int	parse_file(int fd, t_minirt *rt)
{
	char	*line;
	char	**info;
	int		invalid;

	line = get_next_line(fd);
	invalid = 0;
	while (line && !invalid)
	{
		filter_line(line, &info);
		if (store_info(info, rt))
			invalid = 1;
		free(line);
		free_arr(info);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (!invalid && validate_file(rt))
		invalid = 1;
	close(fd);
	// printf("invalid = %d\n", invalid); // debug
	return (invalid);
}

int	store_info(char **info, t_minirt *rt)
{
	// printf("info[0] = %s\n", info[0]); // debug
	if (!info || !info[0])
		return (0);
	else if (ft_strcmp(info[0], "A") == 0)
		return (parse_ambient(info, rt));
	else if (ft_strcmp(info[0], "C") == 0)
		return (parse_camera(info, rt));
	else if (ft_strcmp(info[0], "L") == 0)
		return (parse_light(info, rt));
	else if (ft_strcmp(info[0], "pl") == 0)
		return (parse_shape(PLANE, info, rt));
	else if (ft_strcmp(info[0], "sp") == 0)
		return (parse_shape(SPHERE, info, rt));
	else if (ft_strcmp(info[0], "cy") == 0)
		return (parse_shape(CYLINDER, info, rt));
	return (0);
}

int	parse_ambient(char **info, t_minirt *rt)
{
	t_ambient	ambient;
	char		**color;
	int			i;

	i = -1;
	if (rt->ambient.id)
		return (print_error("Too many A argument"));
	ambient.id = AMBIENT;
	ambient.ratio = ft_atof(info[1]);
	// printf("info[1] = %f\n", ambient.ratio); // debug
	ambient.color = malloc(sizeof(int) * NUM_ARG_FIXED);
	color = ft_split(info[2], ',');
	while (++i < NUM_ARG_FIXED)
	{
		ambient.color[i] = ft_atoi(color[i]);
		// printf("color = %d\n", ambient.color[i]); // debug
	}
	rt->ambient = ambient;
	free_arr(color);
	return (0);
}

int	parse_camera(char **info, t_minirt *rt)
{
	t_camera	camera;
	char		**coords;
	char		**vector;
	int			i;

	i = -1;
	if (rt->camera.id)
		return (print_error("Too many C argument"));
	camera.id = CAMERA;
	camera.coordinate = malloc(sizeof(float) * NUM_ARG_FIXED);
	camera.vector = malloc(sizeof(float) * NUM_ARG_FIXED);
	coords = ft_split(info[1], ',');
	vector = ft_split(info[2], ',');
	while (++i < NUM_ARG_FIXED)
	{
		camera.coordinate[i] = ft_atof(coords[i]);
		camera.vector[i] = ft_atof(vector[i]);
		// printf("coords = %f\n", camera.coordinate[i]);
		// printf("vector = %f\n", camera.vector[i]);
	}
	camera.fov = ft_atoi(info[3]);
	// printf("fov = %d\n", camera.fov); //debug
	rt->camera = camera;
	free_arr(coords);
	free_arr(vector);
	return (0);
}

int	parse_light(char **info, t_minirt *rt)
{
	t_light	light;
	char	**color;
	char	**coords;
	int		i;

	i = -1;
	if (rt->light.id)
		return (print_error("Too many L argument"));
	light.id = LIGHT;
	light.coordinate = malloc(sizeof(float) * NUM_ARG_FIXED);
	light.color = malloc(sizeof(int) * NUM_ARG_FIXED);
	coords = ft_split(info[1], ',');
	color = ft_split(info[3], ',');
	light.ratio = ft_atof(info[2]);
	while (++i < NUM_ARG_FIXED)
	{
		light.coordinate[i] = ft_atof(coords[i]);
		// printf("coords = %f\n", light->coordinate[i]);
		light.color[i] = ft_atoi(color[i]);
		// printf("coords = %d\n", light->color[i]);
	}
	rt->light = light;
	free_arr(coords);
	free_arr(color);
	return (0);
}
