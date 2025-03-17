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
	float	ratio;
	int		*color;
}	t_ambient;

typedef struct s_camera
{
	float	*coordinate;
	float	*vector;
	int		fov;
}	t_camera;

typedef struct s_light
{
	float	*coordinate;
	float	ratio;
	int		*color;
}	t_light;

typedef struct s_sphere
{
	float	*coordinate;
	float	diameter;
	int		*color;
}	t_sphere;

typedef struct s_plane
{
	float	*coordinate;
	float	*vector;
	int		*color;
}	t_plane;

typedef struct s_cylinder
{
	float	*coordinate;
	float	*vector;
	float	diameter;
	float	height;
	int		*color;
}	t_cylinder;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_minirt
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_minirt;

#endif