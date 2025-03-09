/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:26:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/09 16:34:00 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "utils.h"

typedef struct s_obj	t_obj;

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
t_color		stripe_at_object(t_pattern patt, const t_obj *obj, t_tuple world_point);

#endif
