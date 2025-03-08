/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:26:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/08 17:47:47 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "utils.h"

typedef enum e_patt_type
{
	NONE,
	STRIPES,
}	t_patt_type;

typedef struct s_pattern
{
	t_color	a;
	t_color	b;
}	t_pattern;

t_pattern	*stripe_pattern(t_color a, t_color b);
t_color		stripe_at(t_pattern patt, t_tuple p);

#endif
