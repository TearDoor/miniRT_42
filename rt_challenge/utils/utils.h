/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:16:09 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/20 18:11:19 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef union u_tuple
{
	double	elems[4];
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
}	t_tuple;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_canvas
{
	int		width;
	int		height;
	t_color	**pixels;
}	t_canvas;

t_tuple		point(double x, double y, double z);
t_tuple		vector(double x, double y, double z);
void		print_tuple(t_tuple tuple);
int			tuple_equal(t_tuple t1, t_tuple t2);

t_tuple		tuple_add(t_tuple t1, t_tuple t2);
t_tuple		tuple_subtract(t_tuple t1, t_tuple t2);
t_tuple		tuple_negate(t_tuple tup);
t_tuple		tuple_scalar_mult(t_tuple tup, double scalar);
t_tuple		tuple_scaler_div(t_tuple tup, double scalar);

double		vector_magnitude(t_tuple vec);
t_tuple		vector_normalize(t_tuple vec);
double		vector_dot_product(t_tuple v1, t_tuple v2);
t_tuple		vector_cross_product(t_tuple v1, t_tuple v2);

t_color		color(double r, double g, double b);
void		print_color(t_color color);

t_color		color_add(t_color c1, t_color c2);
t_color		color_subtract(t_color c1, t_color c2);
t_color		color_mult(t_color c1, t_color c2);
t_color		color_scalar_mult(t_color color, double scalar);
int			clamp(double val);

t_canvas	canvas(int width, int height);
void		write_pixel(t_canvas c, int x, int y, t_color color);
void		canvas_to_ppm(t_canvas canvas);

int			equal(double a, double b);

#endif
