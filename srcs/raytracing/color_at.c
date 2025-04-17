/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:22:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/17 22:03:11 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "raytracing.h"
#include <math.h>

static t_color	calculate_final_color(t_world *world, t_lightparams params)
{
	t_list	*lights_node;
	t_light	*light;
	t_color	final_color;

	final_color = color_mult(world->ambient, params.m.color);
	lights_node = world->lights;
	while (lights_node)
	{
		light = (t_light *)lights_node->content;
		if (light->on == 1)
		{
			params.in_shadow = is_shadowed(*world, params.point, light);
			params.light = *light;
			final_color = color_add(final_color, lighting(params));
		}
		lights_node = lights_node->next;
	}
	return (final_color);
}

/*
 * fires a ray from the surface of obj along the reflect vector
 * has a remaining argument to prevent infinite recursion
 * if two surfaces are parallel to each other
*/
t_color	reflected_color(const t_world *w, const t_comps *comps, int remaining)
{
	t_ray	reflect_ray;
	t_color	refl_color;

	if (equal(comps->obj->material.reflective, 0.0) || remaining == 0)
		return (color(0, 0, 0));
	reflect_ray = ray(comps->over_point, comps->reflectv);
	refl_color = color_at(*w, reflect_ray, remaining - 1);
	return (color_scalar_mult(refl_color, comps->obj->material.reflective));
}

/*
 * approximation of the Fresnel effect
 * (where steep angle = weak reflection; shallow angle = strong reflection)
 * calculates reflectance which is the ratio of reflected vs refracted light
 */
double	schlick(t_comps *comps)
{
	double	cos;
	double	n;
	double	sin2_t;
	double	cos_t;
	double	r0;

	cos = vector_dot_product(comps->eyev, comps->normalv);
	if (comps->n1 > comps->n2)
	{
		n = comps->n1 / comps->n2;
		sin2_t = sq(n) * (1.0 - sq(cos));
		if (sin2_t > 1.0)
			return (1.0);
		cos_t = sqrt(1.0 - sin2_t);
		cos = cos_t;
	}
	r0 = sq((comps->n1 - comps->n2) / (comps->n1 + comps->n2));
	return (r0 + (1 - r0) * pow((1 - cos), 5));
}

/*
 * Snell's law to calculate reflected color under total internal reflection
*/
t_color	refracted_color(const t_world *w, const t_comps *comps, int remaining)
{
	double	n_ratio;
	double	cos_i;
	double	sin2_t;
	double	cos_t;
	t_tuple	direction;
	t_ray	refract_ray;
	t_color	refr_color;

	if (equal(comps->obj->material.transparency, 0.0) || remaining == 0)
		return (color(0, 0, 0));
	n_ratio = comps->n1 / comps->n2;
	cos_i = vector_dot_product(comps->eyev, comps->normalv);
	sin2_t = sq(n_ratio) * (1 - sq(cos_i));
	if (sin2_t > 1)
		return (color(0, 0, 0));
	cos_t = sqrt(1.0 - sin2_t);
	direction = tuple_scalar_mult(comps->normalv, n_ratio * cos_i - cos_t);
	direction = tuple_subtract(direction, tuple_scalar_mult(comps->eyev, n_ratio));
	refract_ray = ray(comps->under_point, direction);
	refr_color = color_at(*w, refract_ray, remaining - 1);
	return (color_scalar_mult(refr_color, comps->obj->material.transparency));
}

static t_color	shade_hit(t_world world, t_comps comp, int remaining)
{
	t_lightparams	params;
	t_color			surface_color;
	t_color			reflect_color;
	t_color			refract_color;
	double			reflectance;

	params.m = comp.obj->material;
	params.obj = comp.obj;
	params.point = comp.over_point;
	params.eye_vec = comp.eyev;
	params.normal_vec = comp.normalv;
	if (params.m.pattern != NULL)
		params.m.color = pattern_at_shape(params.m.pattern,
				params.obj, params.point);
	surface_color = calculate_final_color(&world, params);
	reflect_color = reflected_color(&world, &comp, remaining);
	refract_color = refracted_color(&world, &comp, remaining);
	if (params.m.reflective > 0 && params.m.transparency > 0)
	{
		reflectance = schlick(&comp);
		reflect_color = color_scalar_mult(reflect_color, reflectance);
		refract_color = color_scalar_mult(refract_color, (1 - reflectance));
		return (color_add(color_add(surface_color, reflect_color), refract_color));
	}
	else
		return (color_add(color_add(surface_color, reflect_color), refract_color));
}

static t_comps	prepare_computations(t_intersect *hit, t_ray r, t_list *xs)
{
	t_comps	comps;

	comps.t = hit->t;
	comps.obj = hit->obj;
	comps.point = position(r, comps.t);
	comps.eyev = tuple_negate(r.direction);
	comps.normalv = normal_at(comps.obj, comps.point);
	comps.reflectv = reflect(r.direction, comps.normalv);
	if (vector_dot_product(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = tuple_negate(comps.normalv);
	}
	else
		comps.inside = 0;
	comps.over_point = tuple_add(comps.point,
			tuple_scalar_mult(comps.normalv, EPSILON));
	comps.under_point = tuple_subtract(comps.point,
			tuple_scalar_mult(comps.normalv, EPSILON));
	calculate_n(hit, &comps, xs);
	return (comps);
}

t_color	color_at(t_world w, t_ray r, int remaining)
{
	t_list		*intersections;
	t_intersect	*hit;
	t_comps		comp;

	intersections = intersect_world(r, w);
	hit = checkhit(intersections);
	if (!hit)
	{
		ft_lstclear(&intersections, free);
		return (w.ambient);
	}
	comp = prepare_computations(hit, r, intersections);
	ft_lstclear(&intersections, free);
	return (shade_hit(w, comp, remaining));
}
