/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:44:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/29 14:50:57 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "rays.h"
#include <math.h>

static t_color	diffuse_calc(t_lightparams params, \
							t_tuple lightv, t_color eff_color)
{
	double	diffuse_ratio;

	diffuse_ratio = params.m.diffuse * \
					vector_dot_product(lightv, params.normal_vec);
	return (color_scalar_mult(eff_color, diffuse_ratio));
}

static t_color	specular_calc(t_lightparams params, t_tuple lightv)
{
	t_tuple	reflectv;
	double	refl_dot_eye;
	double	reflect_ratio;

	reflectv = reflect(tuple_negate(lightv), params.normal_vec);
	refl_dot_eye = vector_dot_product(reflectv, params.eye_vec);
	if (refl_dot_eye < 0)
		return (color(0, 0, 0));
	else
	{
		reflect_ratio = params.m.specular * \
						pow(refl_dot_eye, params.m.shininess);
		return (color_scalar_mult(params.light.intensity, reflect_ratio));
	}
}

t_color	lighting(t_lightparams params)
{
	t_color	effective_color;
	t_tuple	lightv;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;

	effective_color = color_mult(params.m.color, params.light.intensity);
	lightv = tuple_subtract(params.light.position, params.point);
	lightv = vector_normalize(lightv);
	ambient = color_scalar_mult(effective_color, params.m.ambient);
	if (vector_dot_product(lightv, params.normal_vec) < 0)
		return (ambient);
	specular = specular_calc(params, lightv);
	diffuse = diffuse_calc(params, lightv, effective_color);
	return (color_add(ambient, color_add(diffuse, specular)));
}

t_color	shade_hit(t_world world, t_comps comp)
{
	t_lightparams	params;

	params.m = comp.obj.material;
	params.light = world.light;
	params.point = comp.point;
	params.eye_vec = comp.eyev;
	params.normal_vec = comp.normalv;
	return (lighting(params));
}

t_comps	prepare_computations(t_intersect *i, t_ray r)
{
	t_comps	new;

	new.t = i->t;
	new.obj = i->obj;
	new.point = position(r, new.t);
	new.eyev = tuple_negate(r.direction);
	new.normalv = normal_at(i->obj, new.point);
	if (vector_dot_product(new.normalv, new.eyev) < 0)
	{
		new.inside = 1;
		new.normalv = tuple_negate(new.normalv);
	}
	else
		new.inside = 0;
	return (new);
}

t_color	color_at(t_world w, t_ray r)
{
	t_list		*intersections;
	t_intersect	*hit;
	t_comps		comp;

	intersections = intersect_world(r, w);
	hit = checkhit(intersections);
	if (!hit)
		return (color(0, 0, 0));
	comp = prepare_computations(hit, r);
	return (shade_hit(w, comp));
}
