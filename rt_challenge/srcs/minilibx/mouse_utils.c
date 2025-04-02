/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:31:09 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/02 22:39:36 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include "minirt.h"

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

double	calculate_plane_intersection(t_camera cam, t_ray ray, t_tuple obj_pos)
{
	t_tuple	plane_normal;
	t_tuple	plane_point;

	plane_point = obj_pos;

}

void	move_object(t_rt *rt, int x, int y)
{
	t_ray	select_ray;
	t_tuple	curr_pos;
	t_tuple	new_pos;
	double	t;

	select_ray = ray_for_pixel(rt->cam, x, y);
	curr_pos = get_obj_position(rt->mouse.held_obj);
	t = calculate_plane_intersection(rt->cam, select_ray, curr_pos);
}
