/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-10 07:02:40 by root              #+#    #+#             */
/*   Updated: 2025-03-10 07:02:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minirt.h"

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

typedef struct s_atof
{
	float	whole_num;
	float	fraction;
	int		decimal_point;
	int		neg;
	int		divisor;
}	t_atof;

typedef struct s_ambient
{
	t_obj_id	id;
	float		ratio;
	int			*color;
}	t_ambient;

typedef struct s_camera
{
	t_obj_id	id;
	float		*coordinate;
	float		*vector;
	int			fov;
}	t_camera;

typedef struct s_light
{
	t_obj_id	id;
	float		*coordinate;
	float		ratio;
	int			*color;
}	t_light;

typedef struct s_sphere
{
	t_obj_id	id;
	float		*coordinate;
	float		diameter;
	int			*color;
}	t_sphere;

typedef struct s_plane
{
	t_obj_id	id;
	float		*coordinate;
	float		*vector;
	int			*color;
}	t_plane;

typedef struct s_cylinder
{
	t_obj_id	id;
	float		*coordinate;
	float		*vector;
	float		diameter;
	float		height;
	int			*color;
}	t_cylinder;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

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

typedef struct s_minirt
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_obj		*obj_list;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
}	t_minirt;

#endif