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

t_point2d	spherical_map(t_tuple point3d)
{
	return ((t_point2d){0, 0});
}
