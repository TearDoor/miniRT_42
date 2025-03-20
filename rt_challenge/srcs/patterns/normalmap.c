/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:07:09 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/20 15:54:51 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "rays.h"
#include <math.h>

t_tuple	color_to_normal(t_color clr)
{
	double	x;
	double	y;
	double	z;

	x = (clr.r * 2.0) - 1.0;
	y = (clr.g * 2.0) - 1.0;
	z = (clr.b * 2.0) - 1.0;
	return (vector(x, y, z));
}

t_tuple	get_normal_from_map(t_canvas *cvs, t_point2d uv)
{
	double	x;
	double	y;
	t_color	normal_as_color;

	uv.v = 1 - uv.v;
	x = uv.u * (cvs->width - 1);
	y = uv.v * (cvs->height - 1);
	normal_as_color = cvs->pixels[(int)round(y)][(int)round(x)];
	return (color_to_normal(normal_as_color));
}

void	set_normal_from_file(t_obj *obj, char *filename)
{
	obj->material.normalmap = parse_map(filename);
}
