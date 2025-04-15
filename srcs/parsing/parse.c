/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 06:34:22 by root              #+#    #+#             */
/*   Updated: 2025/04/14 16:39:29 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	parse_file(int fd, t_parse *rt)
{
	char	*line;
	char	**info;

	line = get_next_line(fd);
	while (line && !rt->invalid)
	{
		filter_line(line, &info);
		if (store_info(info, rt))
			rt->invalid = 1;
		free(line);
		free_arr(info);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (!rt->invalid && validate_file(rt))
		rt->invalid = 1;
	close(fd);
	// printf("invalid = %d\n", invalid); // debug
	return (rt->invalid);
}

int	store_info(char **info, t_parse *rt)
{
	printf("info[0]= %s\n", info[0]); // debug
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
	else if (ft_strcmp(info[0], "sc") == 0)
		return (parse_shape(SINGLE_CONE, info, rt));
	else if (ft_strcmp(info[0], "dc") == 0)
		return (parse_shape(DOUBLE_CONE, info, rt));
	return (0);
}

int	parse_ambient(char **info, t_parse *rt)
{
	t_ambient	ambient;
	char		**color;

	if (check_arrlen(info, 3))
		return (print_error("Invalid arguments for Ambient"));
	if (rt->ambient.id)
		return (print_error("Too many A argument"));
	ambient.id = AMBIENT;
	ambient.ratio = ft_atod(info[1], rt);
	color = ft_split(info[2], ',');
	if (ft_arrlen(color) != 3)
	{
		free_arr(color);
		return (print_error("Invalid arguments for Ambient (color)"));
	}
	ambient.color.r = ft_atod(color[0], rt) / 255;
	ambient.color.g = ft_atod(color[1], rt) / 255;
	ambient.color.b = ft_atod(color[2], rt) / 255;
	printf("ambient color b = %f\n", ambient.color.b); // debug
	rt->ambient = ambient;
	print_color(ambient.color); // debug
	free_arr(color);
	return (0);
}

int	parse_camera(char **info, t_parse *rt)
{
	t_parse_camera	camera;
	char			**coords;
	char			**vector;
	int				i;

	i = -1;
	if (check_arrlen(info, 4))
		return (print_error("Invalid arguments for Camera"));
	if (rt->camera.id)
		return (print_error("Too many C argument"));
	camera.id = CAMERA;
	if (check_coords_vector(info, &vector, &coords))
		return (print_error("Invalid arg for Camera (vector or coords)"));
	while (++i < NUM_ARG_FIXED)
	{
		camera.coordinate.elems[i] = ft_atod(coords[i], rt);
		camera.vector.elems[i] = ft_atod(vector[i], rt);
	}
	camera.coordinate.w = 1;
	camera.vector.w = 0;
	camera.fov = ft_atoi(info[3]);
	// printf("fov = %d\n", camera.fov); //debug
	rt->camera = camera;
	free_arr(coords);
	free_arr(vector);
	return (0);
}

int	parse_light(char **info, t_parse *rt)
{
	t_parse_light	*light;
	char			**color;
	char			**coords;
	int				i;

	i = -1;
	if (check_arrlen(info, 4))
		return (print_error("Invalid arguments for Light"));
	light = NULL;
	light = init_light(light, rt);
	light->id = LIGHT;
	if (check_coords_vector(info, NULL, &coords) || check_color(info, &color, &coords, NULL))
		return (print_error("Invalid arguments for Light (coords or color)"));
	light->ratio = ft_atod(info[2], rt);
	while (++i < NUM_ARG_FIXED)
		light->coordinate.elems[i] = ft_atod(coords[i], rt);
	light->coordinate.w = 1;
	print_tuple(light->coordinate); // debug
	light->color.r = ft_atod(color[0], rt) / 255;
	light->color.g = ft_atod(color[1], rt) / 255;
	light->color.b = ft_atod(color[2], rt) / 255;
	free_arr(coords);
	free_arr(color);
	return (0);
}
