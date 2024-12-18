/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:48:20 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/18 17:18:52 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "utils.h"
# include "libft.h"
# include "matrix.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_sphere
{
	int		id;
	t_tuple	origin;
	double	radius;
	t_mat4	transform;
}	t_sphere;

typedef struct s_intersect
{
	double		t;
	t_sphere	obj;
}	t_intersect;

t_ray		ray(t_tuple point, t_tuple vector);
t_tuple		position(t_ray ray, double distance);
t_intersect	*intersection(double t, t_sphere obj);
t_list		*check_intersect(t_sphere sphere, t_ray ray);
t_intersect	*hit(t_list *intersects);
t_ray		transform_ray(t_ray ray, t_mat4 transform);

t_sphere	sphere(int id);
void		set_transform(t_sphere *s, t_mat4 m);

#endif
