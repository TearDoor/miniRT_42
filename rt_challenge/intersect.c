/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:04:22 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/18 18:28:08 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>

t_intersect	*intersection(double t, t_sphere obj)
{
	t_intersect	*inter;

	inter = malloc(sizeof(t_intersect));
	inter->t = t;
	inter->obj = obj;
	return (inter);
}

t_list	*calculate_xs(double a, double b, double discriminant, t_sphere sphere)
{
	t_list	*xs;
	double	t1;
	double	t2;

	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);
	xs = NULL;
	ft_lstadd_back(&xs, ft_lstnew((void *)intersection(t1, sphere)));
	ft_lstadd_back(&xs, ft_lstnew((void *)intersection(t2, sphere)));
	return (xs);
}

t_list	*line_sphere_intersection(t_sphere sphere, t_ray ray)
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

t_intersect	*hit(t_list *intersects)
{
	t_list		*curr;
	t_intersect	*curr_xs;
	t_intersect	*result;

	curr = intersects;
	result = NULL;
	while (curr)
	{
		curr_xs = curr->content;
		if (curr_xs->t >= 0)
		{
			if (result == NULL)
				result = curr_xs;
			else if (curr_xs->t < result->t)
				result = curr_xs;
		}
		curr = curr->next;
	}
	return (result);
}

t_list	*check_intersect(t_sphere sphere, t_ray ray)
{
	t_ray	ray2;

	ray2 = transform_ray(ray, matrix_invert(sphere.transform));
	return (line_sphere_intersection(sphere, ray2));
}
