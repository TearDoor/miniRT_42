/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:14:47 by root              #+#    #+#             */
/*   Updated: 2025/04/16 17:26:32 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	check_bump_file(t_parse_obj *obj)
{
	if (obj->bump_file)
	{
		if (access(obj->bump_file, F_OK) == -1)
		{
			print_error("Bump file not found");
			return (1);
		}
		if (ft_strlen(obj->bump_file) < 4
			|| ft_strcmp(obj->bump_file
				+ ft_strlen(obj->bump_file) - 4, ".ppm") != 0)
		{
			print_error("Bump file must be .ppm");
			return (1);
		}
	}
	return (0);
}

int	check_texture_file(t_parse_obj *obj)
{
	if (obj->texture_file)
	{
		if (access(obj->texture_file, F_OK) == -1)
		{
			print_error("Texture file not found");
			return (1);
		}
		if (ft_strlen(obj->texture_file) < 4
			|| ft_strcmp(obj->texture_file
				+ ft_strlen(obj->texture_file) - 4, ".ppm") != 0)
		{
			print_error("Texture file must be .ppm");
			return (1);
		}
	}
	return (0);
}

int	parse_shape(t_obj_id id, char **info, t_parse *rt)
{
	t_parse_obj	*obj;

	printf("check_id = %d\n", id);
	obj = ft_calloc(sizeof(t_parse_obj), 1);
	init_obj(obj, id, rt);
	init_txr_bump(obj, info);
	if (check_texture_file(obj) || check_bump_file(obj))
		return (1);
	if (id == PLANE)
		return (parse_plane(info, obj, rt));
	else if (id == CYLINDER || id == SINGLE_CONE || id == DOUBLE_CONE)
		return (parse_cy_cone(info, obj, rt));
	else if (id == SPHERE)
		return (parse_sphere(info, obj, rt));
	return (0);
}

int	parse_cy_cone(char **info, t_parse_obj *obj, t_parse *rt)
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
		cy_cone.coordinate.elems[i] = ft_atod(coords[i], rt);
		cy_cone.vector.elems[i] = ft_atod(vector[i], rt);
		// printf("color = %s\n", color[i]); // debug
	}
	cy_cone.diameter = ft_atod(info[3], rt);
	cy_cone.height = ft_atod(info[4], rt);
	cy_cone.vector = vector_normalize(cy_cone.vector);
	cy_cone.color.r = ft_atod(color[0], rt) / 255;
	cy_cone.color.g = ft_atod(color[1], rt) / 255;
	cy_cone.color.b = ft_atod(color[2], rt) / 255;
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
	obj->shape.cy_cone = cy_cone;
	return (0);
}

int	parse_plane(char **info, t_parse_obj *obj, t_parse *rt)
{
	t_plane	plane;
	char	**coords;
	char	**vector;
	char	**color;
	int		i;

	i = -1;
	if (check_coords_vector(info, &vector, &coords) || check_color(info, &color, &coords, &vector))
		return (print_error("Invalid Argument for Plane"));
	while (++i < NUM_ARG_FIXED)
	{
		plane.coordinate.elems[i] = ft_atod(coords[i], rt);
		// printf("coords = %f\n", plane.coordinate[i]); // debug
		plane.vector.elems[i] = ft_atod(vector[i], rt);
	}
	plane.vector = vector_normalize(plane.vector);
	plane.color.r = ft_atod(color[0], rt) / 255;
	plane.color.g = ft_atod(color[1], rt) / 255;
	plane.color.b = ft_atod(color[2], rt) / 255;
	free_arr(coords);
	free_arr(vector);
	free_arr(color);
	obj->shape.plane = plane;
	return (0);
}

int	parse_sphere(char **info, t_parse_obj *obj, t_parse *rt)
{
	t_sphere	sphere;
	char		**coords;
	char		**color;
	int			i;

	i = -1;
	if (check_coords_vector(info, NULL, &coords) || check_color(info, &color, &coords, NULL))
		return (print_error("Invalid Argument for Sphere"));
	while (++i < NUM_ARG_FIXED)
	{
		sphere.coordinate.elems[i] = ft_atod(coords[i], rt);
	}
	sphere.coordinate.w = 1;
	print_tuple(sphere.coordinate);
	sphere.color.r = ft_atod(color[0], rt) / 255;
	sphere.color.g = ft_atod(color[1], rt) / 255;
	sphere.color.b = ft_atod(color[2], rt) / 255;
	sphere.diameter = ft_atod(info[2], rt);
	free_arr(coords);
	free_arr(color);
	obj->shape.sphere = sphere;
	return (0);
}
