/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:19:35 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/19 21:48:41 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// a helper function to create a glassy sphere
t_obj	*glass_sphere(void)
{
	t_obj	*gsphere;

	gsphere = sphere();
	gsphere->material.transparency = 1.0;
	gsphere->material.refractive_index = 1.5;
	return (gsphere);
}

void	refract_test(t_rt *rt)
{
	rt->world = default_world();
	rt->cam = new_camera(WIDTH, HEIGHT, M_PI / 2);
	init_view_matrix(&rt->cam, point(0, 0, -4), point(0, 0, -3), vector(0, 1, 0));
	t_obj	*plane1 = plane();
	apply_transform(plane1, translate_mat(0, -1, 0));
	add_obj_to_world(&rt->world, plane1);
	plane1->material.color = color(0, 0, 0.4);
	plane1->material.reflective = 0.9;
	plane1->material.transparency = 0.9;
	plane1->material.refractive_index = 1.5;
	plane1->material.shininess = 300;
	plane1->material.specular = 1;
	plane1->material.cast_shadow = 0;
	t_obj	*far_wall = plane();
	apply_transform(far_wall, rotation_x(M_PI / 2));
	apply_transform(far_wall, translate_mat(0, 0, 10));
	set_pattern(far_wall, bw_checkers());
	add_obj_to_world(&rt->world, far_wall);
	t_obj	*plane2 = plane();
	apply_transform(plane2, translate_mat(0, -3, 0));
	add_obj_to_world(&rt->world, plane2);
	set_pattern(plane2, checkers_pattern(color(1, 0, 0), color(0, 0.7, 0)));
	t_obj	*small_ball = sphere();
	set_pattern(small_ball, bw_uv_checkers(20, 10));
	apply_transform(small_ball, equal_scaling_mat(0.3));
	add_obj_to_world(&rt->world, small_ball);
	t_obj	*ball = sphere();
	apply_transform(ball, translate_mat(0, 1, 0));
	ball->material.color = color(1, 1, 1);
	ball->material.ambient = 0.1;
	ball->material.diffuse = 0.2;
	ball->material.reflective = 0.9;
	ball->material.shininess = 300;
	ball->material.specular = 1;
	add_obj_to_world(&rt->world, ball);
	// t_obj *a = glass_sphere();
	// t_obj *b = glass_sphere();
	// t_obj *c = glass_sphere();
	// t_light *light1 = point_light(color(1, 1, 1), point(2, 2, -3), 1);
	// rt->world = new_world();
	// add_light_to_world(&rt->world, light1);
	// apply_transform(a, equal_scaling_mat(2.0));
	// apply_transform(b, translate_mat(0, 0, 0.25));
	// apply_transform(c, translate_mat(0, 0, -0.25));
	// add_obj_to_world(&rt->world, a);
	// add_obj_to_world(&rt->world, b);
	// add_obj_to_world(&rt->world, c);
}
