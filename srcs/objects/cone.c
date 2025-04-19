/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:33:42 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/19 23:34:59 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "raytracing.h"
#include <math.h>

static void	cone_intersect_caps(t_obj *cone, t_ray ray, t_list **list)
{
	double	t;

	t = (get_cone_min(cone->type) - ray.origin.y) / ray.direction.y;
	if (cone_check_caps(ray, t, get_cone_min(cone->type)))
		add_to_intersections(t, cone, list);
	t = (CONE_MAX - ray.origin.y) / ray.direction.y;
	if (cone_check_caps(ray, t, CONE_MAX))
		add_to_intersections(t, cone, list);
}

/* when a is 0 it means the ray is parallel to one of cone halves,
 * which might have 1 intersection. unless b is also 0 then there would 
 * be no intersection */
void	cone_intersect(t_obj *cone, t_ray ray, t_list **list)
{
	double	a;
	double	b;
	double	c;
	double	roots[2];

	a = sq(ray.direction.x) - sq(ray.direction.y) + sq(ray.direction.z);
	b = (2 * ray.origin.x * ray.direction.x)
		- (2 * ray.origin.y * ray.direction.y)
		+ (2 * ray.origin.z * ray.direction.z);
	c = sq(ray.origin.x) - sq(ray.origin.y) + sq(ray.origin.z);
	if (!solve_quadratic(a, b, c, roots))
		return ;
	if (check_bounds(roots[0], ray, CONE_MAX, get_cone_min(cone->type)))
		add_to_intersections(roots[0], cone, list);
	if (check_bounds(roots[1], ray, CONE_MAX, get_cone_min(cone->type)))
		add_to_intersections(roots[1], cone, list);
	cone_intersect_caps(cone, ray, list);
}

t_tuple	cone_normal_at(t_tuple point)
{
	double	y;
	double	dist;

	dist = pow(point.x, 2) + pow(point.z, 2);
	if (dist < 1 && point.y >= CONE_MAX - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && point.y <= CONE_MIN + EPSILON)
		return (vector(0, -1, 0));
	y = sqrt(sq(point.x) + sq(point.z));
	if (point.y > 0)
		y = y * -1;
	return (vector(point.x, y, point.z));
}

t_tuple	dcone_normal_at(t_tuple point)
{
	double	y;
	double	dist;

	dist = sq(point.x) + sq(point.z);
	if (dist < 1 && point.y >= CONE_MAX - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && point.y <= DCONE_MIN + EPSILON)
		return (vector(0, -1, 0));
	if (equal(dist, 0))
		return (vector(0, 0, 1));
	y = sqrt(dist);
	if (point.y > 0)
		y = y * -1;
	return (vector(point.x, y, point.z));
}

t_obj	*cone(void)
{
	t_obj	*new_cone;

	new_cone = new_obj();
	new_cone->type = OBJ_CONE;
	new_cone->local_intersect = &cone_intersect;
	new_cone->local_normal_at = &cone_normal_at;
	new_cone->mapping_func = &cylindrical_map;
	new_cone->material.def_checkers = bw_uv_checkers(20, 4);
	new_cone->material.def_checkers->mapping_func = &cylindrical_map;
	return (new_cone);
}
