/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:01:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/14 20:52:25 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "utils.h"
#include "libft.h"

static void	submatrix4(double mat4[4][4], double mat3[3][3], int row, int col)
{
	int	i;
	int	j;
	int	sub_row;
	int	sub_col;

	j = 0;
	sub_row = 0;
	while (j < 4)
	{
		if (j != row)
		{
			i = 0;
			sub_col = 0;
			while (i < 4)
			{
				if (i != col)
					mat3[sub_row][sub_col++] = mat4[j][i];
				i++;
			}
			sub_row++;
		}
		j++;
	}
}

static double	cofactor4(double mat4[4][4], int row, int col)
{
	double	mat3[3][3];

	submatrix4(mat4, mat3, row, col);
	if ((row + col) % 2 == 0)
		return (determinant3(mat3));
	else
		return (determinant3(mat3) * -1);
}

static double	determinant4(double mat4[4][4])
{
	double	det;
	int		i;

	det = 0;
	i = 0;
	while (i < 4)
	{
		det += mat4[0][i] * cofactor4(mat4, 0, i);
		i++;
	}
	return (det);
}

t_mat4	matrix_invert(t_mat4 mat)
{
	t_mat4	inv;
	double	det;
	double	c;
	int		i;
	int		j;

	det = determinant4(mat.mat);
	if (equal(det, 0.0))
	{
		ft_putendl_fd("Warning: matrix not invertible.", STDERR_FILENO);
		return (id_matrix());
	}
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			c = cofactor4(mat.mat, j, i);
			inv.mat[i][j] = c / det;
			i++;
		}
		j++;
	}
	return (inv);
}
