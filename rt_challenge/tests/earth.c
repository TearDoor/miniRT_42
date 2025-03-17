/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   earth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:24:46 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/17 22:01:45 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	earth(t_rt rt)
{
	t_world		w;
	t_camera	cam;
	t_obj		*s1;
	size_t		start;

	start = curr_time();
	w = new_world();
	w.light = point_light(color(1, 1, 1), point(-1, 1, -2));
	s1 = sphere();
	s1->material.ambient = 0.5;
	s1->material.diffuse = 0.9;
	s1->material.specular = 0.1;
	s1->material.shininess = 10;
	set_transform(s1, scaling_mat(1.5, 1.5, 1.5));
	t_canvas img = canvas_from_ppm("earthmap1k.ppm");
	set_pattern(s1, uv_image(&img));
	set_normal_from_file(s1, "earthnormal1k.ppm");
	set_transform(s1, rotation_y(M_PI / 2));
	add_obj_to_world(&w, s1);
	cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 0, 0), vector(0, 1, 0));
	rt.canvas = render(cam, w);
	printf("render time: %lu\n", curr_time() - start);
	canvas_to_mlxwin(&rt.canvas, &rt);
}
