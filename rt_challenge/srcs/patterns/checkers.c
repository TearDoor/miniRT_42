/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:32 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/10 11:26:02 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_pattern	*checkers_pattern(t_color a, t_color b)
{
	t_stripe_pattern	*new_checkers;

	new_checkers = malloc(sizeof(t_stripe_pattern));
	new_checkers->pattern = init_pattern();
	new_checkers->pattern.pattern_at = NULL;
	new_checkers->a = a;
	new_checkers->b = b;
	return ((t_pattern *)new_checkers);
}
