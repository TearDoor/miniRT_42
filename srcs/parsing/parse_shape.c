/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:14:47 by root              #+#    #+#             */
/*   Updated: 2025/04/19 22:13:01 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	parse_shape(t_obj_id id, char **info, t_parse *rt)
{
	t_parse_obj	*obj;

	obj = ft_calloc(sizeof(t_parse_obj), 1);
	init_obj(obj, id, rt);
	init_txr_bump(obj, info);
	if (obj->texture_file)
		if (check_texture_file(obj))
			return (1);
	if (obj->bump_file)
		if (check_bump_file(obj))
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

	if (check_coords_vector(info, &vector, &coords)
		|| check_color(info, &color, &coords, &vector))
		return (print_error("Invalid Argument for Cylinder or Cone"));
	init_cy_cone(&cy_cone, coords, vector, rt);
	cy_cone.diameter = ft_atod(info[3], rt);
	cy_cone.height = ft_atod(info[4], rt);
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
	if (check_coords_vector(info, &vector, &coords)
		|| check_color(info, &color, &coords, &vector))
		return (print_error("Invalid Argument for Plane"));
	init_plane(&plane, coords, vector, rt);
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
	if (check_coords_vector(info, NULL, &coords)
		|| check_color(info, &color, &coords, NULL))
		return (print_error("Invalid Argument for Sphere"));
	while (++i < NUM_ARG_FIXED)
		sphere.coordinate.elems[i] = ft_atod(coords[i], rt);
	sphere.coordinate.w = 1;
	sphere.color.r = ft_atod(color[0], rt) / 255;
	sphere.color.g = ft_atod(color[1], rt) / 255;
	sphere.color.b = ft_atod(color[2], rt) / 255;
	sphere.diameter = ft_atod(info[2], rt);
	free_arr(coords);
	free_arr(color);
	obj->shape.sphere = sphere;
	return (0);
}
