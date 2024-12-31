/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:48:35 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/31 10:49:44 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "minirt.h"
#include "mlx.h"

void	scene_one(void)
{
	t_world w;
	t_obj	*s1, s2, s3;
	t_obj	*floor;
	t_obj	*lwall;
	t_obj	*rwall;
	t_camera	cam;
	t_canvas	cvs;
	t_mlx		mlx;

	w = new_world();
	w.light = point_light(color(1, 1, 1), point(-10, 10, -10));
	floor = sphere(1);
	set_transform(floor, scaling_mat(10, 0.01, 10));
	floor->material = material();
	floor->material.color = color(1, 0.9, 0.9);
	floor->material.specular = 0;
	ft_lstadd_back(&w.objs, ft_lstnew(floor));
	lwall = sphere(2);
	set_transform(lwall, scaling_mat(10, 0.01, 10));
	set_transform(lwall, rotation_x(M_PI / 2));
	set_transform(lwall, rotation_y(-M_PI / 4));
	set_transform(lwall, translate_mat(0, 0, 5));
	lwall->material = floor->material;
	ft_lstadd_back(&w.objs, ft_lstnew(lwall));
	rwall = sphere(2);
	set_transform(rwall, scaling_mat(10, 0.01, 10));
	set_transform(rwall, rotation_x(M_PI / 2));
	set_transform(rwall, rotation_y(M_PI / 4));
	set_transform(rwall, translate_mat(0, 0, 5));
	rwall->material = floor->material;
	ft_lstadd_back(&w.objs, ft_lstnew(rwall));
	cam = new_camera(500, 250, M_PI / 3);
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));
	cvs = render(cam, w);
	mlx.mlx = mlx_init();
	canvas_to_mlxwin(&cvs, &mlx);
}
