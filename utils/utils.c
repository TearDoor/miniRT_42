/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:15:27 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/14 19:01:25 by tkok-kea         ###   ########.fr       */
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

/*
 * Quadratic roots calculated differently than usual
 * x = (-b ± sqrt(discriminant)) / 2a
 * to avoid catastrophic cancellation 
 * (loss of significance due to subtraction of two close values)
 * 1. calculate one of the roots where b doesn't cause subtraction normally
 * 2. use Vieta's formula (root1*root2 = c / a) to calculate the other
 */
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

double	sq(double x)
{
	return (pow(x, 2));
}

void	free_split(void **split)
{
	void	**cptr;

	cptr = split;
	while (*cptr)
	{
		free(*cptr);
		cptr++;
	}
	free(split);
}
