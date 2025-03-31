/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:31:41 by root              #+#    #+#             */
/*   Updated: 2025/03/31 11:39:23 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

int	main(int argc, char **argv)
{
	int			len;
	int			fd;
	t_minirt	*rt;

	if (argc != 2)
		return (print_error("Incorrect number of argument."));
	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + (len - 3), ".rt", 4) != 0)
		return (print_error("Incorrect File Type. <map>.rt"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_error("Invalid file"));
	rt = ft_calloc(sizeof(t_minirt), 1);
	if (parse_file(fd, rt))
	{
		printf("Oh No\n");
		free_shape(rt);
		return (1);
	}
	free_shape(rt);
	return (0);
}
