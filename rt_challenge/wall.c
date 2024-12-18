/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:27:03 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/18 21:46:11 by tkok-kea         ###   ########.fr       */
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
	t_sphere	s1;
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

	printf("start drawing.\n");
	ray_origin = point(0, 0, -5);
	wall_z = 10.0;
	wall_size = 7.0;
	pix_size = wall_size / PIXELS;
	center = wall_size / 2;
	cvs = canvas(PIXELS, PIXELS);
	clr = color(1, 0, 0);
	s1 = sphere(1);
	set_transform(&s1, scaling_mat(0.5, 1, 1));
	set_transform(&s1, shearing_mat((t_shear){1, 0, 0, 0, 0, 0}));
	j = 0;
	while (j < PIXELS)
	{
		i = 0;
		world_y = center - pix_size * j;
		while (i < PIXELS)
		{
			world_x = center - pix_size * i;
			ray_position = point(world_x, world_y, wall_z);
			ray_vector = tuple_subtract(ray_position, ray_origin);
			cam_ray = ray(ray_origin, vector_normalize(ray_vector));
			xs = check_intersect(s1, cam_ray);
			if (hit(xs) != NULL)
				write_pixel(cvs, i, j, clr);
			i++;
		}
		j++;
	}
	printf("Completed canvas.\n");
	mlx.mlx = mlx_init();
	canvas_to_mlxwin(&cvs, &mlx);
}
