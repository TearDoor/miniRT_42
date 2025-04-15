/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:26:09 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/13 21:30:49 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "raytracing.h"
#include <math.h>

//determine the cone_min to use for different type of cones
double	get_cone_min(t_obj_type type)
{
	if (type == OBJ_CONE)
		return (CONE_MIN);
	else
		return (DCONE_MIN);
}

/* a unit cone's radius at any given y is the absolute value of that y */
int	cone_check_caps(t_ray ray, double t, double y)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (pow(x, 2) + pow(z, 2) <= fabs(y));
}
