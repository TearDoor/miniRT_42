/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_showimage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:32:10 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/02 18:33:16 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "linux_keys.h"
#include "mlx.h"

int	close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keypress(int keycode, t_mlx *fdf)
{
	if (keycode == ESC)
		close_win(fdf);
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

	mlx->mlx_win = mlx_new_window(mlx->mlx, cvs->width, cvs->height, "miniRT");
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
