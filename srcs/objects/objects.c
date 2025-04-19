/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:54 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/19 23:36:30 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static t_material	default_material(void)
{
	return ((t_material){
		.color = (t_color){0.7, 0.7, 0.7},
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200,
		.reflective = 0.0,
		.transparency = 0.0,
		.refractive_index = 1.0,
		.cast_shadow = 1,
		.pattern = NULL,
		.image = NULL,
		.normalmap = NULL,
		.def_checkers = NULL,
	});
}

t_obj	*new_obj(void)
{
	t_obj	*newobj;

	newobj = malloc(sizeof(t_obj));
	newobj->transform = id_matrix();
	newobj->inverse_transform = id_matrix();
	newobj->material = default_material();
	newobj->local_intersect = NULL;
	newobj->local_normal_at = NULL;
	newobj->checkered = -1;
	return (newobj);
}

/* truncates cylinders and cones */
int	check_bounds(double t, t_ray ray, double max, double min)
{
	double	y;

	y = ray.origin.y + t * ray.direction.y;
	return ((y > min) && (y < max));
}

void	apply_transform(t_obj *o, t_mat4 m)
{
	if (o == NULL)
		return ;
	o->transform = matrix_mult(m, o->transform);
	o->inverse_transform = matrix_invert(o->transform);
}

void	free_object(void *ptr)
{
	t_obj	*obj;

	obj = (t_obj *)ptr;
	if (obj->material.image != NULL)
	{
		free_canvas(*obj->material.image);
		free(obj->material.image);
	}
	if (obj->material.normalmap != NULL)
	{
		free_canvas(*obj->material.normalmap);
		free(obj->material.normalmap);
	}
	if (obj->material.pattern != NULL)
		free(obj->material.pattern);
	if (obj->material.def_checkers != NULL)
		free(obj->material.def_checkers);
	free(obj);
}
