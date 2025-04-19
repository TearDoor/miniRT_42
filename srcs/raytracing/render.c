/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:41:08 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/17 14:43:06 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include "minirt.h"
#include <stdio.h>

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
	pixel = matrix_tuple_mult(cam.inverse_transform, point(worldx, worldy, -1));
	origin = matrix_tuple_mult(cam.inverse_transform, point(0, 0, 0));
	direction = vector_normalize(tuple_subtract(pixel, origin));
	return (ray(origin, direction));
}

void	render_to_mlximg(t_camera *cam, t_world *w, t_imgdata *img)
{
	int		i;
	int		j;
	t_ray	r;
	t_color	clr;

	cam->inverse_transform = matrix_invert(cam->transform);
	j = 0;
	while (j < cam->vsize)
	{
		printf("\rRendering: remaining lines %d", cam->vsize - j);
		i = 0;
		while (i < cam->hsize)
		{
			r = ray_for_pixel(*cam, i, j);
			clr = color_at(*w, r, MAX_REFLECT);
			ft_mlx_pixel_put(img, i, j, clr);
			i++;
		}
		j++;
	}
	printf("\n");
}

void	lowres_pixel_put(t_imgdata *img, int i, int j, t_color clr)
{
	int	x;
	int	y;
	int	scale;

	scale = WIDTH / LOW_RES_WIDTH;
	y = 0;
	while (y < scale)
	{
		x = 0;
		while (x < scale)
		{
			ft_mlx_pixel_put(img, i * scale + x, j * scale + y, clr);
			x++;
		}
		y++;
	}
}

/*
 * render the scene at lower resolution to improve performance
 */
void	render_mlximg_lowres(t_camera *cam, t_world *w, t_imgdata *img)
{
	int		i;
	int		j;
	t_ray	r;
	t_color	clr;
	int		scale;

	scale = WIDTH / LOW_RES_WIDTH;
	cam->inverse_transform = matrix_invert(cam->transform);
	j = 0;
	while (j < cam->vsize / scale)
	{
		i = 0;
		while (i < cam->hsize / scale)
		{
			r = ray_for_pixel(*cam, i * scale, j * scale);
			clr = color_at(*w, r, MAX_REFLECT);
			lowres_pixel_put(img, i, j, clr);
			i++;
		}
		j++;
	}
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
