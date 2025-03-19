/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-09 13:31:41 by root              #+#    #+#             */
/*   Updated: 2025-03-09 13:31:41 by root             ###   ########.fr       */
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
	if (parse_file(fd, rt) == 0)
	{
		execute_minirt(rt);
		free_acl_plane(rt);
		free_shape(rt);
	}
	return (0);
}