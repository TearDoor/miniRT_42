/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:28:10 by root              #+#    #+#             */
/*   Updated: 2025/04/09 16:38:38 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "struct.h"
# include "raytracing.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define NUM_ARG_FIXED 3
# define RESET_COLOR "\033[0m"
# define YELLOW "\033[33m"

// utils
int				print_error(char *msg);
void			filter_line(char *line, char ***info);
double			ft_atod(char *arg);
int				validate_file(t_parse *rt);

// free
void			free_arr(char **arr);
void			typecast_shape(t_parse_obj *tmp);
void			free_shape(t_parse *rt);

// parsing
int				parse_shape(t_obj_id id, char **info, t_parse *rt);
int				parse_file(int fd, t_parse *rt);
int				store_info(char **info, t_parse *rt);
int				parse_ambient(char **info, t_parse *rt);
int				parse_camera(char **info, t_parse *rt);
int				parse_light(char **info, t_parse *rt);
void			parse_plane(char **info, t_parse_obj *obj);
void			parse_sphere(char **info, t_parse_obj *obj);
void			parse_cylinder(char **info, t_parse_obj *obj);

//laod into world and camera
void			load_camera(t_camera *cam, t_parse_camera *parse);
void			load_world(t_world *world, t_parse *parse);

void			init_obj(t_parse_obj *obj, t_obj_id id, t_parse *rt);
t_parse_light	*init_light(t_parse_light *light, t_parse *rt);
void			init_txr_bump(t_parse_obj *obj, char **info);
int				ft_arrlen(char **arr);

#endif
