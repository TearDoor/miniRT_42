/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:22:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/05 22:25:34 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "raytracing.h"
#include <stdio.h>

static t_color	shade_hit(t_world world, t_comps comp)
{
	t_lightparams	params;
	t_color			final_color;
	t_list			*lights_node;
	t_light			*light;

	final_color = color(0, 0, 0);
	params.m = comp.obj->material;
	params.obj = comp.obj;
	params.point = comp.over_point;
	params.eye_vec = comp.eyev;
	params.normal_vec = comp.normalv;
	lights_node = world.lights;
	while (lights_node)
	{
		light = (t_light *)lights_node->content;
		params.in_shadow = is_shadowed(world, comp.over_point, light);
		params.light = *light;
		final_color = color_add(final_color, lighting(params));
		lights_node = lights_node->next;
	}
	return (final_color);
}

static t_comps	prepare_computations(t_intersect *i, t_ray r)
{
	t_comps	comps;

	comps.t = i->t;
	comps.obj = i->obj;
	comps.point = position(r, comps.t);
	comps.eyev = tuple_negate(r.direction);
	comps.normalv = normal_at(comps.obj, comps.point);
	if (vector_dot_product(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = tuple_negate(comps.normalv);
	}
	else
		comps.inside = 0;
	comps.over_point = tuple_add(comps.point, \
							tuple_scalar_mult(comps.normalv, EPSILON));
	return (comps);
}

t_color	color_at(t_world w, t_ray r)
{
	t_list		*intersections;
	t_intersect	*hit;
	t_comps		comp;

	intersections = intersect_world(r, w);
	hit = checkhit(intersections);
	if (!hit)
	{
		ft_lstclear(&intersections, free);
		return (color(0, 0, 0));
	}
	comp = prepare_computations(hit, r);
	ft_lstclear(&intersections, free);
	return (shade_hit(w, comp));
}
