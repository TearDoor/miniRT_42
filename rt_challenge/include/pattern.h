/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:26:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/10 11:23:45 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "utils.h"
# include "matrix.h"

typedef struct s_obj		t_obj;
typedef struct s_pattern	t_pattern;
typedef t_color				(*t_pattern_at)(const t_pattern *, t_tuple);

typedef enum e_patt_type
{
	NONE,
	STRIPES,
}	t_patt_type;

typedef struct s_pattern
{
	t_mat4			trans_mat;
	t_mat4			inver_trans_mat;
	t_pattern_at	pattern_at;
}	t_pattern;

typedef struct s_stripe_pattern
{
	t_pattern	pattern;
	t_color		a;
	t_color		b;
}	t_stripe_pattern;

typedef struct s_gradient_pattern
{
	t_pattern	pattern;
	t_color		a;
	t_color		b;
}	t_gradient_pattern;

typedef struct s_ring_pattern
{
	t_pattern	pattern;
	t_color		a;
	t_color		b;
}	t_ring_pattern;

t_pattern	init_pattern(void);
void		set_pattern_transform(t_pattern *patt, t_mat4 m);
t_color		pattern_at_shape(const t_pattern *patt, const t_obj *obj, \
							t_tuple point);
t_pattern	*stripe_pattern(t_color a, t_color b);
t_pattern	*gradient_pattern(t_color a, t_color b);
t_pattern	*ring_pattern(t_color a, t_color b);
t_pattern	*checkers_pattern(t_color a, t_color b);

#endif
