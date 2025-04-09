/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:01:01 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/09 17:16:11 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leak_test(t_rt *rt)
{
	t_obj	*floor = plane();
	apply_transform(floor, translate_mat(0, -1, 0));
	add_obj_to_world(&rt->world, floor);
	t_obj	*cyl = cylinder();
	add_obj_to_world(&rt->world, cyl);
	t_obj	*sp = sphere();
	set_pattern(sp, bw_uv_checkers(20, 10));
	apply_transform(sp, translate_mat(-2, 0, 0));
	add_obj_to_world(&rt->world, sp);
	return ;
}
