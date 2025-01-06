/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:21:38 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/06 15:40:32 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>

static int	check_caps(t_ray ray, double t);

/* finds the intersection of the ray with whole plane where
 * the top and bottom caps reside (plane_intersect)
 * check_cap checks if the intersection falls within radius of cylinder */
void	cyl_intersect_caps(t_obj cyl, t_ray ray, t_list **list)
{
	double	t;

	t = (CYL_MIN - ray.origin.y) / ray.direction.y;
	if (check_caps(ray, t))
		lstadd_sorted(list, ft_lstnew(intersection(t, cyl)), &lstcmp_xs);
	t = (CYL_MAX - ray.origin.y) / ray.direction.y;
	if (check_caps(ray, t))
		lstadd_sorted(list, ft_lstnew(intersection(t, cyl)), &lstcmp_xs);
}

static int	check_caps(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (pow(x, 2) + pow(z, 2) <= 1);
}
