/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:48:35 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/05 22:18:16 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "minirt.h"
#include "mlx.h"

void	scene_one(void)
{
	t_world w;
	t_obj	*s1, *s2, *s3;
	t_obj	*cyl1;
	t_obj	*floor;
	t_obj	*lwall;
	t_obj	*celling;
	t_camera	cam;
	t_canvas	cvs;
	t_mlx		mlx;

	w = new_world();
	cyl1 = cylinder();
	ft_lstadd_back(&w.objs, ft_lstnew(cyl1));
	floor = plane();
	ft_lstadd_back(&w.objs, ft_lstnew(floor));
	lwall = plane();
	set_transform(lwall, rotation_x(M_PI / 2));
	set_transform(lwall, translate_mat(0, 0, 10));
	ft_lstadd_back(&w.objs, ft_lstnew(lwall));
	celling = plane();
	set_transform(celling, translate_mat(0, 3, 0));
	ft_lstadd_back(&w.objs, ft_lstnew(celling));
	w.light = point_light(color(1, 1, 1), point(-5, 1, -5));
	s1 = sphere();
	set_transform(s1, translate_mat(-0.5, 1, 0.5));
	s1->material = material();
	s1->material.color = color(0.1, 1, 0.5);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.3;
	ft_lstadd_back(&w.objs, ft_lstnew(s1));
	s2 = sphere();
	set_transform(s2, scaling_mat(0.5, 0.5, 0.5));
	set_transform(s2, translate_mat(1.5, 0.5, -0.5));
	s2->material = material();
	s2->material.color = color(0.5, 1, 0.1);
	s2->material.diffuse = 0.7;
	s2->material.specular = 0.3;
	ft_lstadd_back(&w.objs, ft_lstnew(s2));
	s3 = sphere();
	set_transform(s3, scaling_mat(0.33, 0.33, 0.33));
	set_transform(s3, translate_mat(-1.5, 0.33, -0.75));
	s3->material = material();
	s3->material.color = color(1, 0.8, 0.1);
	s3->material.diffuse = 0.7;
	s3->material.specular = 0.3;
	ft_lstadd_back(&w.objs, ft_lstnew(s3));
	cam = new_camera(500, 250, M_PI / 3);
	cam.transform = view_transform(point(0, 1.5, -10), point(0, 1, 0), vector(0, 1, 0));
	cvs = render(cam, w);
	mlx.mlx = mlx_init();
	canvas_to_mlxwin(&cvs, &mlx);
}
