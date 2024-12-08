/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:35:21 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/08 19:43:58 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_sqmat
{
	double	*elems;
	double	**rows;
	int		order;
}	t_sqmat;

t_sqmat	create_matrix(int order);
void	fill_matrix(t_sqmat *mat, int order, ...);
void	print_matrix(t_sqmat mat);
int		matrix_equal(t_sqmat m1, t_sqmat m2);

#endif
