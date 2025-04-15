/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:00:38 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/13 21:28:21 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

t_obj	*load_dcone(t_shape *p_cone)
{
	t_obj	*new_dcone;

	p_cone->cy_cone.height = p_cone->cy_cone.height / 2;
	new_dcone = load_cone(p_cone);
	new_dcone->type = OBJ_DCONE;
	new_dcone->local_normal_at = dcone_normal_at;
	return (new_dcone);
}
