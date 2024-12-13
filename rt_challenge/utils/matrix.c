/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:47:00 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/13 21:59:08 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "utils.h"
#include <stdarg.h>
#include <stdio.h>

void	print_matrix(t_mat4 mat)
{
	int	i;
	int	j;

	j = 0;
	while (j < MAT_SIZE)
	{
		i = 0;
		while (i < MAT_SIZE)
		{
			printf("%.5f ", mat.mat[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

int	matrix_equal(t_mat4 mat1, t_mat4 mat2)
{
	int	i;
	int	j;

	j = 0;
	while (j < MAT_SIZE)
	{
		i = 0;
		while (i < MAT_SIZE)
		{
			if (!equal(mat1.mat[j][i], mat2.mat[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

t_mat4	matrix_transpose(t_mat4 mat)
{
	t_mat4	tp;
	int		i;
	int		j;

	j = 0;
	while (j < MAT_SIZE)
	{
		i = 0;
		while (i < MAT_SIZE)
		{
			tp.mat[i][j] = mat.mat[j][i];
			i++;
		}
		j++;
	}
	return (tp);
}
