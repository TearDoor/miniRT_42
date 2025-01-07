/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:48:35 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/07 21:11:28 by tkok-kea         ###   ########.fr       */
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
	t_obj	*cone1;
	t_obj	*floor;
	t_obj	*lwall;
	t_obj	*celling;
	t_camera	cam;
	t_canvas	cvs;
	t_mlx		mlx;

	w = new_world();
	cone1 = cone();
	set_transform(cone1, rotation_z(M_PI / 4));
	set_transform(cone1, rotation_y(M_PI / 3));
	set_transform(cone1, translate_mat(0, 1, 0));
	cone1->material.color = color(0.1, 0.1, 0.8);
	ft_lstadd_back(&w.objs, ft_lstnew(cone1));
	cyl1 = cylinder();
	set_transform(cyl1, scaling_mat(1, 10, 1));
	set_transform(cyl1, rotation_z(M_PI / 4));
	set_transform(cyl1, translate_mat(0, 2, 0.5));
	cyl1->material.color = color(0.1, 0.1, 0.5);
	floor = plane();
	ft_lstadd_back(&w.objs, ft_lstnew(floor));
	lwall = plane();
	set_transform(lwall, rotation_x(M_PI / 2));
	set_transform(lwall, translate_mat(0, 0, 10));
	ft_lstadd_back(&w.objs, ft_lstnew(lwall));
	celling = plane();
	set_transform(celling, translate_mat(0, 4, 0));
	ft_lstadd_back(&w.objs, ft_lstnew(celling));
	w.light = point_light(color(1, 1, 1), point(-5, 2, -5));
	s1 = sphere();
	set_transform(s1, translate_mat(0, 1, 0.5));
	s1->material = material();
	s1->material.color = color(0.1, 1, 0.5);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.3;
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
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));
	cvs = render(cam, w);
	mlx.mlx = mlx_init();
	canvas_to_mlxwin(&cvs, &mlx);
}
