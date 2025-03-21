/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_acl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-10 15:14:47 by root              #+#    #+#             */
/*   Updated: 2025-03-10 15:14:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_cy(char **info, t_cylinder *cylinder)
{
	// printf("info[3] = %s\n", info[3]); //debug
	// printf("info[4] = %s\n", info[4]); //debug
	cylinder->diameter = ft_atof(info[3]);
	cylinder->height = ft_atof(info[4]);
}

int	parse_shape(t_obj_id id, char **info, t_minirt *rt)
{
	t_obj	*obj;

	obj = ft_calloc(sizeof(t_obj), 1);
	init_obj(obj, id, rt);
	init_txr_bump(obj, info);
	if (id == PLANE)
		parse_plane(info, obj);
	else if (id == CYLINDER)
		parse_cylinder(info, obj);
	else if (id == SPHERE)
		parse_sphere(info, obj);
	return (0);
}

void	parse_cylinder(char **info, t_obj *obj)
{
	t_cylinder	cylinder;
	char		**coords;
	char		**vector;
	char		**color;
	int			i;

	i = -1;
	cylinder.coordinate = malloc(sizeof(float) * NUM_ARG_FIXED);
	cylinder.vector = malloc(sizeof(float) * NUM_ARG_FIXED);
	cylinder.color = malloc(sizeof(int) * NUM_ARG_FIXED);
	coords = ft_split(info[1], ',');
	vector = ft_split(info[2], ',');
	color = ft_split(info[5], ',');
	while (++i < NUM_ARG_FIXED)
	{
		cylinder.coordinate[i] = ft_atof(coords[i]);
		cylinder.vector[i] = ft_atof(vector[i]);
		cylinder.color[i] = ft_atof(color[i]);
	}
	parse_cy(info, &cylinder);
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
	obj->shape.cylinder = cylinder;
	// printf("height = %f\n", obj->shape.cylinder.height); // debug
}

void	parse_plane(char **info, t_obj *obj)
{
	t_plane	plane;
	char	**coords;
	char	**vector;
	char	**color;
	int		i;

	i = -1;
	plane.coordinate = malloc(sizeof(float) * NUM_ARG_FIXED);
	plane.vector = malloc(sizeof(float) * NUM_ARG_FIXED);
	plane.color = malloc(sizeof(int) * NUM_ARG_FIXED);
	coords = ft_split(info[1], ',');
	vector = ft_split(info[2], ',');
	color = ft_split(info[3], ',');
	while (++i < NUM_ARG_FIXED)
	{
		plane.coordinate[i] = ft_atof(coords[i]);
		// printf("coords = %f\n", plane.coordinate[i]); // debug
		plane.vector[i] = ft_atof(vector[i]);
		// printf("vector = %f\n", plane->vector[i]); // debug
		plane.color[i] = ft_atof(color[i]);
		// printf("color = %d\n", plane->color[i]); // debug
	}
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
	obj->shape.plane = plane;
}

void	parse_sphere(char **info, t_obj *obj)
{
	t_sphere	sphere;
	char		**coords;
	char		**color;
	int			i;

	sphere.coordinate = malloc(sizeof(float) * NUM_ARG_FIXED);
	sphere.color = malloc(sizeof(int) * NUM_ARG_FIXED);
	i = -1;
	coords = ft_split(info[1], ',');
	color = ft_split(info[3], ',');
	while (++i < NUM_ARG_FIXED)
	{
		sphere.coordinate[i] = ft_atof(coords[i]);
		// printf("coords = %f\n", sphere.coordinate[i]); // debug
		sphere.color[i] = ft_atoi(color[i]);
		// printf("color = %d\n", sphere->color[i]); // debug
	}
	sphere.diameter = ft_atof(info[2]);
	free_arr(coords);
	free_arr(color);
	obj->shape.sphere = sphere;
}
