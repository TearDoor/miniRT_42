/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:59:21 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/05 22:21:18 by tkok-kea         ###   ########.fr       */
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
		return ;
	b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
	c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	if (!solve_quadratic(a, b, c, roots))
		return ;
	lstadd_sorted(list, ft_lstnew((void *)intersection(roots[0], cyl)), \
					&lstcmp_xs);
	lstadd_sorted(list, ft_lstnew((void *)intersection(roots[1], cyl)), \
					&lstcmp_xs);
}

t_tuple	cylinder_normal(t_tuple point)
{
	return (vector(point.x, 0, point.z));
}

t_obj	*cylinder(void)
{
	t_obj	*new_cyl;

	new_cyl = new_obj();
	new_cyl->type = OBJ_CYL;
	new_cyl->local_intersect = &cylinder_intersect;
	new_cyl->local_normal_at = &cylinder_normal;
	return (new_cyl);
}
