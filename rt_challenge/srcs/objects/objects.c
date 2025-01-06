/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:54 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/06 18:56:11 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_obj	*new_obj(void)
{
	t_obj	*newobj;

	newobj = malloc(sizeof(t_obj));
	newobj->transform = id_matrix();
	newobj->material = material();
	return (newobj);
}

int	check_bounds(double t, t_ray ray, double max, double min)
{
	double	y;

	y = ray.origin.y + t * ray.direction.y;
	return ((y > min) && (y < max));
}
