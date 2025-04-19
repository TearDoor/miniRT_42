/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:15:27 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/17 17:27:38 by tkok-kea         ###   ########.fr       */
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
