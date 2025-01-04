/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:04:22 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/04 21:28:10 by tkok-kea         ###   ########.fr       */
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

void	check_intersect(t_obj obj, t_ray ray, t_list **xs)
{
	t_ray	local_ray;

	local_ray = transform_ray(ray, matrix_invert(obj.transform));
	obj.local_intersect(obj, local_ray, xs);
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
