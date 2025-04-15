/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:14:47 by root              #+#    #+#             */
/*   Updated: 2025/04/14 16:56:21 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	parse_shape(t_obj_id id, char **info, t_parse *rt)
{
	t_parse_obj	*obj;

	printf("check_id = %d\n", id);
	obj = ft_calloc(sizeof(t_parse_obj), 1);
	init_obj(obj, id, rt);
	init_txr_bump(obj, info);
	printf("bump = %s\n", obj->bump_file); //debug
	if (id == PLANE)
		return (parse_plane(info, obj));
	else if (id == CYLINDER || id == SINGLE_CONE || id == DOUBLE_CONE)
		return (parse_cy_cone(info, obj));
	else if (id == SPHERE)
		return (parse_sphere(info, obj));
	return (0);
}

int	parse_cy_cone(char **info, t_parse_obj *obj)
{
	t_cy_cone	cy_cone;
	char		**coords;
	char		**vector;
	char		**color;
	int			i;

	i = -1;
	if (check_coords_vector(info, &vector, &coords) || check_color(info, &color, &coords, &vector))
		return (print_error("Invalid Argument for Cylinder or Cone"));
	while (++i < NUM_ARG_FIXED)
	{
		cy_cone.coordinate.elems[i] = ft_atod(coords[i]);
		cy_cone.vector.elems[i] = ft_atod(vector[i]);
		// printf("color = %s\n", color[i]); // debug
	}
	parse_cy(info, &cy_cone);
	cy_cone.vector = vector_normalize(cy_cone.vector);
	cy_cone.color.r = ft_atod(color[0]) / 255;
	cy_cone.color.g = ft_atod(color[1]) / 255;
	cy_cone.color.b = ft_atod(color[2]) / 255;
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
	obj->shape.cy_cone = cy_cone;
	return (0);
}

int	parse_plane(char **info, t_parse_obj *obj)
{
	t_plane	plane;
	char	**coords;
	char	**vector;
	char	**color;
	int		i;

	i = -1;
	if (check_coords_vector(info, &vector, &coords) || check_color(info, &color, &coords, &vector))
		return (print_error("Invalid Argument for plane"));
	while (++i < NUM_ARG_FIXED)
	{
		plane.coordinate.elems[i] = ft_atod(coords[i]);
		// printf("coords = %f\n", plane.coordinate[i]); // debug
		plane.vector.elems[i] = ft_atod(vector[i]);
	}
	plane.vector = vector_normalize(plane.vector);
	plane.color.r = ft_atod(color[0]) / 255;
	plane.color.g = ft_atod(color[1]) / 255;
	plane.color.b = ft_atod(color[2]) / 255;
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
	obj->shape.plane = plane;
	return (0);
}

int	parse_sphere(char **info, t_parse_obj *obj)
{
	t_sphere	sphere;
	char		**coords;
	char		**color;
	int			i;

	i = -1;
	if (check_coords_vector(info, NULL, &coords) || check_color(info, &color, &coords, NULL))
		return (print_error("Invalid Argument for sphere"));
	while (++i < NUM_ARG_FIXED)
	{
		sphere.coordinate.elems[i] = ft_atod(coords[i]);
	}
	print_tuple(sphere.coordinate);
	sphere.color.r = ft_atod(color[0]) / 255;
	sphere.color.g = ft_atod(color[1]) / 255;
	sphere.color.b = ft_atod(color[2]) / 255;
	sphere.diameter = ft_atod(info[2]);
	free_arr(coords);
	free_arr(color);
	obj->shape.sphere = sphere;
	return (0);
}
