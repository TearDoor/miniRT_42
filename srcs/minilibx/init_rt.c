/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:22:35 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/12 23:06:46 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"

int	init_rt(char *path, t_rt *rt)
{
	t_imgdata	img;

	rt->mlx = mlx_init();
	rt->mlx_win = mlx_new_window(rt->mlx, WIDTH, HEIGHT, path);
	img.img_ptr = mlx_new_image(rt->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bbp, &img.size_line,
			&img.endian);
	rt->img = img;
	rt->low_res = 1;
	rt->mouse.status = NOT_PRESSED;
	rt->mouse.held_obj = NULL;
	rt->controlling = CONTROL_CAM;
	return (0);
}
