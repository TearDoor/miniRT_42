/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-17 02:29:44 by root              #+#    #+#             */
/*   Updated: 2025-03-17 02:29:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	execute_minirt(t_minirt *rt)
{
	rt->mlx = mlx_init();
	if (rt->mlx == NULL)
	{
		free_shape(rt);
		print_error("Error: Fails to open window");
		exit(1);
	}
	rt->img = ft_calloc(1, sizeof(t_img));
	rt->img->mlx_img = mlx_new_image(rt->mlx, W_WIDTH, W_HEIGHT);
	rt->win = mlx_new_window(rt->mlx, W_WIDTH, W_HEIGHT, "MiniRT");
	if (!(rt->win) || !(rt->img->mlx_img))
	{
		close_window(rt);
		print_error("Error: Fails to create window.");
		exit(1);
	}
	rt->img->addr = mlx_get_data_addr(rt->img->mlx_img, &rt->img->bpp,
			&rt->img->line_len, &rt->img->endian);
	mlx_hook(rt->win, 2, (1L << 0), &handle_keypress, rt);
	mlx_hook(rt->win, 17, 0, &close_window, rt);
	mlx_loop(rt->mlx);
}

int	close_window(t_minirt *rt)
{
	mlx_destroy_image(rt->mlx, rt->img->mlx_img);
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_destroy_display(rt->mlx);
	if (rt->img)
		free(rt->img);
	free_shape(rt);
	ft_printf("%sWindow is closed. Bye !! %s\n", YELLOW, YELLOW);
	ft_printf("%s", RESET_COLOR);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_minirt *rt)
{
	if (keycode == XK_Escape)
		close_window(rt);
	return (0);
}
