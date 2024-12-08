/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:47:00 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/08 19:46:10 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "utils.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

t_sqmat	create_matrix(int order)
{
	t_sqmat	new_mat;
	int		i;

	new_mat.order = order;
	new_mat.elems = malloc(sizeof(double) * (order * order));
	new_mat.rows = malloc(sizeof(double *) * order);
	i = 0;
	while (i < order)
	{
		new_mat.rows[i] = &new_mat.elems[i * order];
		i++;
	}
	return (new_mat);
}

void	fill_matrix(t_sqmat *mat, int order, ...)
{
	va_list	ap;
	double	num;
	int		i;

	va_start(ap, order);
	i = 0;
	while (i < order * order)
	{
		num = va_arg(ap, double);
		*(mat->elems + i) = num;
		i++;
	}
	va_end(ap);
}

void	print_matrix(t_sqmat mat)
{
	int	i;
	int	j;

	j = 0;
	while (j < mat.order)
	{
		i = 0;
		while (i < mat.order)
			printf("%f ", mat.rows[j][i++]);
		printf("\n");
		j++;
	}
}

int	matrix_equal(t_sqmat m1, t_sqmat m2)
{
	int	i;
	int	j;

	if (m1.order != m2.order)
		return (0);
	j = 0;
	while (j < m1.order)
	{
		i = 0;
		while (i < m1.order)
		{
			if (!equal(m1.rows[j][i], m2.rows[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
