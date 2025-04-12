/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:25:02 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/12 16:59:29 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linux_keys.h"
#include "minirt.h"
#include "mlx_utils.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>

int	mouse_press(t_keycodes button, int x, int y, t_rt *rt)
{
	if (rt->mouse.status != NOT_PRESSED)
		return (1);
	rt->mouse.last_x = x;
	rt->mouse.last_y = y;
	if (button == MB_L)
	{
		rt->mouse.status = LEFT_PRESSED;
		rt->mouse.held_obj = pick_object(rt, x, y);
		if (rt->mouse.held_obj)
		{
			rt->low_res = 1;
		}
	}
	else if (button == MB_R)
		rt->mouse.status = RIGHT_PRESSED;
	else
		return (0);
	return (0);
}

/*
 * checks if the released button is the one being held
 * applies z axis translations to the camera for a moving forward/zooming effect
*/
int	mouse_release(t_keycodes button, int x, int y, t_rt *rt)
{
	(void)x;
	(void)y;
	if ((rt->mouse.status == LEFT_PRESSED && button == MB_L)
		|| (rt->mouse.status == RIGHT_PRESSED && button == MB_R))
	{
		rt->mouse.status = NOT_PRESSED;
		rt->mouse.held_obj = NULL;
		return (0);
	}
	if (button == MW_UP)
		rt->cam.transform = matrix_mult(translate_mat(0, 0, 5),
				rt->cam.transform);
	else if (button == MW_DOWN)
		rt->cam.transform = matrix_mult(translate_mat(0, 0, -5),
				rt->cam.transform);
	else
		return (1);
	mlx_showimg(rt);
	return (0);
}

int	check_distance_moved(int x, int y, int last_x, int last_y)
{
	int	distance;

	distance = sqrt(sq(x - last_x) + sq(y - last_y));
	return (distance > WIDTH / STEPS_PER_WIDTH);
}

int	mouse_move(int x, int y, t_rt *rt)
{
	if (rt->mouse.status == NOT_PRESSED || rt->mouse.held_obj == NULL)
		return (1);
	if (check_distance_moved(x, y, rt->mouse.last_x, rt->mouse.last_y))
	{
		move_object(rt, x, y);
		mlx_showimg(rt);
		rt->mouse.last_x = x;
		rt->mouse.last_y = y;
	}
	return (0);
}
