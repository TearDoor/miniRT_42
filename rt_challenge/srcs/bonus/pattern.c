/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:13:43 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/08 17:58:49 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <math.h>
#include <stdlib.h>

t_pattern	*stripe_pattern(t_color a, t_color b)
{
	t_pattern	*new_pattern;

	new_pattern = malloc(sizeof(t_pattern));
	new_pattern->a = a;
	new_pattern->b = b;
	return (new_pattern);
}

t_color	stripe_at(t_pattern patt, t_tuple p)
{
	if ((int)floor(p.x) % 2 == 0)
		return (patt.a);
	else
		return (patt.b);
}
