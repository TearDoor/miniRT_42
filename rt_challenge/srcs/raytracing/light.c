/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:57:51 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/14 15:59:56 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_tuple	normal_at(t_obj obj, t_tuple world_point)
{
	t_tuple	local_point;
	t_tuple	local_normal;
	t_tuple	world_normal;

	local_point = matrix_tuple_mult(obj.inverse_transform, world_point);
	local_normal = obj.local_normal_at(local_point);
	world_normal = matrix_tuple_mult(\
				matrix_transpose(obj.inverse_transform), local_normal);
	world_normal.w = 0;
	return (vector_normalize(world_normal));
}

t_tuple	reflect(t_tuple v_in, t_tuple normal)
{
	t_tuple	temp;

	temp = tuple_scalar_mult(normal, 2 * vector_dot_product(v_in, normal));
	return (tuple_subtract(v_in, temp));
}

t_light	point_light(t_color intensity, t_tuple position)
{
	return ((t_light){
		intensity, position
	});
}

t_material	material(void)
{
	return ((t_material){
		.color = (t_color){1, 1, 1},
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200,
		.pattern = NULL,
		.normalmap = NULL,
	});
}
