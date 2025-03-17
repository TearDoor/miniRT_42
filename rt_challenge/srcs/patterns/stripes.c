/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:06:48 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/17 13:36:09 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>

static t_color	stripe_at(const t_pattern *patt, t_tuple p)
{
	t_stripe_pattern	*stripe;

	stripe = (t_stripe_pattern *)patt;
	if ((int)floor(p.x) % 2 == 0)
		return (stripe->a);
	else
		return (stripe->b);
}

t_pattern	*stripe_pattern(t_color a, t_color b)
{
	t_stripe_pattern	*new_stripes;

	new_stripes = malloc(sizeof(t_stripe_pattern));
	new_stripes->pattern = init_pattern();
	new_stripes->pattern.pattern_at = &stripe_at;
	new_stripes->a = a;
	new_stripes->b = b;
	return ((t_pattern *)new_stripes);
}
