/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:59:21 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/06 21:14:00 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>

static void	cylinder_intersect(t_obj cyl, t_ray ray, t_list **list)
{
	double	a;
	double	b;
	double	c;
	double	roots[2];

	a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (fabs(a) < EPSILON)
	{
		cyl_intersect_caps(cyl, ray, list);
		return ;
	}
	b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
	c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	if (!solve_quadratic(a, b, c, roots))
		return ;
	if (check_bounds(roots[0], ray, CYL_MAX, CYL_MIN))
		lstadd_sorted(list, ft_lstnew(intersection(roots[0], cyl)), &lstcmp_xs);
	if (check_bounds(roots[1], ray, CYL_MAX, CYL_MIN))
		lstadd_sorted(list, ft_lstnew(intersection(roots[1], cyl)), &lstcmp_xs);
	cyl_intersect_caps(cyl, ray, list);
}

/* if cylinder side (not end cap)
 * normal of cylinder at a point on cylinder is
 * point - center (ignore y value) */
static t_tuple	cylinder_normal_at(t_tuple point)
{
	double	dist;

	dist = pow(point.x, 2) + pow(point.z, 2);
	if (dist < 1 && point.y >= CYL_MAX - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && point.y <= CYL_MIN + EPSILON)
		return (vector(0, -1, 0));
	else
		return (vector(point.x, 0, point.z));
}

/* using a base cylinder (center at 0,0,0; height 1 radius 1 */
t_obj	*cylinder(void)
{
	t_obj	*new_cyl;

	new_cyl = new_obj();
	new_cyl->type = OBJ_CYL;
	new_cyl->local_intersect = &cylinder_intersect;
	new_cyl->local_normal_at = &cylinder_normal_at;
	return (new_cyl);
}
