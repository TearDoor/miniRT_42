/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:26:17 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/24 20:22:07 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include <math.h>

/* point = ray.origin + t * ray.direction 
 * assuming a horizontal plane on xz where y = 0
 * 0 (point.y) = ray.origin.y + t * ray.direction.y 
 * t = - ray.origin.y / ray.direction.y */
static void	plane_intersection(t_obj *pl, t_ray ray, t_list **list)
{
	double	t;

	if (fabs(ray.direction.y) < EPSILON)
		return ;
	t = -ray.origin.y / ray.direction.y;
	add_to_intersections(t, pl, list);
}

static t_tuple	plane_normal_at(t_tuple local_point)
{
	(void)local_point;
	return (vector(0, 1, 0));
}

t_obj	*plane(void)
{
	t_obj	*new_plane;

	new_plane = new_obj();
	new_plane->type = OBJ_PLANE;
	new_plane->local_normal_at = &plane_normal_at;
	new_plane->local_intersect = &plane_intersection;
	new_plane->mapping_func = &planar_map;
	return (new_plane);
}
