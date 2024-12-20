/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:59:15 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/20 20:51:39 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "rays.h"
#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int	close_win(int keycode, t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

unsigned int	color_convert(t_color color)
{
	unsigned int	hex;

	hex = clamp(color.r * 255) << 16;
	hex += clamp(color.g * 255) << 8;
	hex += clamp(color.b * 255);
	return (hex);
}

void	ft_mlx_pixel_put(t_imgdata *img, int x, int y, t_color color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_length) + x * (img->bbp / 8));
	*(unsigned int *)dst = color_convert(color);
}

void	canvas_to_mlxwin(t_canvas *cvs, t_mlx *mlx)
{
	t_imgdata	img;
	int			i;
	int			j;

	mlx->mlx_win = mlx_new_window(mlx->mlx, cvs->width, cvs->height, "Cannon");
	img.img = mlx_new_image(mlx->mlx, cvs->width, cvs->height);
	img.addr = mlx_get_data_addr(img.img, &img.bbp, \
								&img.line_length, &img.endian);
	j = 0;
	while (j < cvs->height)
	{
		i = 0;
		while (i < cvs->width)
		{
			ft_mlx_pixel_put(&img, i, j, cvs->pixels[j][i]);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.img, 0, 0);
	mlx_hook(mlx->mlx_win, 2, 1L >> 0, close_win, mlx);
	mlx_loop(mlx->mlx);
}

int	main(void)
{
	t_sphere	s1;
	t_tuple		pos = point(0, 0, 0);
	t_color		res;
	t_tuple		eyev = vector(0, 0, -1);
	t_tuple		normalv = vector(0, 0, -1);
	t_light		light = point_light(color(0, 0, 1), point(0, 0, 10));

	s1 = sphere(1);
	pos = point(0, 0, 0);
	res = lighting(material(), light, pos, eyev, normalv);
	wall();
	return (0);
}
