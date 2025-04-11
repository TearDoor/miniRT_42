/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_from_ppm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:46:25 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/11 21:09:00 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>
#include <stdio.h>

t_canvas	parse_dimensions(int fd)
{
	char	*line;
	char	**dimensions;
	int		width;
	int		height;

	line = get_next_line(fd);
	dimensions = ft_split(line, ' ');
	width = ft_atoi(dimensions[0]);
	height = ft_atoi(dimensions[1]);
	free(line);
	free_split((void **)dimensions);
	return (canvas(width, height));
}

t_color	parse_color(char *red, char *green, char *blue, double color_scale)
{
	double	r;
	double	g;
	double	b;

	r = ft_atoi(red) / color_scale;
	g = ft_atoi(green) / color_scale;
	b = ft_atoi(blue) / color_scale;
	return (color(r, g, b));
}

/*
 * added a reset after parsing so that the program can parse multiple files
 */
void	store_color_to_canvas(t_canvas *cvs, t_color c)
{
	static int	col = 0;
	static int	row = 0;

	cvs->pixels[row][col] = c;
	++col;
	if (col == cvs->width)
	{
		++row;
		if (row == cvs->height)
			row = 0;
		col = 0;
	}
	return ;
}

void	parse_pixel_data(t_canvas *cvs, int fd)
{
	char	*line;
	int		color_scale;
	char	**values;
	int		i;
	t_color	new_color;

	line = get_next_line(fd);
	color_scale = ft_atoi(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		values = ft_split(line, ' ');
		i = 0;
		while (values[i] && values[i + 1])
		{
			new_color = parse_color(values[i], values[i + 1],
					values[i + 2], color_scale);
			store_color_to_canvas(cvs, new_color);
			i += 3;
		}
		free(line);
		free_split((void **)values);
		line = get_next_line(fd);
	}
}

/*
 * reverse of "canvas_to_ppm" function
*/
t_canvas	canvas_from_ppm(char *filename)
{
	int			fd;
	t_canvas	cvs;
	char		*magic;

	printf("Reading from file: %s\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(1);
	}
	magic = get_next_line(fd);
	if (ft_strcmp(magic, "P3\n") != 0)
	{
		free(magic);
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putstr_fd(": invalid ppm magic number", STDERR_FILENO);
		exit(1);
	}
	free(magic);
	cvs = parse_dimensions(fd);
	parse_pixel_data(&cvs, fd);
	printf("Finished reading.\n");
	return (cvs);
}
