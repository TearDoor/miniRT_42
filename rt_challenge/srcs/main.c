/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:59:15 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/29 19:34:17 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "rays.h"
#include "mlx.h"
#include "minirt.h"
#include "linux_keys.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int	close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
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

int	keypress(int keycode, t_mlx *fdf)
{
	if (keycode == ESC)
		close_win(fdf);
	return (0);
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
	mlx_hook(mlx->mlx_win, 2, 1L >> 0, keypress, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, close_win, mlx);
	mlx_loop(mlx->mlx);
}

void	print_xs(t_list *xs)
{
	t_intersect	*x;

	while (xs)
	{
		x = xs->content;
		printf("%f\n", x->t);
		xs = xs->next;
	}
}

int	main(void)
{
	t_mat4		t;
	t_camera	cam;

	t = view_transform(point(1, 3, 2), point(4, -2, 8), vector(1, 1, 0));
	cam = new_camera(125, 200, M_PI / 2);
	print_matrix(t);
	printf("%.5f\n", cam.pix_size);
	return (0);
}
