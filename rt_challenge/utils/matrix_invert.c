/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:01:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/13 22:14:09 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "utils.h"

void	submatrix4(double mat4[4][4], double mat3[3][3], int row, int col)
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

double	cofactor4(double mat4[4][4], int row, int col)
{
	double	mat3[3][3];

	submatrix4(mat4, mat3, row, col);
	if ((row + col) % 2 == 0)
		return (determinant3(mat3));
	else
		return (determinant3(mat3) * -1);
}

double	determinant4(double mat4[4][4])
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

int	matrix_invert(double mat[][4], double inv[][4])
{
	double	det;
	double	c;
	int		i;
	int		j;

	det = determinant4(mat);
	if (equal(det, 0.0))
	{
		return (1);
	}
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			c = cofactor4(mat, j, i);
			inv[i][j] = c / det;
			i++;
		}
		j++;
	}
	return (0);
}
