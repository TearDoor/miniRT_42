/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:33:42 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/07 21:13:08 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>

/* a cone's radius at any given y is the absolute value of that y */
static int	cone_check_caps(t_ray ray, double t, double y)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (pow(x, 2) + pow(z, 2) <= fabs(y));
}

void	cone_intersect_caps(t_obj cone, t_ray ray, t_list **list)
{
	double	t;

	t = (CONE_MIN - ray.origin.y) / ray.direction.y;
	if (cone_check_caps(ray, t, CONE_MIN))
		add_to_intersections(t, cone, list);
	t = (CONE_MAX - ray.origin.y) / ray.direction.y;
	if (cone_check_caps(ray, t, CONE_MAX))
		add_to_intersections(t, cone, list);
}

/* when a is 0 it means the ray is parallel to one of cone halves,
 * which might have 1 intersection. unless b is also 0 then there would 
 * be no intersection */
void	cone_intersect(t_obj cone, t_ray ray, t_list **list)
{
	double	a;
	double	b;
	double	c;
	double	roots[2];

	a = sq(ray.direction.x) - sq(ray.direction.y) + sq(ray.direction.z);
	b = (2 * ray.origin.x * ray.direction.x) - \
		(2 * ray.origin.y * ray.direction.y) + \
		(2 * ray.origin.z * ray.direction.z);
	c = sq(ray.origin.x) - sq(ray.origin.y) + sq(ray.origin.z);
	if (equal(a, 0))
	{
		if (equal(b, 0))
			return ;
		else
			add_to_intersections(-c / (2 * b), cone, list);
	}
	else if (!solve_quadratic(a, b, c, roots))
		return ;
	if (check_bounds(roots[0], ray, CONE_MAX, CONE_MIN))
		add_to_intersections(roots[0], cone, list);
	if (check_bounds(roots[1], ray, CONE_MAX, CONE_MIN))
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

t_obj	*cone(void)
{
	t_obj	*new_cone;

	new_cone = new_obj();
	new_cone->type = OBJ_CONE;
	new_cone->local_intersect = &cone_intersect;
	new_cone->local_normal_at = &cone_normal_at;
	return (new_cone);
}
