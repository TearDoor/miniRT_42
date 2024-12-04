/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:44:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/04 17:49:22 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_color	color_add(t_color c1, t_color c2)
{
	t_color	c3;

	c3.r = c1.r + c2.r;
	c3.g = c1.g + c2.g;
	c3.b = c1.b + c2.b;
	return (c3);
}

t_color	color_subtract(t_color c1, t_color c2)
{
	t_color	c3;

	c3.r = c1.r - c2.r;
	c3.g = c1.g - c2.g;
	c3.b = c1.b - c2.b;
	return (c3);
}

t_color	color_mult(t_color c1, t_color c2)
{
	t_color	c3;

	c3.r = c1.r * c2.r;
	c3.g = c1.g * c2.g;
	c3.b = c1.b * c2.b;
	return (c3);
}

t_color	color_scalar_mult(t_color color, double scalar)
{
	t_color	res;

	res.r = color.r * scalar;
	res.g = color.g * scalar;
	res.b = color.b * scalar;
	return (res);
}
