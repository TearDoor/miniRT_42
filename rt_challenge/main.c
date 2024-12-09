/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:59:15 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/09 21:10:51 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "matrix.h"
#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include "stdio.h"

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
	t_mlx		mlx_obj;
	t_canvas	cvs;
	t_sqmat		mat1;
	t_sqmat		mat2;
	t_sqmat		mat3;

	mat1 = create_matrix(4);
	fill_matrix(&mat1, 4, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, \
						9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0);
	mat2 = create_matrix(4);
	fill_matrix(&mat2, 4, -2.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, -1.0, \
						4.0, 3.0, 6.0, 5.0, 1.0, 2.0, 7.0, 8.0);
	print_matrix(mat1);
	print_matrix(mat2);
	if (matrix_equal(mat1, mat2))
		printf("Same\n");
	mat3 = matrix_mult(mat1, mat2);
	print_matrix(mat3);
	mlx_obj.mlx = mlx_init();
	return (0);
}
