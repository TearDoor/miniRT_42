/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:25:02 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/30 19:12:31 by tkok-kea         ###   ########.fr       */
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
		rt->mouse.status = LEFT_PRESSED;
	else if (button == MB_R)
		rt->mouse.status = RIGHT_PRESSED;
	else
		return (0);
	mlx_showimg(rt);
	return (0);
}

/*
 * checks if the released button is the one being held
*/
int	mouse_release(t_keycodes button, int x, int y, t_rt *rt)
{
	if ((rt->mouse.status == LEFT_PRESSED && button == MB_L) || \
		(rt->mouse.status == RIGHT_PRESSED && button == MB_R))
		rt->mouse.status = NOT_PRESSED;
	if (button == MW_UP)
		rt->cam.transform = matrix_mult(translate_mat(0, 0, 1), rt->cam.transform);
	else if (button == MW_DOWN)
		rt->cam.transform = matrix_mult(translate_mat(0, 0, -1), rt->cam.transform);
	mlx_showimg(rt);
	return (0);
}

int	distance_since_last(int x, int y, int last_x, int last_y)
{
	int	distance;

	distance = sqrt(sq(x - last_x) + sq(y - last_y));
	return (distance);
}

int	mouse_move(int x, int y, t_rt *rt)
{
	if (rt->mouse.status == NOT_PRESSED)
		return (1);
	if (distance_since_last(x, y, rt->mouse.last_x, rt->mouse.last_y) > 50)
	{
		mlx_showimg(rt);
		rt->mouse.last_x = x;
		rt->mouse.last_y = y;
	}
	return (0);
}
