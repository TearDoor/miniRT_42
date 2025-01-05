/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_first_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:27:03 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/05 16:11:06 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include "minirt.h"
#include <mlx.h>
#include <stdio.h>

#define PIXELS 500

void	wall(void)
{
	t_tuple		ray_origin;
	t_obj		*s1;
	double		wall_z;
	double		wall_size;
	double		pix_size;
	double		center;
	t_canvas	cvs;
	t_color		clr;
	int			i, j;
	double		world_y, world_x;
	t_tuple		ray_position;
	t_ray		cam_ray;
	t_tuple		ray_vector;
	t_list		*xs;
	t_mlx		mlx;
	t_light		light = point_light(color(1, 1, 1), point(5, 5, -5));
	t_lightparams	params;

	printf("start drawing.\n");
	ray_origin = point(0, 0, -5);
	wall_z = 10.0;
	wall_size = 7.0;
	pix_size = wall_size / PIXELS;
	center = wall_size / 2;
	cvs = canvas(PIXELS, PIXELS);
	clr = color(1, 0, 0);
	s1 = sphere();
	s1->material.color = (t_color){1, 0, 0};
	j = 0;
	while (j < PIXELS)
	{
		i = 0;
		world_y = center - pix_size * j;
		while (i < PIXELS)
		{
			world_x = center - pix_size * i;
			ray_position = point(world_x, world_y, wall_z);
			ray_vector =  tuple_subtract(ray_position, ray_origin);
			cam_ray = ray(ray_origin, vector_normalize(ray_vector));
			xs = NULL;
			check_intersect(*s1, cam_ray, &xs);
			if (checkhit(xs) != NULL)
			{
				params.point = position(cam_ray, checkhit(xs)->t);
				params.normal_vec = normal_at(checkhit(xs)->obj, params.point);
				params.eye_vec = tuple_negate(cam_ray.direction);
				params.m = checkhit(xs)->obj.material;
				params.light = light;
				clr = lighting(params);
				write_pixel(cvs, i, j, clr);
			}
			ft_lstclear(&xs, free);
			i++;
		}
		j++;
	}
	printf("Completed canvas.\n");
	mlx.mlx = mlx_init();
	canvas_to_mlxwin(&cvs, &mlx);
}
