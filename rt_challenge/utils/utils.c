/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:15:27 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/02 17:59:26 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "utils.h"

int	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
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

/* adds new element to a linked list into
 * their sorted position based on a comparision function */
void	lstadd_sorted(t_list **lst, t_list *new, int (*cmp)(t_list *, t_list *))
{
	t_list		*curr;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		curr = *lst;
		if (!cmp(new, curr))
		{
			new->next = curr;
			*lst = new;
		}
		else
		{
			while (curr->next && cmp(new, curr->next))
				curr = curr->next;
			new->next = curr->next;
			curr->next = new;
		}
	}
}
