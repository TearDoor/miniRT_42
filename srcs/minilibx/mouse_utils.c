/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:31:09 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/14 18:05:26 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "objects.h"
#include "raytracing.h"
#include "minirt.h"
#include "utils.h"

static t_tuple	get_cam_forward(t_camera cam)
{
	t_tuple	dir;

	dir = vector(
			cam.transform.mat[2][0],
			cam.transform.mat[2][1],
			cam.transform.mat[2][2]);
	dir = tuple_negate(dir);
	return (vector_normalize(dir));
}

t_obj	*pick_object(t_rt *rt, int x, int y)
{
	t_ray		ray;
	t_list		*intersects;
	t_intersect	*hit;
	t_obj		*hit_object;
	t_tuple		hit_pos;

	ray = ray_for_pixel(rt->cam, x, y);
	intersects = intersect_world(ray, rt->world);
	hit = checkhit(intersects);
	if (hit)
	{
		hit_pos = position(ray, hit->t);
		rt->mouse.offset = tuple_subtract(hit_pos, get_obj_position(hit->obj));
		rt->mouse.initial_normal = get_cam_forward(rt->cam);
		rt->mouse.initial_point = hit_pos;
		hit_object = hit->obj;
	}
	else
		hit_object = NULL;
	ft_lstclear(&intersects, free);
	return (hit_object);
}

t_tuple	get_obj_position(t_obj *obj)
{
	t_tuple	pos;

	pos = point(
			obj->transform.mat[0][3],
			obj->transform.mat[1][3],
			obj->transform.mat[2][3]
			);
	return (pos);
}

double	calculate_plane_intersection(t_ray ray, t_tuple normal, t_tuple point)
{
	double	denominator;
	double	t;

	denominator = vector_dot_product(ray.direction, normal);
	t = vector_dot_product(tuple_subtract(point, ray.origin),
			normal) / denominator;
	return (t);
}

void	move_object(t_rt *rt, int x, int y)
{
	t_ray	select_ray;
	t_tuple	curr_pos;
	t_tuple	new_pos;
	t_tuple	delta;
	double	t;

	select_ray = ray_for_pixel(rt->cam, x, y);
	curr_pos = get_obj_position(rt->mouse.held_obj);
	t = calculate_plane_intersection(select_ray,
			rt->mouse.initial_normal, rt->mouse.initial_point);
	new_pos = position(select_ray, t);
	new_pos = tuple_subtract(new_pos, rt->mouse.offset);
	delta = tuple_subtract(new_pos, curr_pos);
	apply_transform(rt->mouse.held_obj, tuple_translate(delta));
}
