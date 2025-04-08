/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:35:21 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/03 20:14:46 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# define MAT_SIZE 4
# ifndef M_PI
#  define M_PI 3.1415926535897932384626433832
# endif

# include "utils.h"

typedef struct s_mat4
{
	double	mat[MAT_SIZE][MAT_SIZE];
}	t_mat4;

typedef struct s_shear
{
	double	x_to_y;
	double	x_to_z;
	double	y_to_x;
	double	y_to_z;
	double	z_to_x;
	double	z_to_y;
}	t_shear;

void	print_matrix(t_mat4 mat);
int		matrix_equal(t_mat4 mat1, t_mat4 mat2);
t_mat4	matrix_transpose(t_mat4 mat);

t_mat4	matrix_mult(t_mat4 mat1, t_mat4 mat2);
t_tuple	matrix_tuple_mult(t_mat4 mat, t_tuple tup);
t_mat4	id_matrix(void);

t_mat4	matrix_invert(t_mat4 mat);
double	determinant3(double mat3[3][3]);

t_mat4	translate_mat(double x, double y, double z);
t_mat4	delta_vector_translate(t_tuple delta);
t_mat4	scaling_mat(double x, double y, double z);
t_mat4	shearing_mat(t_shear params);
t_mat4	rotation_x(double radians);
t_mat4	rotation_y(double radians);
t_mat4	rotation_z(double radians);

#endif
