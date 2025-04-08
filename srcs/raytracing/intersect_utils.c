/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:10:16 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/24 21:10:41 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

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
