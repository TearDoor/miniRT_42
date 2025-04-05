/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 07:02:40 by root              #+#    #+#             */
/*   Updated: 2025/03/31 11:35:20 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "parse.h"

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

typedef enum s_obj_id
{
	ZERO,
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	CYLINDER,
	SPHERE
}	t_obj_id;

typedef struct s_atod
{
	double	whole_num;
	double	fraction;
	int		decimal_point;
	int		neg;
	int		divisor;
}	t_atod;

typedef struct s_ambient
{
	t_obj_id	id;
	double		ratio;
	t_color		color;
}	t_ambient;

typedef struct s_camera
{
	t_obj_id	id;
	t_tuple		coordinate;
	t_tuple		vector;
	int			fov;
}	t_camera;

typedef struct s_light
{
	t_obj_id		id;
	double			*coordinate;
	double			ratio;
	double			*color;
	struct s_light	*next;
}	t_light;

typedef struct s_sphere
{
	t_obj_id	id;
	double		*coordinate;
	double		diameter;
	float		*color;
}	t_sphere;

typedef struct s_plane
{
	t_obj_id	id;
	double		*coordinate;
	double		*vector;
	float		*color;
}	t_plane;

typedef struct s_cylinder
{
	t_obj_id	id;
	double		*coordinate;
	double		*vector;
	double		diameter;
	double		height;
	float		*color;
}	t_cylinder;

typedef union s_shape
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plane		plane;
}	t_shape;

typedef struct s_obj
{
	t_obj_id		id;
	t_shape			shape;
	char			*texture_file;
	char			*bump_file;
	struct s_obj	*next;
}	t_obj;

typedef struct s_parse
{
	t_obj		*obj_list;
	t_light		*light_list;
	t_ambient	ambient;
	t_camera	camera;
}	t_parse;

#endif