/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_pattern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:26:14 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/11 17:04:23 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>

// Returns the color at coordinates (u, v) for a given 2d pattern
t_color	uv_pattern_at(t_uv_pattern *uv_patt, double u, double v)
{
	int	u2;
	int	v2;

	u2 = floor(u * uv_patt->width);
	v2 = floor(v * uv_patt->height);
	if ((u2 + v2) % 2 == 0)
		return (uv_patt->a);
	else
		return (uv_patt->b);
}

/*
* Finds the corresponding 2d coordinates (u, v) 
* of a 3d point(x,y,z) on a sphere
*/
t_point2d	spherical_map(t_tuple p)
{
	double		theta;
	double		radius;
	double		phi;
	double		raw_u;
	t_point2d	p2d;

	theta = atan2(p.x, p.z);
	radius = vector_magnitude(vector(p.x, p.y, p.z));
	phi = acos(p.y / radius);
	raw_u = theta / (2 * M_PI);
	p2d.u = 1 - (raw_u + 0.5);
	p2d.v = 1 - phi / M_PI;
	return (p2d);
}
