/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:57:51 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/27 21:45:33 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_tuple	normal_at(t_obj sp, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = matrix_tuple_mult(matrix_invert(sp.transform), world_point);
	object_normal = tuple_subtract(object_point, sp.origin);
	world_normal = matrix_tuple_mult(\
				matrix_transpose(matrix_invert(sp.transform)), object_normal);
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
	});
}
