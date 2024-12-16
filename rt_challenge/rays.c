/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:47:40 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/16 21:10:12 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_ray	ray(t_tuple point, t_tuple vector)
{
	return ((t_ray){
		.origin = point,
		.direction = vector
	});
}

t_tuple	position(t_ray ray, double distance)
{
	return (tuple_add(ray.origin, tuple_scalar_mult(ray.direction, distance)));
}

t_sphere	sphere(int id)
{
	return ((t_sphere){
		id,
		(t_tuple){{0, 0, 0, 1}},
		1,
	});
}

t_intersect	*intersection(double t, t_sphere obj)
{
	t_intersect	*inter;

	inter = malloc(sizeof(t_intersect));
	printf("%f\n", t);
	inter->t = t;
	inter->obj = obj;
	return (inter);
}

t_list	*calculate_xs(double a, double b, double discriminant, t_sphere sphere)
{
	t_list		*xs;

	xs = NULL;
	ft_lstadd_back(&xs, ft_lstnew((void *)intersection(\
									(-b - sqrt(discriminant)) / (2 * a), sphere)));
	ft_lstadd_back(&xs, ft_lstnew((void *)intersection(\
									(-b + sqrt(discriminant)) / (2 * a), sphere)));
	return (xs);
}

t_list	*check_intersect(t_sphere sphere, t_ray ray)
{
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	sphere_to_ray = tuple_subtract(ray.origin, sphere.origin);
	a = vector_dot_product(ray.direction, ray.direction);
	b = 2 * vector_dot_product(ray.direction, sphere_to_ray);
	c = vector_dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant < 0)
		return (NULL);
	else
		return (calculate_xs(a, b, discriminant, sphere));
}
