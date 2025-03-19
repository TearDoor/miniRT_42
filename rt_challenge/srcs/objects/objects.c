/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:54 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/19 15:21:57 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_obj	*new_obj(void)
{
	t_obj	*newobj;

	newobj = malloc(sizeof(t_obj));
	newobj->transform = id_matrix();
	newobj->inverse_transform = id_matrix();
	newobj->material = material();
	return (newobj);
}

/* truncates cylinders and cones */
int	check_bounds(double t, t_ray ray, double max, double min)
{
	double	y;

	y = ray.origin.y + t * ray.direction.y;
	return ((y > min) && (y < max));
}

static int	lstcmp_xs(t_list *l1, t_list *l2)
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

void	add_to_intersections(double t, t_obj *obj, t_list **list)
{
	t_intersect	*new_intersect;

	new_intersect = intersection(t, obj);
	lstadd_sorted(list, ft_lstnew(new_intersect), &lstcmp_xs);
}
