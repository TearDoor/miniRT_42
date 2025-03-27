/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:48:35 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/27 21:51:08 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "pattern.h"
#include "minirt.h"
#include <stdio.h>

void	scene_one(t_rt rt)
{
	t_world w;
	t_obj	*s1, *s2, *s3;
	t_obj	*cyl1;
	t_obj	*cone1;
	t_obj	*floor;
	t_obj	*lwall;
	t_obj	*celling;
	t_camera	cam;
	size_t		start_time;

	start_time = curr_time();
	w = new_world();
	w.light = point_light(color(1, 1, 1), point(-5, 2, -5));
	cone1 = cone();
	set_transform(cone1, rotation_z(M_PI / 4));
	set_transform(cone1, rotation_y(M_PI / 3));
	set_transform(cone1, translate_mat(2, 1, 0));
	set_pattern(cone1, uv_checkers(40, 2, color(0,0,0), color(1,1,1)));
	set_pattern_transform(cone1->material.pattern, scaling_mat(0.1, 0.1, 0.1));
	add_obj_to_world(&w, cone1);
	cone1->material.color = color(0.1, 0.1, 0.8);
	cyl1 = cylinder();
	set_pattern(cyl1, bw_ring());
	set_transform(cyl1, rotation_x(M_PI / 3));
	set_transform(cyl1, translate_mat(-2, 2, 0.5));
	set_pattern_transform(cyl1->material.pattern, scaling_mat(0.1, 0.1, 0.1));
	add_obj_to_world(&w, cyl1);
	t_obj	*cyl2 = cylinder();
	set_transform(cyl2, scaling_mat(0.5, 0.5, 0.5));
	set_transform(cyl2, translate_mat(0, 0.5, -2));
	set_pattern(cyl2, uv_checkers(32, 4, color(0,0,0), color(1,1,1)));
	add_obj_to_world(&w, cyl2);
	floor = plane();
	set_pattern(floor, bw_checkers());
	add_obj_to_world(&w, floor);
	lwall = plane();
	set_transform(lwall, rotation_x(M_PI / 2));
	set_transform(lwall, translate_mat(0, 0, 10));
	lwall->material.pattern = stripe_pattern(color(0,0,0), color(1, 1, 1));
	add_obj_to_world(&w, lwall);
	celling = plane();
	set_transform(celling, translate_mat(0, 4, 0));
	celling->material.pattern = stripe_pattern(color(0,0,0), color(0.8,0.8,0.8));
	add_obj_to_world(&w, celling);
	s1 = sphere();
	set_transform(s1, translate_mat(0, 1, 0));
	s1->material.color = color(0.1, 1, 0.5);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.3;
	set_pattern(s1, uv_checkers(20, 10, color(0,0,0), color(1,1,1)));
	add_obj_to_world(&w, s1);
	s2 = sphere();
	set_transform(s2, scaling_mat(0.5, 0.5, 0.5));
	set_transform(s2, translate_mat(1.5, 0.5, -0.5));
	s2->material.diffuse = 0.7;
	s2->material.pattern = stripe_pattern(color(1,1,1), color(0,0,0.6));
	set_pattern_transform(s2->material.pattern, scaling_mat(0.25, 0.25, 0.25));
	s2->material.specular = 0.3;
	add_obj_to_world(&w, s2);
	s3 = sphere();
	set_transform(s3, scaling_mat(0.33, 0.33, 0.33));
	set_transform(s3, translate_mat(-1.5, 0.33, -0.75));
	s3->material.color = color(1, 0.8, 0.1);
	s3->material.diffuse = 0.7;
	s3->material.specular = 0.3;
	add_obj_to_world(&w, s3);
	cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	init_view_matrix(&cam, point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));
	rt.world = w;
	printf("count = %ld\n", w.obj_count);
	render_to_mlximg(&cam, &w, &rt.img);
	printf("Time taken to render: %lu\n", curr_time() - start_time);
}
