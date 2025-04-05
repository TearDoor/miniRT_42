/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:01:01 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/05 22:47:00 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leak_test(t_rt *rt)
{
	rt->world = new_world();
	t_light *light1 = point_light(color(1, 1, 1), point(-1, 5, -2), 0.6);
	add_light_to_world(&rt->world, light1);
	t_light *light2 = point_light(color(1, 1, 1), point(3, 5, 0), 0.6);
	add_light_to_world(&rt->world, light2);
	rt->cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	init_view_matrix(&rt->cam, point(0, 2, -5), point(0, 0, 0), vector(0, 1, 0));
	rt->cam.initial_transform = rt->cam.transform;
	t_obj	*floor = plane();
	apply_transform(floor, translate_mat(0, -0.5, 0));
	add_obj_to_world(&rt->world, floor);
	t_obj	*cyl = cylinder();
	add_obj_to_world(&rt->world, cyl);
	t_obj	*wall = plane();
	add_obj_to_world(&rt->world, wall);
	t_obj	*sp = sphere();
	sp->material.color = color(0.7, 0.7, 0);
	add_obj_to_world(&rt->world, sp);
	apply_transform(wall, rotation_x(M_PI / 2));
	apply_transform(wall, translate_mat(0, 0, 5));
	return ;
}
