/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:13:44 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/19 21:49:22 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include <math.h>

/*
 * fires a ray from the surface of obj along the reflect vector
 * has a remaining argument to prevent infinite recursion
 * if two surfaces are parallel to each other
*/
t_color	reflected_color(const t_world *w, const t_comps *comps, int remaining)
{
	t_ray	reflect_ray;
	t_color	refl_color;

	if (equal(comps->obj->material.reflective, 0.0) || remaining == 0)
		return (color(0, 0, 0));
	reflect_ray = ray(comps->over_point, comps->reflectv);
	refl_color = color_at(*w, reflect_ray, remaining - 1);
	return (color_scalar_mult(refl_color, comps->obj->material.reflective));
}

static double	set_n(t_list *containers)
{
	t_obj	*last;

	if (containers == NULL)
		return (1.0);
	else
	{
		last = ft_lstlast(containers)->content;
		return (last->material.refractive_index);
	}
}

void	calculate_n(t_intersect *hit, t_comps *comps, t_list *xs)
{
	t_intersect	*curr_x;
	t_list		*containers;

	containers = NULL;
	while (xs)
	{
		curr_x = xs->content;
		if (curr_x == hit)
			comps->n1 = set_n(containers);
		if (lstfind(containers, (void *)curr_x->obj) != 0)
			lstfind_and_del(&containers, curr_x->obj);
		else
			ft_lstadd_back(&containers, ft_lstnew(curr_x->obj));
		if (curr_x == hit)
		{
			comps->n2 = set_n(containers);
			break ;
		}
		xs = xs->next;
	}
	ft_lstclear(&containers, nothing);
}

/*
 * Snell's law to calculate reflected color under total internal reflection
*/
t_color	refracted_color(const t_world *w, const t_comps *comps, int remaining)
{
	t_refrparams	refparams;
	t_tuple			direction;
	t_ray			refract_ray;
	t_color			refr_color;

	if (equal(comps->obj->material.transparency, 0.0) || remaining == 0)
		return (color(0, 0, 0));
	refparams.n_ratio = comps->n1 / comps->n2;
	refparams.cos_i = vector_dot_product(comps->eyev, comps->normalv);
	refparams.sin2_t = sq(refparams.n_ratio) * (1 - sq(refparams.cos_i));
	if (refparams.sin2_t > 1)
		return (color(0, 0, 0));
	refparams.cos_t = sqrt(1.0 - refparams.sin2_t);
	direction = tuple_scalar_mult(comps->normalv,
			refparams.n_ratio * refparams.cos_i - refparams.cos_t);
	direction = tuple_subtract(direction,
			tuple_scalar_mult(comps->eyev, refparams.n_ratio));
	refract_ray = ray(comps->under_point, direction);
	refr_color = color_at(*w, refract_ray, remaining - 1);
	return (color_scalar_mult(refr_color, comps->obj->material.transparency));
}

/*
 * approximation of the Fresnel effect
 * (where steep angle = weak reflection; shallow angle = strong reflection)
 * calculates reflectance which is the ratio of reflected vs refracted light
 */
double	schlick(t_comps *comps)
{
	double	cos;
	double	n;
	double	sin2_t;
	double	cos_t;
	double	r0;

	cos = vector_dot_product(comps->eyev, comps->normalv);
	if (comps->n1 > comps->n2)
	{
		n = comps->n1 / comps->n2;
		sin2_t = sq(n) * (1.0 - sq(cos));
		if (sin2_t > 1.0)
			return (1.0);
		cos_t = sqrt(1.0 - sin2_t);
		cos = cos_t;
	}
	r0 = sq((comps->n1 - comps->n2) / (comps->n1 + comps->n2));
	return (r0 + (1 - r0) * pow((1 - cos), 5));
}
