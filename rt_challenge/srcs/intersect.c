/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:04:22 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/29 14:49:18 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_intersect	*intersection(double t, t_obj obj)
{
	t_intersect	*inter;

	inter = malloc(sizeof(t_intersect));
	inter->t = t;
	inter->obj = obj;
	return (inter);
}

int	lstcmp_xs(t_list *l1, t_list *l2)
{
	t_intersect	*x1;
	t_intersect	*x2;

	x1 = l1->content;
	x2 = l2->content;
	if (x1->t >= x2->t)
		return (1);
	else
		return (0);
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
	lstadd_sorted(list, ft_lstnew((void *)intersection(roots[0], sphere)), \
					&lstcmp_xs);
	lstadd_sorted(list, ft_lstnew((void *)intersection(roots[1], sphere)), \
					&lstcmp_xs);
}

void	check_intersect(t_obj sphere, t_ray ray, t_list **xs)
{
	t_ray	ray2;

	ray2 = transform_ray(ray, matrix_invert(sphere.transform));
	line_sphere_intersection(sphere, ray2, xs);
}

t_intersect	*checkhit(t_list *intersects)
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
			result = curr->content;
			break ;
		}
		curr = curr->next;
	}
	return (result);
}
