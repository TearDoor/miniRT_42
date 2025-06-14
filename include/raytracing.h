/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:48:20 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/19 21:50:24 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "utils.h"
# include "libft.h"
# include "matrix.h"
# include "pattern.h"
# include "objects.h"

//max bounce for reflections
# define MAX_REFLECT 4

//refractive index
# define VACUUM 1.0
# define GLASS 1.5

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_light
{
	t_color	intensity;
	t_tuple	position;
	int		on;
}	t_light;

typedef struct s_comps
{
	double	t;
	t_obj	*obj;
	t_tuple	point;
	t_tuple	eyev;
	t_tuple	normalv;
	t_tuple	reflectv;
	int		inside;
	t_tuple	over_point;
	double	n1;
	double	n2;
	t_tuple	under_point;
}	t_comps;

typedef struct s_lightparams
{
	t_material	m;
	t_obj		*obj;
	t_light		light;
	t_tuple		point;
	t_tuple		eye_vec;
	t_tuple		normal_vec;
	int			in_shadow;
}	t_lightparams;

typedef struct s_world
{
	t_list	*objs;
	t_list	*lights;
	size_t	obj_count;
	t_color	ambient;
}	t_world;

typedef struct s_intersect
{
	double	t;
	t_obj	*obj;
}	t_intersect;

typedef struct s_camera
{
	int		hsize;
	int		vsize;
	double	fov;
	t_mat4	initial_transform;
	t_mat4	transform;
	t_mat4	inverse_transform;
	double	half_width;
	double	half_height;
	double	pix_size;
}	t_camera;

typedef struct s_refrparams
{
	double	n_ratio;
	double	cos_i;
	double	sin2_t;
	double	cos_t;
}	t_refrparams;

/* Constructors */
t_ray		ray(t_tuple point, t_tuple vector);
t_intersect	*intersection(double t, t_obj *obj);
t_light		*point_light(t_color color, t_tuple position, double ratio);
t_world		new_world(void);
t_world		default_world(void);
void		free_world(t_world *w);
t_camera	new_camera(int hsize, int vsize, double fov);

/* adding things to world */
void		add_obj_to_world(t_world *w, t_obj *obj);
void		add_light_to_world(t_world *w, t_light *light);

/* ray intersection */
t_tuple		position(t_ray ray, double distance);
void		check_intersect(t_obj *obj, t_ray ray, t_list **list);
void		add_to_intersections(double t, t_obj *obj, t_list **list);
t_obj		*list_to_array_obj(t_list *list);
t_list		*intersect_world(t_ray ray, t_world world);
t_intersect	*checkhit(t_list *intersects);
t_ray		transform_ray(t_ray ray, t_mat4 transform);

/* light and shading */
t_tuple		normal_at(t_obj *obj, t_tuple point);
t_tuple		reflect(t_tuple v_in, t_tuple normal);
t_color		lighting(t_lightparams params);
t_color		color_at(t_world w, t_ray r, int remaining);
int			is_shadowed(t_world w, t_tuple point, t_light *light);

/* refraction */
t_obj		*glass_sphere(void);
t_color		reflected_color(const t_world *w, const t_comps *comps,
				int remaining);
void		calculate_n(t_intersect *hit, t_comps *comps, t_list *xs);
t_color		refracted_color(const t_world *w, const t_comps *comps,
				int remaining);
double		schlick(t_comps *comps);

/* views and cameras */
void		init_view_matrix(t_camera *cam, t_tuple from, t_tuple to,
				t_tuple up);
t_ray		ray_for_pixel(t_camera cam, int px, int py);
t_canvas	render(t_camera cam, t_world w);

#endif
