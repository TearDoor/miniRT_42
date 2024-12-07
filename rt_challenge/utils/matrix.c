/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:47:00 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/07 21:25:36 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
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
