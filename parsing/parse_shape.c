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

void	parse_cylinder(char **info, t_minirt *rt)
{
	t_cylinder	*cylinder;
	char	**coords;
	char	**vector;
	char	**color;
	int		i;

	i = -1;
	cylinder = malloc(sizeof(t_cylinder));
	cylinder->coordinate = malloc(sizeof(float) * COORDS_XYZ);
	cylinder->vector = malloc(sizeof(float) * VECTORS);
	cylinder->color = malloc(sizeof(int) * COLOR_RGB);
	coords = ft_split(info[1], ',');
	vector = ft_split(info[2], ',');
	color = ft_split(info[5], ',');
	while (++i < 3)
	{
		cylinder->coordinate[i] = ft_atof(coords[i]);
		// printf("coords = %f\n", cylinder->coordinate[i]); // debug
		cylinder->vector[i] = ft_atof(vector[i]);
		// printf("vector = %f\n", cylinder->vector[i]); // debug
		cylinder->color[i] = ft_atof(color[i]);
		// printf("color = %d\n", cylinder->color[i]); // debug
	}
	parse_cy(info, cylinder);
	// printf("diameter = %f\n", cylinder->diameter); // debug
	// printf("height = %f\n", cylinder->height); // debug
	rt->cylinder = cylinder;
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
}

void	parse_plane(char **info, t_minirt *rt)
{
	t_plane	*plane;
	char	**coords;
	char	**vector;
	char	**color;
	int		i;

	i = -1;
	plane = malloc(sizeof(t_plane));
	plane->coordinate = malloc(sizeof(float) * COORDS_XYZ);
	plane->vector = malloc(sizeof(float) * VECTORS);
	plane->color = malloc(sizeof(int) * COLOR_RGB);
	coords = ft_split(info[1], ',');
	vector = ft_split(info[2], ',');
	color = ft_split(info[3], ',');
	while (++i < 3)
	{
		plane->coordinate[i] = ft_atof(coords[i]);
		// printf("coords = %f\n", plane->coordinate[i]); // debug
		plane->vector[i] = ft_atof(vector[i]);
		// printf("vector = %f\n", plane->vector[i]); // debug
		plane->color[i] = ft_atof(color[i]);
		// printf("color = %d\n", plane->color[i]); // debug
	}
	rt->plane = plane;
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
}

void	parse_sphere(char **info, t_minirt *rt)
{
	t_sphere	*sphere;
	char		**coords;
	char		**color;
	int			i;

	sphere = malloc(sizeof(t_sphere));
	sphere->coordinate = malloc(sizeof(float) * COORDS_XYZ);
	sphere->color = malloc(sizeof(int) * COLOR_RGB);
	i = -1;
	coords = ft_split(info[1], ',');
	color = ft_split(info[3], ',');
	while (++i < 3)
	{
		sphere->coordinate[i] = ft_atof(coords[i]);
		// printf("coords = %f\n", sphere->coordinate[i]); // debug
		sphere->color[i] = ft_atoi(color[i]);
		// printf("color = %d\n", sphere->color[i]); // debug
	}
	sphere->diameter = ft_atof(info[2]);
	rt->sphere = sphere;
	free_arr(coords);
	free_arr(color);
}
