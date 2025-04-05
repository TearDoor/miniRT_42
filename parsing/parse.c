/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 06:34:22 by root              #+#    #+#             */
/*   Updated: 2025/03/31 11:33:56 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	parse_file(int fd, t_parse *rt)
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

int	store_info(char **info, t_parse *rt)
{
	printf("info[0] = %s\n", info[0]); // debug
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

int	parse_ambient(char **info, t_parse *rt)
{
	t_ambient	ambient;
	char		**color;

	if (rt->ambient.id)
		return (print_error("Too many A argument"));
	ambient.id = AMBIENT;
	ambient.ratio = ft_atod(info[1]);
	color = ft_split(info[2], ',');
	ambient.color.r = ft_atod(color[0]) / 255;
	ambient.color.g = ft_atod(color[1]) / 255;
	ambient.color.b = ft_atod(color[2]) / 255;
	rt->ambient = ambient;
	free_arr(color);
	return (0);
}

int	parse_camera(char **info, t_parse *rt)
{
	t_camera	camera;
	char		**coords;
	char		**vector;
	int			i;

	i = -1;
	if (rt->camera.id)
		return (print_error("Too many C argument"));
	camera.id = CAMERA;
	coords = ft_split(info[1], ',');
	vector = ft_split(info[2], ',');
	while (++i < NUM_ARG_FIXED)
	{
		camera.coordinate.elems[i] = ft_atod(coords[i]);
		camera.vector.elems[i] = ft_atod(vector[i]);
		printf("camera vector = %f\n", camera.coordinate.elems[i]); //debug
	}
	camera.coordinate.w = 0;
	camera.vector.w = 1;
	printf("camera vector = %f\n", camera.vector.w); //debug
	camera.fov = ft_atoi(info[3]);
	// printf("fov = %d\n", camera.fov); //debug
	rt->camera = camera;
	free_arr(coords);
	free_arr(vector);
	return (0);
}

int	parse_light(char **info, t_parse *rt)
{
	t_light	*light;
	char	**color;
	char	**coords;
	int		i;

	i = -1;
	light = init_light(light, rt);
	light->id = LIGHT;
	light->coordinate = malloc(sizeof(double) * NUM_ARG_FIXED);
	light->color = malloc(sizeof(double) * NUM_ARG_FIXED);
	coords = ft_split(info[1], ',');
	color = ft_split(info[3], ',');
	light->ratio = ft_atod(info[2]);
	while (++i < NUM_ARG_FIXED)
	{
		light->coordinate[i] = ft_atod(coords[i]);
		printf("coords = %f\n", light->coordinate[i]);
		light->color[i] = ft_atoi(color[i]) / 255;
		// printf("color = %f\n", light->color[i]);
	}
	free_arr(coords);
	free_arr(color);
	return (0);
}
