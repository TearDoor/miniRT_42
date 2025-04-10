/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:24:06 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/10 17:30:39 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>
/*
 * A series of functions to find map a 3d point(xyz) to a 2d point(uv)
 * for various object types
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

// NOTE: Hacky way of ensuring fmod is positive (fmod(fmod(x, 1) + 1), 1)
// -3.7 mod 1 = - 0.7 + 1 = 1.7 mod 1 = 0.7
t_point2d	cylindrical_map(t_tuple p)
{
	double		theta;
	double		raw_u;
	t_point2d	p2d;

	theta = atan2(p.x, p.z);
	raw_u = theta / (2 * M_PI);
	p2d.u = 1 - (raw_u + 0.5);
	p2d.v = fmod(fmod(p.y, 1.0) + 1, 1);
	return (p2d);
}

t_point2d	planar_map(t_tuple p)
{
	return ((t_point2d){
		fmod(fmod(p.x, 1) + 1, 1),
		fmod(fmod(p.z, 1) + 1, 1)
	});
}
