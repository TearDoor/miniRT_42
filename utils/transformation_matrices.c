/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrices.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:48:24 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/11 22:11:06 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	translate_mat(double x, double y, double z)
{
	return (
		(t_mat4){{
			{1, 0, 0, x},
			{0, 1, 0, y},
			{0, 0, 1, z},
			{0, 0, 0, 1},
		}}
	);
}

/*
 * transform based on the xyz of a vector
 * used for mouse movement (translate with delta vector)
 * and parsing coordinates (translate with coordinate point)
*/
t_mat4	tuple_translate(t_tuple delta)
{
	return (translate_mat(delta.x, delta.y, delta.z));
}

t_mat4	scaling_mat(double x, double y, double z)
{
	return (
		(t_mat4){{
			{x, 0, 0, 0},
			{0, y, 0, 0},
			{0, 0, z, 0},
			{0, 0, 0, 1},
		}}
	);
}

t_mat4	equal_scaling_mat(double f)
{
	return (scaling_mat(f, f, f));
}

t_mat4	shearing_mat(t_shear params)
{
	return (
		(t_mat4){{
			{1, params.x_to_y, params.x_to_z, 0},
			{params.y_to_x, 1, params.y_to_z, 0},
			{params.z_to_x, params.z_to_y, 1, 0},
			{0, 0, 0, 1},
		}}
	);
}
