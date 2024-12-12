/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:35:21 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/12 19:23:21 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# define MAT_SIZE 4

#include "utils.h"

typedef struct s_mat4
{
	double	mat[MAT_SIZE][MAT_SIZE];
}	t_mat4;

void	print_matrix(t_mat4 mat);
int		matrix_equal(t_mat4 mat1, t_mat4 mat2);

t_mat4	matrix_mult(t_mat4 mat1, t_mat4 mat2);
t_tuple	matrix_tuple_mult(t_mat4 mat, t_tuple tup);

#endif
