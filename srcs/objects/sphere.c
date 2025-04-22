/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:39:54 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/19 23:44:55 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "raytracing.h"

static void	line_sphere_intersection(t_obj *obj, t_ray ray, t_list **list)
{
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;
	double	roots[2];

	sphere_to_ray = tuple_subtract(ray.origin, point(0, 0, 0));
	a = vector_dot_product(ray.direction, ray.direction);
	b = 2 * vector_dot_product(ray.direction, sphere_to_ray);
	c = vector_dot_product(sphere_to_ray, sphere_to_ray) - 1;
	if (!solve_quadratic(a, b, c, roots))
		return ;
	add_to_intersections(roots[0], obj, list);
	add_to_intersections(roots[1], obj, list);
}

/* normal of a point on a sphere is 
 * the vector from the sphere's origin to the point (point - origin)
 * since we assume a unit sphere (origin at 0,0,0) we can just return
 * the point (but w is 0 instead of 1 because it is a vector)*/
static t_tuple	sphere_normal_at(t_tuple local_point)
{
	return (vector(local_point.x, local_point.y, local_point.z));
}

t_obj	*sphere(void)
{
	t_obj	*new;

	new = new_obj();
	new->type = OBJ_SPHERE;
	new->local_intersect = &line_sphere_intersection;
	new->local_normal_at = &sphere_normal_at;
	new->mapping_func = &spherical_map;
	new->material.def_checkers = bw_uv_checkers(20, 10);
	new->material.def_checkers->mapping_func = &spherical_map;
	return (new);
}
