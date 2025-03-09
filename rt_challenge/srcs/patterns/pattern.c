/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:13:43 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/09 22:08:26 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "rays.h"

t_pattern	init_pattern(void)
{
	return ((t_pattern){id_matrix(), id_matrix(), NULL});
}

t_color	pattern_at_shape(const t_pattern *patt, const t_obj *obj, t_tuple w_pt)
{
	t_tuple	object_point;
	t_tuple	pattern_point;

	object_point = matrix_tuple_mult(obj->inverse_transform, w_pt);
	pattern_point = matrix_tuple_mult(obj->inverse_transform, object_point);
	return (patt->pattern_at(patt, pattern_point));
}
