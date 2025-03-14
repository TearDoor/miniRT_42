/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_pattern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:26:14 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/14 21:49:57 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>

// Returns the color at coordinates (u, v) for a given 2d pattern
t_color	uv_checker_pattern_at(const t_pattern *patt, t_point2d uv)
{
	t_uv_pattern	*uv_patt;
	int				u2;
	int				v2;

	uv_patt = (t_uv_pattern *)patt;
	u2 = floor(uv.u * uv_patt->width);
	v2 = floor(uv.v * uv_patt->height);
	if ((u2 + v2) % 2 == 0)
		return (uv_patt->a);
	else
		return (uv_patt->b);
}

t_color	pattern_at_3d_to_2d(const t_pattern *patt, t_tuple p)
{
	t_point2d		uv_point;
	t_uv_pattern	*uv_patt;

	uv_patt = (t_uv_pattern *)patt;
	uv_point = patt->mapping_func(p);
	return (uv_patt->uv_pattern_at(patt, uv_point));
}

/*
 * width to height ratios for nice square checkerboard patterns
 * sphere 2 to 1
 * cylinder 16 to 2
 * cone 20 to 1
*/
t_pattern	*uv_checkers(double width, double height, t_color a, t_color b)
{
	t_uv_pattern	*uv_patt;

	uv_patt = malloc(sizeof(t_uv_pattern));
	uv_patt->pattern = init_pattern();
	uv_patt->width = width;
	uv_patt->height = height;
	uv_patt->a = a;
	uv_patt->b = b;
	uv_patt->pattern.pattern_at = &pattern_at_3d_to_2d;
	uv_patt->uv_pattern_at = &uv_checker_pattern_at;
	return ((t_pattern *)uv_patt);
}
