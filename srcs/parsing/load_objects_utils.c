/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_objects_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:19:06 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/13 21:30:42 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	align_orientation(t_obj *obj, t_tuple orient)
{
	apply_transform(obj, rot_vector_to_vector(vector(0, 1, 0), orient));
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
