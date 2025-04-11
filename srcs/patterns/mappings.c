/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:24:06 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/10 18:30:56 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>
/*
 * A series of functions to find map a 3d point(xyz) to a 2d point(uv)
 * for various object types
 */

double	ft_mod(double x, double n);

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

// NOTE: how to properly modulo negative numbers (fmod(fmod(x, 1) + 1), 1)
// -3.7 mod 1 = - 0.7 + 1 = 1.3 mod 1 = 0.3
t_point2d	cylindrical_map(t_tuple p)
{
	double		theta;
	double		raw_u;
	t_point2d	p2d;

	theta = atan2(p.x, p.z);
	raw_u = theta / (2 * M_PI);
	p2d.u = 1 - (raw_u + 0.5);
	p2d.v = ft_mod(p.y, 1.0);
	return (p2d);
}

t_point2d	planar_map(t_tuple p)
{
	return ((t_point2d){
		ft_mod(p.x, 1),
		ft_mod(p.z, 1)
	});
}

// proper way to doing modulo for negative numbers
double	ft_mod(double x, double n)
{
	return (fmod(fmod(x, n) + n, n));
}
