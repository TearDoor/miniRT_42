/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:24:06 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/14 21:17:21 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>
/*
 * A series of functions to find the 2d point (u,v) given
 * a 3d point(x, y, z) different for each shape
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

t_point2d	cylindrical_map(t_tuple p)
{
	double		theta;
	double		raw_u;
	t_point2d	p2d;

	theta = atan2(p.x, p.z);
	raw_u = theta / (2 * M_PI);
	p2d.u = 1 - (raw_u + 0.5);
	p2d.v = fmod(p.y, 1.0);
	return (p2d);
}

t_point2d	cone_map(t_tuple p)
{
	double		theta;
	double		horizontal_dist;
	double		raw_u;
	t_point2d	p2d;

	theta = atan2(p.x, p.z);
	horizontal_dist = sqrt(sq(p.x) + sq(p.z));
	raw_u = theta / (2 * M_PI);
	p2d.u = 1 - (raw_u + 0.5);
	p2d.v = p.y;
	return (p2d);
}
