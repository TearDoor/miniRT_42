/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-09 13:28:10 by root              #+#    #+#             */
/*   Updated: 2025-03-09 13:28:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft_42/libft.h"
# include "struct.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <mlx.h>

# define COLOR_RGB 3
# define COORDS_XYZ 3
# define VECTORS 3
# define W_WIDTH 800
# define W_HEIGHT 800
# define RESET_COLOR "\033[0m"
# define YELLOW "\033[33m"

// utils
int			print_error(char *msg);
void		filter_line(char *line, char ***info);
float		ft_atof(char *arg);
int			validate_file(t_minirt *rt);

// free
void		free_arr(char **arr);
void		free_acl_plane(t_minirt *rt);
void		free_shape(t_minirt *rt);

int		close_window(t_minirt *rt);
void	execute_minirt(t_minirt *rt);
int		handle_keypress(int keycode, t_minirt *rt);

// parsing
t_minirt	*parse_file(int fd);
void		store_info(char **info, t_minirt *rt);
void		parse_ambient(char **info, t_minirt *rt);
void		parse_camera(char **info, t_minirt *rt);
void		parse_light(char **info, t_minirt *rt);
void		parse_plane(char **info, t_minirt *rt);
void		parse_sphere(char **info, t_minirt *rt);
void		parse_cylinder(char **info, t_minirt *rt);

#endif