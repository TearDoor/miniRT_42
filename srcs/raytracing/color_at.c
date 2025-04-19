/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:22:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/19 21:49:22 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "raytracing.h"

static t_color	total_surface_color(t_world *world, t_lightparams params)
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

static t_color	apply_fresnel(t_comps *comps,
							t_color surface, t_color reflect, t_color refract)
{
	double	reflectance;

	reflectance = schlick(comps);
	reflect = color_scalar_mult(reflect, reflectance);
	refract = color_scalar_mult(refract, (1 - reflectance));
	return (color_add(color_add(surface, reflect), refract));
}

static t_color	shade_hit(t_world world, t_comps comp, int remaining)
{
	t_lightparams	params;
	t_color			surface_color;
	t_color			reflect_color;
	t_color			refract_color;

	params.m = comp.obj->material;
	params.obj = comp.obj;
	params.point = comp.over_point;
	params.eye_vec = comp.eyev;
	params.normal_vec = comp.normalv;
	if (params.m.pattern != NULL)
		params.m.color = pattern_at_shape(params.m.pattern,
				params.obj, params.point);
	surface_color = total_surface_color(&world, params);
	reflect_color = reflected_color(&world, &comp, remaining);
	refract_color = refracted_color(&world, &comp, remaining);
	if (params.m.reflective > 0 && params.m.transparency > 0)
		return (apply_fresnel(&comp, surface_color, reflect_color,
				refract_color));
	else
		return (color_add(color_add(surface_color, reflect_color),
				refract_color));
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
