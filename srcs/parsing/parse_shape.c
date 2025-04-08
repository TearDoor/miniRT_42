/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:14:47 by root              #+#    #+#             */
/*   Updated: 2025/04/08 17:29:00 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	parse_cy(char **info, t_cylinder *cylinder)
{
	// printf("info[3] = %s\n", info[3]); //debug
	// printf("info[4] = %s\n", info[4]); //debug
	cylinder->diameter = ft_atod(info[3]);
	cylinder->height = ft_atod(info[4]);
}

int	parse_shape(t_obj_id id, char **info, t_parse *rt)
{
	t_parse_obj	*obj;

	obj = ft_calloc(sizeof(t_parse_obj), 1);
	init_obj(obj, id, rt);
	init_txr_bump(obj, info);
	printf("bump = %s\n", obj->bump_file); //debug
	if (id == PLANE)
		parse_plane(info, obj);
	else if (id == CYLINDER)
		parse_cylinder(info, obj);
	else if (id == SPHERE)
		parse_sphere(info, obj);
	return (0);
}

void	parse_cylinder(char **info, t_parse_obj *obj)
{
	t_cylinder	cylinder;
	char		**coords;
	char		**vector;
	char		**color;
	int			i;

	i = -1;
	cylinder.coordinate = malloc(sizeof(double) * NUM_ARG_FIXED);
	cylinder.vector = malloc(sizeof(double) * NUM_ARG_FIXED);
	cylinder.color = malloc(sizeof(double) * NUM_ARG_FIXED);
	coords = ft_split(info[1], ',');
	vector = ft_split(info[2], ',');
	color = ft_split(info[5], ',');
	while (++i < NUM_ARG_FIXED)
	{
		cylinder.coordinate[i] = ft_atod(coords[i]);
		cylinder.vector[i] = ft_atod(vector[i]);
		cylinder.color[i] = ft_atod(color[i]) / 255;
		printf("cylinder color = %f\n", cylinder.color[i]); // debug
	}
	parse_cy(info, &cylinder);
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
	obj->shape.cylinder = cylinder;
}

void	parse_plane(char **info, t_parse_obj *obj)
{
	t_plane	plane;
	char	**coords;
	char	**vector;
	char	**color;
	int		i;

	i = -1;
	plane.coordinate = malloc(sizeof(double) * NUM_ARG_FIXED);
	plane.vector = malloc(sizeof(double) * NUM_ARG_FIXED);
	plane.color = malloc(sizeof(double) * NUM_ARG_FIXED);
	coords = ft_split(info[1], ',');
	vector = ft_split(info[2], ',');
	color = ft_split(info[3], ',');
	while (++i < NUM_ARG_FIXED)
	{
		plane.coordinate[i] = ft_atod(coords[i]);
		// printf("coords = %f\n", plane.coordinate[i]); // debug
		plane.vector[i] = ft_atod(vector[i]);
		plane.color[i] = ft_atod(color[i]) / 255;
		printf("plane color = %f\n", plane.color[i]); // debug
	}
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
	obj->shape.plane = plane;
}

void	parse_sphere(char **info, t_parse_obj *obj)
{
	t_sphere	sphere;
	char		**coords;
	char		**color;
	int			i;

	sphere.coordinate = malloc(sizeof(double) * NUM_ARG_FIXED);
	sphere.color = malloc(sizeof(double) * NUM_ARG_FIXED);
	i = -1;
	coords = ft_split(info[1], ',');
	color = ft_split(info[3], ',');
	while (++i < NUM_ARG_FIXED)
	{
		sphere.coordinate[i] = ft_atod(coords[i]);
		// printf("coords = %f\n", sphere.coordinate[i]); // debug
		sphere.color[i] = ft_atoi(color[i]) / 255;
		printf("sphere color = %f\n", sphere.color[i]); // debug
	}
	sphere.diameter = ft_atod(info[2]);
	free_arr(coords);
	free_arr(color);
	obj->shape.sphere = sphere;
}
