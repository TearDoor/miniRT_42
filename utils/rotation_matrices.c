/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:30:58 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/14 21:59:32 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_mat4	rotation_x(double radians)
{
	return (
		(t_mat4){{
			{1, 0, 0, 0},
			{0, cos(radians), -sin(radians), 0},
			{0, sin(radians), cos(radians), 0},
			{0, 0, 0, 1},
		}}
	);
}

t_mat4	rotation_y(double radians)
{
	return (
		(t_mat4){{
			{cos(radians), 0, sin(radians), 0},
			{0, 1, 0, 0},
			{-sin(radians), 0, cos(radians), 0},
			{0, 0, 0, 1},
		}}
	);
}

t_mat4	rotation_z(double radians)
{
	return (
		(t_mat4){{
			{cos(radians), -sin(radians), 0, 0},
			{sin(radians), cos(radians), 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1},
		}}
	);
}
