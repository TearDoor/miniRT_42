/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:48:20 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/20 21:37:21 by tkok-kea         ###   ########.fr       */
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

typedef struct s_light
{
	t_color	intensity;
	t_tuple	position;
}	t_light;

typedef struct s_phong
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
}	t_phong;

typedef struct s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_sphere
{
	int			id;
	t_tuple		origin;
	double		radius;
	t_mat4		transform;
	t_material	material;
}	t_sphere;

typedef struct s_intersect
{
	double		t;
	t_sphere	obj;
}	t_intersect;

/* Constructors */
t_ray		ray(t_tuple point, t_tuple vector);
t_intersect	*intersection(double t, t_sphere obj);
t_light		point_light(t_color intensity, t_tuple position);
t_sphere	sphere(int id);
t_material	material(void);

/* basic ray intersection */
t_tuple		position(t_ray ray, double distance);
t_list		*check_intersect(t_sphere sphere, t_ray ray);
t_intersect	*hit(t_list *intersects);
t_ray		transform_ray(t_ray ray, t_mat4 transform);

/* light and shading */
t_tuple		normal_at(t_sphere sp, t_tuple point);
t_tuple		reflect(t_tuple v_in, t_tuple normal);
t_color		lighting(t_material m, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv);

void		set_transform(t_sphere *s, t_mat4 m);

#endif
