/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:13:43 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/09 16:19:56 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "rays.h"
#include <math.h>
#include <stdlib.h>

t_pattern	*stripe_pattern(t_color a, t_color b)
{
	t_pattern	*new_pattern;

	new_pattern = malloc(sizeof(t_pattern));
	new_pattern->a = a;
	new_pattern->b = b;
	return (new_pattern);
}

t_color	stripe_at(t_pattern patt, t_tuple p)
{
	if ((int)floor(p.x) % 2 == 0)
		return (patt.a);
	else
		return (patt.b);
}

t_color	stripe_at_object(t_pattern patt, const t_obj *obj, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	pattern_point;

	object_point = matrix_tuple_mult(obj->inverse_transform, world_point);
	pattern_point = matrix_tuple_mult(obj->inverse_transform, object_point);
	return (stripe_at(patt, pattern_point));
}
