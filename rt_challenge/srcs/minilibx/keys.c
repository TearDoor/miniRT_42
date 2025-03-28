/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:38:36 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/28 15:35:08 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx_utils.h"
#include <stdio.h>

void	toggle_lowres(int *lowres)
{
	if (*lowres)
	{
		printf("Changing to full resolution\n");
		*lowres = 0;
	}
	else
	{
		printf("Changing to low resoultion\n");
		*lowres = 1;
	}
}

int	keypress(t_keycodes key, t_rt *rt)
{
	const t_keycodes	cam_keys[] = {
		KEY_W, KEY_S, KEY_A, KEY_D, KEY_Q, KEY_E,
	};

	if (key == ESC)
		close_win(rt);
	printf("%d pressed\n", key);
	if (key == KEY_W)
		rt->cam.transform = matrix_mult(translate_mat(0, -1, 0), rt->cam.transform);
	else if (key == KEY_S)
		rt->cam.transform = matrix_mult(translate_mat(0, 1, 0), rt->cam.transform);
	else if (key == KEY_A)
		rt->cam.transform = matrix_mult(translate_mat(-1, 0, 0), rt->cam.transform);
	else if (key == KEY_D)
		rt->cam.transform = matrix_mult(translate_mat(1, 0, 0), rt->cam.transform);
	else if (key == KEY_Q)
		rt->cam.transform = matrix_mult(rotation_z(-M_PI / 16), rt->cam.transform);
	else if (key == KEY_E)
		rt->cam.transform = matrix_mult(rotation_z(M_PI / 16), rt->cam.transform);
	else if (key == UP)
		rt->cam.transform = matrix_mult(rotation_x(-M_PI / 16), rt->cam.transform);
	else if (key == DOWN)
		rt->cam.transform = matrix_mult(rotation_x(M_PI / 16), rt->cam.transform);
	else if (key == LEFT)
		rt->cam.transform = matrix_mult(rotation_y(M_PI / 16), rt->cam.transform);
	else if (key == RIGHT)
		rt->cam.transform = matrix_mult(rotation_y(-M_PI / 16), rt->cam.transform);
	else if (key == BSPC)
		rt->cam.transform = rt->cam.initial_transform;
	else if (key == SPC)
		toggle_lowres(&rt->low_res);
	else
		return (0);
	mlx_showimg(rt);
	return (0);
}
