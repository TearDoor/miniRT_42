/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:38:36 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/06 21:51:36 by tkok-kea         ###   ########.fr       */
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

int	change_mode(t_keycodes key, t_control *controlled)
{
	if (key == KEY_1)
		*controlled = CONTROL_CAM;
	else if (key == KEY_2)
		*controlled = CONTROL_LIGHTS;
	else if (key == KEY_3)
		*controlled = CONTROL_OBJ;
	else
		return (0);
	return (1);
}

int	keypress(t_keycodes key, t_rt *rt)
{
	const t_ctrl_funcptr	ctrl_funcs[] = {
	[CONTROL_CAM] = camera_transform,
	[CONTROL_LIGHTS] = light_transform,
	[CONTROL_OBJ] = NULL,
	};

	printf("%d pressed\n", key);
	if (key == ESC)
		close_win(rt);
	if (change_mode(key, &rt->controlling))
		return (0);
	if (ctrl_funcs[rt->controlling](key, rt))
		return (0);
	if (key == BSPC)
		rt->cam.transform = rt->cam.initial_transform;
	else if (key == SPC)
		toggle_lowres(&rt->low_res);
	else
		return (0);
	mlx_showimg(rt);
	return (0);
}
