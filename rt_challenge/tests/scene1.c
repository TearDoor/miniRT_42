/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:48:35 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/09 15:40:10 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "minirt.h"
#include "mlx.h"
#include <sys/time.h>
#include <stdio.h>

size_t	curr_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

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
	cone1 = cone();
	set_transform(cone1, rotation_z(M_PI / 4));
	set_transform(cone1, rotation_y(M_PI / 3));
	set_transform(cone1, translate_mat(2, 1, 0));
	add_obj_to_world(&w, cone1);
	cone1->material.color = color(0.1, 0.1, 0.8);
	cyl1 = cylinder();
	set_transform(cyl1, translate_mat(-2, 2, 0.5));
	cyl1->material.color = color(0.1, 0.1, 0.5);
	add_obj_to_world(&w, cyl1);
	floor = plane();
	add_obj_to_world(&w, floor);
	lwall = plane();
	set_transform(lwall, rotation_x(M_PI / 2));
	set_transform(lwall, translate_mat(0, 0, 10));
	add_obj_to_world(&w, lwall);
	celling = plane();
	set_transform(celling, translate_mat(0, 4, 0));
	add_obj_to_world(&w, celling);
	w.light = point_light(color(1, 1, 1), point(-5, 2, -5));
	s1 = sphere();
	set_transform(s1, translate_mat(0, 1, 0.5));
	s1->material = material();
	s1->material.color = color(0.1, 1, 0.5);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.3;
	add_obj_to_world(&w, s1);
	s2 = sphere();
	set_transform(s2, scaling_mat(0.5, 0.5, 0.5));
	set_transform(s2, translate_mat(1.5, 0.5, -0.5));
	s2->material = material();
	s2->material.color = color(0.5, 1, 0.1);
	s2->material.diffuse = 0.7;
	s2->material.specular = 0.3;
	add_obj_to_world(&w, s2);
	s3 = sphere();
	set_transform(s3, scaling_mat(0.33, 0.33, 0.33));
	set_transform(s3, translate_mat(-1.5, 0.33, -0.75));
	s3->material = material();
	s3->material.color = color(1, 0.8, 0.1);
	s3->material.diffuse = 0.7;
	s3->material.specular = 0.3;
	add_obj_to_world(&w, s3);
	cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));
	printf("count = %ld\n", w.obj_count);
	rt.canvas = render(cam, w);
	printf("Time taken to render: %lu\n", curr_time() - start_time);
	ft_lstclear(&w.objs, free);
	canvas_to_mlxwin(&rt.canvas, &rt);
}
