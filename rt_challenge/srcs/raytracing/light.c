/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:57:51 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/05 22:44:42 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include <math.h>

/*
 * Important part of building tbn matrix: handedness of coordinate system
 * the postion of vectors matter when calling function cross(up, normal)
 */
t_mat4	tbn_matrix(t_tuple normal)
{
	t_tuple	tangent;
	t_tuple	bitangent;
	t_tuple	up;

	normal = vector_normalize(normal);
	up = vector(0, 1, 0);
	if (fabs(vector_dot_product(up, normal)) >= 0.99)
		up = vector(1, 0, 0);
	tangent = vector_cross_product(up, normal);
	tangent = vector_normalize(tangent);
	bitangent = vector_cross_product(normal, tangent);
	bitangent = vector_normalize(bitangent);
	return (
		(t_mat4){{
			{tangent.x, bitangent.x, normal.x, 0},
			{tangent.y, bitangent.y, normal.y, 0},
			{tangent.z, bitangent.z, normal.z, 0},
			{0, 0, 0, 1},
		}});
}

t_tuple	normal_at(t_obj *obj, t_tuple world_point)
{
	t_tuple	local_point;
	t_tuple	local_normal;
	t_tuple	map_normal;
	t_tuple	world_normal;

	local_point = matrix_tuple_mult(obj->inverse_transform, world_point);
	local_normal = obj->local_normal_at(local_point);
	if (obj->material.normalmap != NULL)
	{
		map_normal = get_normal_from_map(obj->material.normalmap, \
											obj->mapping_func(local_point));
		local_normal = matrix_tuple_mult(tbn_matrix(local_normal), map_normal);
		local_normal = vector_normalize(local_normal);
	}
	world_normal = matrix_tuple_mult(\
				matrix_transpose(obj->inverse_transform), local_normal);
	world_normal.w = 0;
	return (vector_normalize(world_normal));
}

/*
 * r = in - (normal * 2 * (in . normal))
*/
t_tuple	reflect(t_tuple v_in, t_tuple normal)
{
	t_tuple	temp;

	temp = tuple_scalar_mult(normal, 2 * vector_dot_product(v_in, normal));
	return (tuple_subtract(v_in, temp));
}

void	add_light_to_world(t_world *w, t_light *light)
{
	ft_lstadd_back(&w->lights, ft_lstnew(light));
}

t_light	*point_light(t_color color, t_tuple position, double ratio)
{
	t_light	*new_light;

	new_light = malloc(sizeof(t_light));
	new_light->intensity = color_scalar_mult(color, ratio);
	new_light->position = position;
	return (new_light);
}
