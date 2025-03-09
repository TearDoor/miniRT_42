/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:44:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/09 22:19:48 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "utils.h"
#include "rays.h"
#include <math.h>

static t_color	diffuse_calc(t_lightparams params, \
							t_tuple lightv, t_color eff_color)
{
	double	diffuse_ratio;

	diffuse_ratio = params.m.diffuse * \
					vector_dot_product(lightv, params.normal_vec);
	return (color_scalar_mult(eff_color, diffuse_ratio));
}

static t_color	specular_calc(t_lightparams params, t_tuple lightv)
{
	t_tuple	reflectv;
	double	refl_dot_eye;
	double	reflect_ratio;

	reflectv = reflect(tuple_negate(lightv), params.normal_vec);
	refl_dot_eye = vector_dot_product(reflectv, params.eye_vec);
	if (refl_dot_eye < 0)
		return (color(0, 0, 0));
	else
	{
		reflect_ratio = params.m.specular * \
						pow(refl_dot_eye, params.m.shininess);
		return (color_scalar_mult(params.light.intensity, reflect_ratio));
	}
}

t_color	lighting(t_lightparams params)
{
	t_color	effective_color;
	t_tuple	lightv;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;

	if (params.m.pattern != NULL)
		params.m.color = pattern_at_shape(params.m.pattern, \
											&params.obj, params.point);
	effective_color = color_mult(params.m.color, params.light.intensity);
	ambient = color_scalar_mult(effective_color, params.m.ambient);
	if (params.in_shadow)
		return (ambient);
	lightv = tuple_subtract(params.light.position, params.point);
	lightv = vector_normalize(lightv);
	if (vector_dot_product(lightv, params.normal_vec) < 0)
		return (ambient);
	specular = specular_calc(params, lightv);
	diffuse = diffuse_calc(params, lightv, effective_color);
	return (color_add(ambient, color_add(diffuse, specular)));
}
