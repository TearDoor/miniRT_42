/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:00:38 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/11 22:27:36 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_obj	*load_sphere(t_shape *p_sphere)
{
	t_obj	*new_sphere;

	new_sphere = sphere();
	new_sphere->material.color = p_sphere->sphere.color;
	apply_transform(new_sphere, equal_scaling_mat(p_sphere->sphere.diameter));
	apply_transform(new_sphere, tuple_translate(p_sphere->sphere.coordinate));
	return (new_sphere);
}

t_obj	*load_plane(t_shape *p_plane)
{
	t_obj	*new_plane;

	new_plane = plane();
	new_plane->material.color = p_plane->plane.color;
	apply_transform(new_plane, tuple_translate(p_plane->plane.coordinate));
	return (new_plane);
}

t_obj	*load_cyl(t_shape *p_cyl)
{
	t_obj	*new_cyl;
	double	diameter;
	double	height;

	new_cyl = cylinder();
	new_cyl->material.color = p_cyl->cy_cone.color;
	diameter = p_cyl->cy_cone.diameter;
	height = p_cyl->cy_cone.height;
	apply_transform(new_cyl, scaling_mat(diameter, height, diameter));
	apply_transform(new_cyl, tuple_translate(p_cyl->cy_cone.coordinate));
	return (new_cyl);
}

void	load_objects(t_world *world, t_parse_obj *p_obj_list)
{
	t_parse_obj				*ptr;
	t_obj					*new_obj;
	const t_obj_cons_ptr	obj_cons[] = {
	[SPHERE] = load_sphere,
	[PLANE] = load_plane,
	[CYLINDER] = load_cyl,
	};

	ptr = p_obj_list;
	while (ptr)
	{
		new_obj = obj_cons[ptr->id](&ptr->shape);
		print_matrix(new_obj->transform);
		print_color(new_obj->material.color);
		add_obj_to_world(world, new_obj);
		ptr = ptr->next;
	}
}
