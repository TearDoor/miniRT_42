/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:38:46 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/02 18:35:45 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "mlx_utils.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	check_arg(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int		fd;
	t_rt	rt;

	fd = check_arg(argc, argv);
	init_rt(argv[1], &rt);
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
