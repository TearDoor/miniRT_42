/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:38:36 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/29 22:46:44 by tkok-kea         ###   ########.fr       */
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

int	camera_transform(t_keycodes key, t_rt *rt)
{
	const t_key_transform	cam_keys[] = {
	{KEY_W, translate_mat(0, -1, 0)}, {KEY_S, translate_mat(0, 1, 0)},
	{KEY_A, translate_mat(-1, 0, 0)}, {KEY_D, translate_mat(1, 0, 0)},
	{KEY_Q, rotation_z(-M_PI / 16)}, {KEY_E, rotation_z(M_PI / 16)},
	{UP, rotation_x(-M_PI / 16)}, {DOWN, rotation_x(M_PI / 16)},
	{LEFT, rotation_y(M_PI / 16)}, {RIGHT, rotation_y(-M_PI / 16)},
	{0, id_matrix()},
	};
	const t_key_transform	*ptr;

	ptr = cam_keys;
	while (ptr->key != 0)
	{
		if (key == ptr->key)
		{
			rt->cam.transform = matrix_mult(ptr->transform, rt->cam.transform);
			mlx_showimg(rt);
			return (1);
		}
		ptr++;
	}
	return (0);
}

int	keypress(t_keycodes key, t_rt *rt)
{
	if (key == ESC)
		close_win(rt);
	if (camera_transform(key, rt))
		return (0);
	if (key == BSPC)
		rt->cam.transform = rt->cam.initial_transform;
	else if (key == SPC)
		toggle_lowres(&rt->low_res);
	else
		return (0);
	mlx_showimg(rt);
	printf("%d pressed\n", key);
	return (0);
}
