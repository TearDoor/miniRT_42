/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_to_ppm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:31:47 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/07 21:37:29 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

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

void	print_canvas(t_canvas canvas)
{
	int	i;
	int	j;

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
		j++;
	}
}

void	canvas_to_ppm(t_canvas canvas)
{
	int	fd;

	fd = open("output.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
		perror("open: ");
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("P3\n");
	printf("%d %d\n", canvas.width, canvas.height);
	printf("255\n");
	print_canvas(canvas);
}
