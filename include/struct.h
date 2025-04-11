/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 07:02:40 by root              #+#    #+#             */
/*   Updated: 2025/04/11 17:58:54 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "utils.h"

typedef enum e_obj_id
{
	ZERO,
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	CYLINDER,
	SPHERE,
	SINGLE_CONE,
	DOUBLE_CONE
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

typedef struct s_parse_camera
{
	t_obj_id	id;
	t_tuple		coordinate;
	t_tuple		vector;
	int			fov;
}	t_parse_camera;

typedef struct s_parse_light
{
	t_obj_id				id;
	t_tuple					coordinate;
	double					ratio;
	t_color					color;
	struct s_parse_light	*next;
}	t_parse_light;

typedef struct s_sphere
{
	t_obj_id	id;
	t_tuple		coordinate;
	double		diameter;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_obj_id	id;
	t_tuple		coordinate;
	t_tuple		vector;
	t_color		color;
}	t_plane;

typedef struct s_cy_cone
{
	t_obj_id	id;
	t_tuple		coordinate;
	t_tuple		vector;
	double		diameter;
	double		height;
	t_color		color;
}	t_cy_cone;

typedef struct s_cone
{
	t_obj_id	id;
	
}	t_cone;

typedef union s_shape
{
	t_sphere	sphere;
	t_cy_cone	cy_cone;
	t_plane		plane;
}	t_shape;

typedef struct s_parse_obj
{
	t_obj_id			id;
	t_shape				shape;
	char				*texture_file;
	char				*bump_file;
	struct s_parse_obj	*next;
}	t_parse_obj;

typedef struct s_parse
{
	t_parse_obj		*obj_list;
	t_parse_light	*light_list;
	t_ambient		ambient;
	t_parse_camera	camera;
}	t_parse;

#endif
