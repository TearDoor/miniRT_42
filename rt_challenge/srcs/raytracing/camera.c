/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:41:12 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/22 21:04:37 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "matrix.h"
#include "rays.h"
#include "minirt.h"
#include <mlx.h>
#include <math.h>

t_mat4	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	forward;
	t_tuple	left;
	t_tuple	true_up;
	t_mat4	orientation;

	forward = vector_normalize(tuple_subtract(to, from));
	left = vector_cross_product(forward, vector_normalize(up));
	true_up = vector_cross_product(left, forward);
	orientation = (t_mat4){{
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1},
	}};
	return (matrix_mult(orientation, translate_mat(-from.x, -from.y, -from.z)));
}

t_camera	new_camera(int hsize, int vsize, double fov)
{
	double	half_view;
	double	aspect;
	double	half_width;
	double	half_height;

	half_view = tan(fov / 2);
	aspect = (double)hsize / (double)vsize;
	if (aspect >= 1)
	{
		half_width = half_view;
		half_height = half_view / aspect;
	}
	else
	{
		half_width = half_view * aspect;
		half_height = half_view;
	}
	return ((t_camera){
		hsize, vsize, fov, id_matrix(), id_matrix(),
		half_width, half_height,
		(half_width * 2) / hsize,
	});
}

/* generates a ray for each pixel to be rendered on screen 
 * camera x/y to world x/y : 
 * first calculate the distance from edge of screen to pixel center
 * px + 0.5 * cam.pix_size*/
t_ray	ray_for_pixel(t_camera cam, int px, int py)
{
	double	worldx;
	double	worldy;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

	worldx = cam.half_width - ((double)px + 0.5) * cam.pix_size;
	worldy = cam.half_height - ((double)py + 0.5) * cam.pix_size;
	pixel = matrix_tuple_mult(cam.inverse_transform, \
								point(worldx, worldy, -1));
	origin = matrix_tuple_mult(cam.inverse_transform, point(0, 0, 0));
	direction = vector_normalize(tuple_subtract(pixel, origin));
	return (ray(origin, direction));
}

#include <stdio.h>
void	render_to_mlximg(t_camera *cam, t_world *w, t_imgdata *img)
{
	int		i;
	int		j;
	t_ray	r;
	t_color	clr;

	printf("abc\n");
	cam->inverse_transform = matrix_invert(cam->transform);
	printf("abc\n");
	w->obj_arr = list_to_array_obj(w->objs);
	j = 0;
	while (j < cam->vsize)
	{
		i = 0;
		while (i < cam->hsize)
		{
			r = ray_for_pixel(*cam, i, j);
			clr = color_at(*w, r);
			ft_mlx_pixel_put(img, i, j, clr);
			i++;
		}
		j++;
	}
	free(w->obj_arr);
}

/*
t_canvas	render(t_camera cam, t_world w)
{
	t_canvas	cvs;
	int			i;
	int			j;
	t_ray		r;
	t_color		clr;

	cvs = canvas(cam.hsize, cam.vsize);
	cam.inverse_transform = matrix_invert(cam.transform);
	w.obj_arr = list_to_array_obj(w.objs);
	j = 0;
	while (j < cam.vsize)
	{
		i = 0;
		while (i < cam.hsize)
		{
			r = ray_for_pixel(cam, i, j);
			clr = color_at(w, r);
			write_pixel(cvs, i, j, clr);
			i++;
		}
		j++;
	}
	free(w.obj_arr);
	return (cvs);
}
*/
