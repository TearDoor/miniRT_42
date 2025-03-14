/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   earth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:24:46 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/14 14:08:12 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	earth(t_rt rt)
{
	t_world		w;
	t_camera	cam;
	t_obj		*s1;

	w = new_world();
	w.light = point_light(color(1, 1, 1), point(0, 1, -2));
	s1 = sphere();
	t_canvas img = canvas_from_ppm("earthmap1k.ppm");
	s1->material.ambient = 0.5;
	s1->material.specular = 0.1;
	set_transform(s1, scaling_mat(1.5, 1.5, 1.5));
	s1->material.pattern = uv_image(&img);
	add_obj_to_world(&w, s1);
	cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 0, 0), vector(0, 1, 0));
	rt.canvas = render(cam, w);
	canvas_to_mlxwin(&rt.canvas, &rt);
}
