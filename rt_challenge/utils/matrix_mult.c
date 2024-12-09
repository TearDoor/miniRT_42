/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:24:11 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/09 20:35:50 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_sqmat	matrix_mult(t_sqmat m1, t_sqmat m2)
{
	int		i;
	int		j;
	int		k;
	t_sqmat	m3;

	m3 = create_matrix(m1.order);
	j = 0;
	while (j < m1.order)
	{
		i = 0;
		while (i < m1.order)
		{
			k = 0;
			m3.rows[j][i] = 0;
			while (k < m1.order)
			{
				m3.rows[j][i] += m1.rows[j][k] * m2.rows[k][i];
				k++;
			}
			i++;
		}
		j++;
	}
	return (m3);
}
