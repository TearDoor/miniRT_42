/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:38:46 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/16 14:59:08 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "mlx_utils.h"
#include "parse.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	check_arg(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int		fd;
	t_parse	*parse_data;
	t_rt	rt;

	fd = check_arg(argc, argv);
	parse_data = ft_calloc(1, sizeof(t_parse));
	if (parse_file(fd, parse_data))
	{
		free_shape(parse_data);
		return (1);
	}
	init_rt(argv[1], &rt);
	load_camera(&rt.cam, &parse_data->camera);
	load_world(&rt.world, parse_data);
	free_shape(parse_data);
	ft_mlx_hooks(&rt);
	mlx_showimg(&rt);
	mlx_loop(rt.mlx);
	return (0);
}

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
