/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:12:24 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/13 22:14:03 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	determinant2(double mat[][2])
{
	return ((mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]));
}

static void	submatrix3(double mat3[3][3], double mat2[2][2], int row, int col)
{
	int	i;
	int	j;
	int	sub_row;
	int	sub_col;

	j = 0;
	sub_row = 0;
	while (j < 3)
	{
		if (j != row)
		{
			i = 0;
			sub_col = 0;
			while (i < 3)
			{
				if (i != col)
					mat2[sub_row][sub_col++] = mat3[j][i];
				i++;
			}
			sub_row++;
		}
		j++;
	}
}

static double	cofactor2(double mat3[3][3], int row, int col)
{
	double	mat2[2][2];

	submatrix3(mat3, mat2, row, col);
	if ((row + col) % 2 == 0)
		return (determinant2(mat2));
	else
		return (determinant2(mat2) * -1);
}

double	determinant3(double mat3[3][3])
{
	double	det;
	int		i;

	det = 0;
	i = 0;
	while (i < 3)
	{
		det += mat3[0][i] * cofactor2(mat3, 0, i);
		i++;
	}
	return (det);
}
