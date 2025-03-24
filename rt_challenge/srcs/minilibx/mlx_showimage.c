/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_showimage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:32:10 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/24 22:26:35 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "linux_keys.h"
#include "mlx.h"
#include <stdio.h>

int	close_win(t_rt *rt)
{
	free_world(&rt->world);
	mlx_destroy_image(rt->mlx, rt->img.img_ptr);
	mlx_destroy_window(rt->mlx, rt->mlx_win);
	mlx_destroy_display(rt->mlx);
	free(rt->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keypress(t_keycodes key, t_rt *rt)
{
	if (key == ESC)
		close_win(rt);
	printf("%d pressed\n", key);
	if (key == UP)
		rt->cam.transform = matrix_mult(translate_mat(0, -1, 0), rt->cam.transform);
	else if (key == DOWN)
		rt->cam.transform = matrix_mult(translate_mat(0, 1, 0), rt->cam.transform);
	else if (key == LEFT)
		rt->cam.transform = matrix_mult(translate_mat(-1, 0, 0), rt->cam.transform);
	else if (key == RIGHT)
		rt->cam.transform = matrix_mult(translate_mat(1, 0, 0), rt->cam.transform);
	mlx_showimg(rt);
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

	dst = img->addr + ((y * img->size_line) + x * (img->bbp / 8));
	*(unsigned int *)dst = color_convert(color);
}

void	mlx_showimg(t_rt *rt)
{
	render_to_mlximg(&rt->cam, &rt->world, &rt->img);
	mlx_put_image_to_window(rt->mlx, rt->mlx_win, rt->img.img_ptr, 0, 0);
}

void	ft_mlx_hooks(t_rt *rt)
{
	mlx_key_hook(rt->mlx_win, keypress, rt);
	mlx_hook(rt->mlx_win, 17, 0, close_win, rt);
}

/*
void	canvas_to_mlxwin(t_canvas *cvs, t_rt *rt)
{
	int			i;
	int			j;

	j = 0;
	while (j < cvs->height)
	{
		i = 0;
		while (i < cvs->width)
		{
			ft_mlx_pixel_put(&rt->img, i, j, cvs->pixels[j][i]);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(rt->mlx, rt->mlx_win, rt->img.img_ptr, 0, 0);
	mlx_hook(rt->mlx_win, 2, 1L >> 0, keypress, rt);
	mlx_hook(rt->mlx_win, 17, 0, close_win, rt);
	mlx_loop(rt->mlx);
}
*/
