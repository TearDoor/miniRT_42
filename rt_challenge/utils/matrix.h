/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:35:21 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/07 21:09:27 by tkok-kea         ###   ########.fr       */
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

#endif
