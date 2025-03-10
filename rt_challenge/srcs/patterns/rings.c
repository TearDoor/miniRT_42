/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rings.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:40 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/10 11:21:41 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>

t_color	ring_at(const t_pattern *patt, t_tuple p)
{
	t_ring_pattern	*ring;
	double			distance;

	ring = (t_ring_pattern *)patt;
	distance = sqrt(pow(p.x, 2) + pow(p.z, 2));
	if ((int)floor(distance) % 2 == 0)
		return (ring->a);
	else
		return (ring->b);

}

t_pattern	*ring_pattern(t_color a, t_color b)
{
	t_ring_pattern	*new_ring;

	new_ring = malloc(sizeof(t_ring_pattern));
	new_ring->pattern = init_pattern();
	new_ring->pattern.pattern_at = &ring_at;
	new_ring->a = a;
	new_ring->b = b;
	return ((t_pattern *)new_ring);
}
