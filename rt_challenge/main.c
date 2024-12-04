/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:59:15 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/04 21:18:40 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include "libft.h"

typedef struct s_canvas
{
	int		width;
	int		height;
	t_color	**pixels;
}	t_canvas;

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
		return ((int)val);
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
	t_color c1 = color(1, 0.8, 0.6);

	printf("P3\n");
	printf("%d %d\n", canvas.width, canvas.height);
	printf("255\n");
	j = 0;
	while (j < canvas.height)
	{
		i = 0;
		while (i < canvas.width)
		{
			print_color_ascii(c1);
			if (i != canvas.width - 1)
				printf(" ");
			else
				printf("\n");
			i++;
		}
		printf("\n");
		j++;
	}
}

int	main(void)
{
	t_color		c1, c2, c3;
	t_canvas	c;

	c1 = color(1.5, 0, 0);
	c2 = color(0, 0.5, 0);
	c3 = color(-0.5, 0, 1);
	c = canvas(10,3);
	canvas_to_ppm(c);
	return (0);
}
