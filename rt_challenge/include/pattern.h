/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:26:33 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/14 21:17:43 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "utils.h"
# include "matrix.h"

typedef struct s_obj		t_obj;
typedef struct s_pattern	t_pattern;
typedef struct s_point2d	t_point2d;
typedef t_point2d			(*t_mapping)(t_tuple);
typedef t_color				(*t_pattern_at)(const t_pattern *, t_tuple);
typedef t_color				(*t_uv_pattern_at)(const t_pattern *, t_point2d);

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
	t_mapping		mapping_func;
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

typedef struct s_uv_pattern
{
	t_pattern		pattern;
	t_uv_pattern_at	uv_pattern_at;
	double			width;
	double			height;
	t_color			a;
	t_color			b;
}	t_uv_pattern;

typedef struct s_uv_image
{
	t_pattern		pattern;
	t_uv_pattern_at	uv_pattern_at;
	t_canvas		*cvs;
}	t_uv_image;

typedef struct s_point2d
{
	double	u;
	double	v;
}	t_point2d;

t_pattern	init_pattern(void);
void		set_pattern(t_obj *obj, t_pattern *patt);
void		set_pattern_transform(t_pattern *patt, t_mat4 m);

t_color		pattern_at_shape(const t_pattern *patt, const t_obj *obj, \
							t_tuple point);
t_pattern	*stripe_pattern(t_color a, t_color b);
t_pattern	*gradient_pattern(t_color a, t_color b);
t_pattern	*ring_pattern(t_color a, t_color b);
t_pattern	*checkers_pattern(t_color a, t_color b);

t_point2d	spherical_map(t_tuple p);
t_point2d	cylindrical_map(t_tuple p);
t_point2d	cone_map(t_tuple p);

t_color		pattern_at_3d_to_2d(const t_pattern *patt, t_tuple p);
t_pattern	*uv_checkers(double width, double height, t_color a, t_color b);
t_pattern	*uv_image(t_canvas *cvs);

t_tuple		**normal_map(char *filename);

#endif
