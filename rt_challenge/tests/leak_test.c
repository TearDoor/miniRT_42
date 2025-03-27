/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:01:01 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/27 21:50:19 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leak_test(t_rt *rt)
{
	rt->world = default_world();
	rt->cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	init_view_matrix(&rt->cam, point(0, 0, -5), point(0, 0, 0), vector(0, 1, 0));
	rt->cam.initial_transform = rt->cam.transform;
	t_obj	*floor = plane();
	set_transform(floor, translate_mat(0, -1, 0));
	add_obj_to_world(&rt->world, floor);
	t_obj	*wall = plane();
	set_transform(wall, rotation_x(M_PI / 2));
	set_transform(wall, translate_mat(0, 0, 5));
	add_obj_to_world(&rt->world, wall);
	return ;
}
