/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   earth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:24:46 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/10 14:44:18 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	earth(t_rt *rt)
{
	t_obj		*s1;

	rt->world = new_world();
	t_light *light1 = point_light(color(1, 1, 1), point(-1, 5, -2), 1);
	add_light_to_world(&rt->world, light1);
	s1 = sphere();
	s1->material.ambient = 0.5;
	s1->material.diffuse = 0.9;
	s1->material.specular = 0.1;
	s1->material.shininess = 10;
	set_img_from_file(s1, "earthmap1k.ppm");
	set_pattern(s1, uv_image(s1->material.image));
	apply_transform(s1, scaling_mat(1.5, 1.5, 1.5));
	set_normal_from_file(s1, "earthnormal1k.ppm");
	apply_transform(s1, rotation_y(M_PI / 2));
	add_obj_to_world(&rt->world, s1);
	rt->cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	init_view_matrix(&rt->cam, point(0, -2, -5), point(0, 0, 0), vector(0, 1, 0));
}
