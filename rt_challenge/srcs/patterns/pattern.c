/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:13:43 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/14 17:17:06 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "matrix.h"
#include "rays.h"

t_pattern	init_pattern(void)
{
	return ((t_pattern){id_matrix(), id_matrix(), NULL, NULL});
}

void	set_pattern(t_obj *obj, t_pattern *patt)
{
	obj->material.pattern = patt;
	patt->mapping_func = obj->mapping_func;
}

t_color	pattern_at_shape(const t_pattern *patt, const t_obj *obj, t_tuple w_pt)
{
	t_tuple	object_point;
	t_tuple	pattern_point;

	object_point = matrix_tuple_mult(obj->inverse_transform, w_pt);
	pattern_point = matrix_tuple_mult(patt->inver_trans_mat, object_point);
	return (patt->pattern_at(patt, pattern_point));
}

void	set_pattern_transform(t_pattern *patt, t_mat4 m)
{
	if (patt == NULL)
		return ;
	patt->trans_mat = matrix_mult(m, patt->trans_mat);
	patt->inver_trans_mat = matrix_invert(patt->trans_mat);
}
