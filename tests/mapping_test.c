/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:45:25 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/10 18:28:13 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	map_test(t_rt *rt)
{
	t_obj		*plane1;

	rt->world = new_world();
	t_light *light1 = point_light(color(1, 1, 1), point(-1, 5, -2), 1);
	add_light_to_world(&rt->world, light1);
	plane1 = plane();
	set_normal_from_file(plane1, "earthnormal1k.ppm");
	set_img_from_file(plane1, "earthmap1k.ppm");
	set_pattern(plane1, uv_image(plane1->material.image));
	add_obj_to_world(&rt->world, plane1);
	rt->cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	init_view_matrix(&rt->cam, point(0, 2, -5), point(0, 0, 0), vector(0, 1, 0));
}
