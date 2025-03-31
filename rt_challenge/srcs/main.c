/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:38:46 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/31 19:36:22 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "mlx_utils.h"
#include "raytracing.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	check_arg(int argc, char *argv[])
{
	char	*file_exten;
	int		fd;

	if (argc != 2)
		error_exit("Need one and only one *.rt file as argument.");
	file_exten = ft_strrchr(argv[1], '.');
	if (!file_exten || ft_strcmp(file_exten, ".rt") != 0)
		error_exit("Argument must have .rt extension.");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(1);
	}
	return (fd);
}

void	parse_line(char *line)
{
	char	**info;

	if (*line == '\n')
		return ;
	info = ft_split(line, ' ');
	free_split((void **)info);
}

t_world	parse_world(int fd)
{
	t_world	w;
	char	*line;

	w = new_world();
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line);
		free(line);
		line = get_next_line(fd);
	}
	return (w);
}

int	init_rt(int fd, char *path, t_rt *rt)
{
	t_imgdata	img;

	rt->world = parse_world(fd);
	rt->mlx = mlx_init();
	rt->mlx_win = mlx_new_window(rt->mlx, WIDTH, HEIGHT, path);
	img.img_ptr = mlx_new_image(rt->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bbp, \
								&img.size_line, &img.endian);
	rt->img = img;
	rt->low_res = -1;
	rt->mouse.status = NOT_PRESSED;
	rt->mouse.held_obj = NULL;
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_rt	rt;

	fd = check_arg(argc, argv);
	init_rt(fd, argv[1], &rt);
	if (close(fd) < 0)
	{
		perror("close");
		exit(1);
	}
	leak_test(&rt);
	ft_mlx_hooks(&rt);
	mlx_showimg(&rt);
	mlx_loop(rt.mlx);
	return (0);
}
