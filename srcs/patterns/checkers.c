/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:32 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/17 12:53:18 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>

t_color	checkers_at(const t_pattern *patt, t_tuple p)
{
	t_stripe_pattern	*checkers;
	double				distance;

	checkers = (t_stripe_pattern *)patt;
	distance = floor(p.x) + floor(p.y) + floor(p.z);
	if ((int)distance % 2 == 0)
		return (checkers->a);
	else
		return (checkers->b);
}

t_pattern	*checkers_pattern(t_color a, t_color b)
{
	t_stripe_pattern	*new_checkers;

	new_checkers = malloc(sizeof(t_stripe_pattern));
	new_checkers->pattern = init_pattern();
	new_checkers->pattern.pattern_at = checkers_at;
	new_checkers->a = a;
	new_checkers->b = b;
	return ((t_pattern *)new_checkers);
}

t_pattern	*bw_checkers(void)
{
	return (checkers_pattern(color(1, 1, 1), color(0, 0, 0)));
}
