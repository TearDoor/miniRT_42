/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:04:22 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/26 17:55:00 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>
#include <stdio.h>

t_intersect	*intersection(double t, t_obj obj)
{
	t_intersect	*inter;

	inter = malloc(sizeof(t_intersect));
	inter->t = t;
	inter->obj = obj;
	return (inter);
}

int	solve_quadratic(double a, double b, double c, double roots[2])
{
	double	discriminant;
	double	q;

	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant < 0)
		return (0);
	if (b > 0)
		q = -0.5 * (b + sqrt(discriminant));
	else
		q = -0.5 * (b - sqrt(discriminant));
	roots[0] = q / a;
	roots[1] = c / q;
	return (1);
}

void	lstadd_sorted_t(t_list **lst, t_list *new)
{
	t_list		*curr;
	t_intersect	*curr_x;
	t_intersect	*new_x;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		curr = *lst;
		curr_x = curr->content;
		new_x = new->content;
		if (new_x->t <= curr_x->t)
		{
			new->next = curr;
			*lst = new;
		}
		else
		{
			while (curr->next && new_x->t > curr_x->t)
			{
				curr = curr->next;
				curr_x = curr->content;
			}
			new->next = curr->next;
			curr->next = new;
		}
	}
}

void	line_sphere_intersection(t_obj sphere, t_ray ray, t_list **list)
{
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;
	double	roots[2];

	sphere_to_ray = tuple_subtract(ray.origin, sphere.origin);
	a = vector_dot_product(ray.direction, ray.direction);
	b = 2 * vector_dot_product(ray.direction, sphere_to_ray);
	c = vector_dot_product(sphere_to_ray, sphere_to_ray) - 1;
	if (!solve_quadratic(a, b, c, roots))
		return ;
	lstadd_sorted_t(list, ft_lstnew((void *)intersection(roots[0], sphere)));
	lstadd_sorted_t(list, ft_lstnew((void *)intersection(roots[1], sphere)));
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

void	check_intersect(t_obj sphere, t_ray ray, t_list **xs)
{
	t_ray	ray2;

	ray2 = transform_ray(ray, matrix_invert(sphere.transform));
	line_sphere_intersection(sphere, ray2, xs);
}
