/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:26:44 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/24 21:16:58 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "matrix.h"
# include "pattern.h"

struct	s_ray;

typedef struct s_material
{
	t_color		color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	t_pattern	*pattern;
	t_canvas	*normalmap;
	t_canvas	*image;
}	t_material;

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
	void		(*local_intersect)(struct s_obj*, struct s_ray, t_list **);
	t_tuple		(*local_normal_at)(t_tuple);
	t_mapping	mapping_func;
}	t_obj;

t_obj		*new_obj(void);
t_obj		*sphere(void);
t_obj		*plane(void);
t_obj		*cylinder(void);
t_obj		*cone(void);

/* utils */
void		set_transform(t_obj *o, t_mat4 m);
int			check_bounds(double t, struct s_ray ray, double max, double min);
void		free_object(void *ptr);

#endif
