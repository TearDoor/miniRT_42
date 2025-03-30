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

#include "minirt.h"
#include "mlx_utils.h"

int	mouse_release(t_keycodes button, int x, int y, t_rt *rt)
{
	if (button == MW_UP)
		rt->cam.transform = matrix_mult(translate_mat(0, 0, 1), rt->cam.transform);
	else if (button == MW_DOWN)
		rt->cam.transform = matrix_mult(translate_mat(0, 0, -1), rt->cam.transform);
	mlx_showimg(rt);
	return (0);
}
