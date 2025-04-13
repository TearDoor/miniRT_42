/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:00:38 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/13 19:49:07 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	align_orientation(t_obj *obj, t_tuple orient)
{
	apply_transform(obj, rot_vector_to_vector(vector(0, 1, 0), orient));
}

t_obj	*load_sphere(t_shape *p_sphere)
{
	t_obj	*new_sphere;
	double	radius;

	new_sphere = sphere();
	new_sphere->material.color = p_sphere->sphere.color;
	radius = p_sphere->sphere.diameter / 2;
	apply_transform(new_sphere, equal_scaling_mat(radius));
	apply_transform(new_sphere, tuple_translate(p_sphere->sphere.coordinate));
	return (new_sphere);
}

t_obj	*load_plane(t_shape *p_plane)
{
	t_obj	*new_plane;

	new_plane = plane();
	new_plane->material.color = p_plane->plane.color;
	align_orientation(new_plane, p_plane->plane.vector);
	apply_transform(new_plane, tuple_translate(p_plane->plane.coordinate));
	return (new_plane);
}

t_obj	*load_cyl_cone(t_obj *obj, t_shape *p_cyl_cone)
{
	double	radius;
	double	height;

	obj->material.color = p_cyl_cone->cy_cone.color;
	radius = p_cyl_cone->cy_cone.diameter / 2;
	height = p_cyl_cone->cy_cone.height;
	apply_transform(obj, scaling_mat(radius, height, radius));
	align_orientation(obj, p_cyl_cone->cy_cone.vector);
	apply_transform(obj, tuple_translate(p_cyl_cone->cy_cone.coordinate));
	return (obj);
}

t_obj	*load_cyl(t_shape *p_cyl)
{
	t_obj	*new_cyl;

	new_cyl = cylinder();
	new_cyl = load_cyl_cone(new_cyl, p_cyl);
	return (new_cyl);
}

t_obj	*load_cone(t_shape *p_cone)
{
	t_obj	*new_cone;

	new_cone = cone();
	new_cone = load_cyl_cone(new_cone, p_cone);
	return (new_cone);
}

void	load_objects(t_world *world, t_parse_obj *p_obj_list)
{
	t_parse_obj				*ptr;
	t_obj					*new_obj;
	const t_obj_cons_ptr	obj_cons[] = {
	[SPHERE] = load_sphere,
	[PLANE] = load_plane,
	[CYLINDER] = load_cyl,
	[SINGLE_CONE] = load_cone,
	[DOUBLE_CONE] = load_cone,
	};

	ptr = p_obj_list;
	while (ptr)
	{
		new_obj = obj_cons[ptr->id](&ptr->shape);
		add_obj_to_world(world, new_obj);
		ptr = ptr->next;
	}
}
