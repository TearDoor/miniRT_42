/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:25:08 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/05 18:30:07 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

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
		printf("Error: writing pixel out of bounds.\n");
		return ;
	}
	c.pixels[y][x] = color;
}

int	clamp(double val)
{
	if (val >= 255)
		return (255);
	else if (val <= 0)
		return (0);
	else
		return (round(val));
}

void	print_color_ascii(t_color color)
{
	printf("%d ", clamp(255 * color.r));
	printf("%d ", clamp(255 * color.g));
	printf("%d", clamp(255 * color.b));
}

void	canvas_to_ppm(t_canvas canvas)
{
	int	i;
	int	j;
	int	fd;

	fd = open("output.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
		perror("open: ");
	dup2(fd, STDOUT_FILENO);
	printf("P3\n");
	printf("%d %d\n", canvas.width, canvas.height);
	printf("255\n");
	j = 0;
	while (j < canvas.height)
	{
		i = 0;
		while (i < canvas.width)
		{
			print_color_ascii(canvas.pixels[j][i]);
			if (i != canvas.width - 1)
				printf(" ");
			else
				printf("\n");
			i++;
		}
		printf("\n");
		j++;
	}
	close(fd);
}

