/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:57:51 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/26 17:55:00 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>

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

t_color	lighting(t_material m, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_color	effective_color;
	t_tuple	lightv;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_tuple	reflectv;
	double	reflect_dot_eye;

	effective_color = color_mult(m.color, light.intensity);
	lightv = vector_normalize(tuple_subtract(light.position, point));
	ambient = color_scalar_mult(effective_color, m.ambient);
	if (vector_dot_product(lightv, normalv) < 0)
	{
		diffuse = (t_color){0, 0, 0};
		specular = (t_color){0, 0, 0};
	}
	else
	{
		diffuse = color_scalar_mult(effective_color, m.diffuse);
		diffuse = color_scalar_mult(diffuse, vector_dot_product(lightv, normalv));
		reflectv = reflect(tuple_negate(lightv), normalv);
		reflect_dot_eye = vector_dot_product(reflectv, eyev);
		if (reflect_dot_eye < 0)
			specular = (t_color){0, 0, 0};
		else
		{
			specular = color_scalar_mult(light.intensity, m.specular);
			specular = color_scalar_mult(specular, pow(reflect_dot_eye, m.shininess));
		}
	}
	return (color_add(ambient, color_add(diffuse, specular)));
}
