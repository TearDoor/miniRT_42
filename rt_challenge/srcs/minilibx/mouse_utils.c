/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:31:09 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/03 20:15:10 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "objects.h"
#include "raytracing.h"
#include "minirt.h"
#include "utils.h"
#include <math.h>

t_obj	*pick_object(t_rt *rt, int x, int y)
{
	t_ray		ray;
	t_list		*intersects;
	t_intersect	*hit;
	t_obj		*hit_object;

	ray = ray_for_pixel(rt->cam, x, y);
	intersects = intersect_world(ray, rt->world);
	hit = checkhit(intersects);
	if (hit)
		hit_object = hit->obj;
	else
		hit_object = NULL;
	ft_lstclear(&intersects, free);
	return (hit_object);
}

t_tuple	get_obj_position(t_obj *obj)
{
	t_tuple	pos;

	pos = point(obj->transform.mat[0][3], \
				obj->transform.mat[1][3], \
				obj->transform.mat[2][3]);
	return (pos);
}

t_tuple	get_cam_forward(t_camera cam)
{
	t_tuple	dir;

	dir = vector(
			cam.transform.mat[2][0],
			cam.transform.mat[2][1],
			cam.transform.mat[2][2]);
	dir = tuple_negate(dir);
	return (vector_normalize(dir));
}

double	calculate_plane_intersection(t_camera cam, t_ray ray, t_tuple obj_pos)
{
	t_tuple	plane_normal;
	t_tuple	plane_point;
	double	denominator;
	double	t;

	plane_normal = get_cam_forward(cam);
	plane_point = obj_pos;
	denominator = vector_dot_product(ray.direction, plane_normal);
	t = vector_dot_product(tuple_subtract(plane_point, ray.origin), \
						plane_normal) / denominator;
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
	t = calculate_plane_intersection(rt->cam, select_ray, curr_pos);
	new_pos = position(select_ray, t);
	delta = tuple_subtract(new_pos, curr_pos);
	apply_transform(rt->mouse.held_obj, delta_vector_translate(delta));
}
