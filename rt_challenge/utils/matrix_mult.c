/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:24:11 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/12 19:24:50 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "utils.h"

t_mat4	matrix_mult(t_mat4 mat1, t_mat4 mat2)
{
	int		i;
	int		j;
	int		k;
	t_mat4	m3;

	j = 0;
	while (j < MAT_SIZE)
	{
		i = 0;
		while (i < MAT_SIZE)
		{
			k = 0;
			m3.mat[j][i] = 0;
			while (k < MAT_SIZE)
			{
				m3.mat[j][i] += mat1.mat[j][k] * mat2.mat[k][i];
				k++;
			}
			i++;
		}
		j++;
	}
	return (m3);
}

t_tuple	matrix_tuple_mult(t_mat4 mat, t_tuple tup)
{
	int		i;
	t_tuple	res;

	res = vector(0, 0, 0);
	i = 0;
	while (i < MAT_SIZE)
	{
		res.x += mat.mat[0][i] * tup.elems[i];
		res.y += mat.mat[1][i] * tup.elems[i];
		res.z += mat.mat[2][i] * tup.elems[i];
		res.w += mat.mat[3][i] * tup.elems[i];
		i++;
	}
	return (res);
}
