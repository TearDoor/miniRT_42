/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:25:08 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/08 14:57:39 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdlib.h>

t_canvas	canvas(int width, int height)
{
	t_canvas	new_canvas;
	int			i;

	new_canvas.width = width;
	new_canvas.height = height;
	new_canvas.pixels = malloc(height * sizeof(t_color *));
	i = 0;
	while (i < height)
		new_canvas.pixels[i++] = ft_calloc(width, sizeof(t_color));
	return (new_canvas);
}

void	write_pixel(t_canvas c, int x, int y, t_color color)
{
	if (x < 0 || x >= c.width || y < 0 || y >= c.height)
	{
		ft_putendl_fd("Warning: drawing out of bounds.", STDERR_FILENO);
		return ;
	}
	c.pixels[y][x] = color;
}

void	free_canvas(t_canvas cvs)
{
	int	i;

	i = 0;
	while (i < cvs.height)
		free(cvs.pixels[i++]);
	free(cvs.pixels);
}
