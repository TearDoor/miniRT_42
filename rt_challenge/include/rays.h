/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:48:20 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/08 16:56:03 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# define CYL_MAX 0.5
# define CYL_MIN -0.5
# define CONE_MAX 1
# define CONE_MIN 0

# include "utils.h"
# include "libft.h"
# include "matrix.h"
# include <stdlib.h>

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

typedef struct s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_lightparams
{
	t_material	m;
	t_light		light;
	t_tuple		point;
	t_tuple		eye_vec;
	t_tuple		normal_vec;
	int			in_shadow;
}	t_lightparams;

typedef enum e_obj_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYL,
	OBJ_CONE,
}	t_obj_type;

typedef struct s_obj
{
	t_obj_type	type;
	t_mat4		transform;
	t_mat4		inverse_transform;
	t_material	material;
	void		(*local_intersect)(struct s_obj, t_ray, t_list **);
	t_tuple		(*local_normal_at)(t_tuple);
}	t_obj;

typedef struct s_world
{
	t_list	*objs;
	size_t	obj_count;
	t_obj	*obj_arr;
	t_light	light;
}	t_world;

typedef struct s_intersect
{
	double	t;
	t_obj	obj;
}	t_intersect;

typedef struct s_comps
{
	double	t;
	t_obj	obj;
	t_tuple	point;
	t_tuple	eyev;
	t_tuple	normalv;
	int		inside;
	t_tuple	over_point;
}	t_comps;

typedef struct s_camera
{
	int		hsize;
	int		vsize;
	double	fov;
	t_mat4	transform;
	t_mat4	inverse_transform;
	double	half_width;
	double	half_height;
	double	pix_size;
}	t_camera;

/* Constructors */
t_ray		ray(t_tuple point, t_tuple vector);
t_intersect	*intersection(double t, t_obj obj);
t_light		point_light(t_color intensity, t_tuple position);
t_obj		*new_obj(void);
t_obj		*sphere(void);
t_obj		*plane(void);
t_obj		*cylinder(void);
t_obj		*cone(void);
t_material	material(void);
t_world		new_world(void);
t_world		default_world(void);
t_camera	new_camera(int hsize, int vsize, double fov);

/* ray intersection */
t_tuple		position(t_ray ray, double distance);
void		check_intersect(t_obj obj, t_ray ray, t_list **xs);
void		add_to_intersections(double t, t_obj obj, t_list **list);
t_obj		*list_to_array_obj(t_list *list);
t_list		*intersect_world(t_ray ray, t_world world);
t_intersect	*checkhit(t_list *intersects);
t_ray		transform_ray(t_ray ray, t_mat4 transform);

/* light and shading */
t_tuple		normal_at(t_obj sp, t_tuple point);
t_tuple		reflect(t_tuple v_in, t_tuple normal);
t_color		lighting(t_lightparams params);
t_color		color_at(t_world w, t_ray r);
int			is_shadowed(t_world w, t_tuple point);

void		set_transform(t_obj *o, t_mat4 m);

/* views and cameras */
t_mat4		view_transform(t_tuple from, t_tuple to, t_tuple up);
t_ray		ray_for_pixel(t_camera cam, int px, int py);
t_canvas	render(t_camera cam, t_world w);

/* utils */
int			check_bounds(double t, t_ray ray, double max, double min);

#endif
