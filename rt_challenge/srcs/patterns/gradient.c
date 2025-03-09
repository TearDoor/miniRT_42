/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:22:31 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/09 22:35:56 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>

t_color	gradient_at(const t_pattern *patt, t_tuple p)
{
	t_gradient_pattern	*gradient;
	t_color				distance;
	double				fraction;

	gradient = (t_gradient_pattern *)patt;
	distance = color_subtract(gradient->b, gradient->a);
	fraction = p.x - floor(p.x);
	return (color_add(gradient->a, color_scalar_mult(distance, fraction)));
}

t_pattern	*gradient_pattern(t_color a, t_color b)
{
	t_stripe_pattern	*new_gradient;

	new_gradient = malloc(sizeof(t_stripe_pattern));
	new_gradient->pattern = init_pattern();
	new_gradient->pattern.pattern_at = &gradient_at;
	new_gradient->a = a;
	new_gradient->b = b;
	return ((t_pattern *)new_gradient);
}
