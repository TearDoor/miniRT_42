/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:22:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/07 16:51:26 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

static t_color	shade_hit(t_world world, t_comps comp)
{
	t_lightparams	params;
	uint64_t startime, shadow_time;

	params.m = comp.obj.material;
	params.light = world.light;
	params.point = comp.over_point;
	params.eye_vec = comp.eyev;
	params.normal_vec = comp.normalv;
	startime = curr_time();
	params.in_shadow = is_shadowed(world, comp.over_point);
	shadow_time = curr_time() - startime;
	*world.total_inter += shadow_time;
	return (lighting(params));
}

static t_comps	prepare_computations(t_intersect *i, t_ray r)
{
	t_comps	comps;

	comps.t = i->t;
	comps.obj = i->obj;
	comps.point = position(r, comps.t);
	comps.eyev = tuple_negate(r.direction);
	comps.normalv = normal_at(i->obj, comps.point);
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
	uint64_t	start_time, inter_time;

	start_time = curr_time();
	intersections = intersect_world(r, w);
	hit = checkhit(intersections);
	inter_time = curr_time() - start_time;
	*w.total_inter += inter_time;
	if (!hit)
		return (color(0, 0, 0));
	start_time = curr_time();
	comp = prepare_computations(hit, r);
	ft_lstclear(&intersections, free);
	return (shade_hit(w, comp));
}
