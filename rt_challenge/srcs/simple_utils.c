/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:05:58 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/10 17:07:16 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	error_exit(char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

void	free_split(char **split)
{
	char	**cptr;

	cptr = split;
	while (*cptr)
	{
		free(*cptr);
		cptr++;
	}
	free(split);
}
