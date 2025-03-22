/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:01:01 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/22 21:12:24 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	leak_test(t_rt *rt)
{
	rt->world = default_world();
	rt->cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	rt->cam.transform = view_transform(point(0, 1.5, -5), point(0, 0, 0), vector(0, 1, 0));
	t_obj	*floor = plane();
	set_transform(floor, translate_mat(0, -1, 0));
	add_obj_to_world(&rt->world, floor);
	return ;
}
