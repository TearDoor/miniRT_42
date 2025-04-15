/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:28:10 by root              #+#    #+#             */
/*   Updated: 2025/04/14 16:54:01 by hni-xuan         ###   ########.fr       */
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

typedef t_obj	*(*t_obj_cons_ptr)(t_shape *);

// utils
int				print_error(char *msg);
void			filter_line(char *line, char ***info);
double			ft_atod(char *arg, t_parse *rt);
int				validate_file(t_parse *rt);

// free
void			free_arr(char **arr);
void			free_shape(t_parse *rt);

// parsing
int				parse_shape(t_obj_id id, char **info, t_parse *rt);
int				parse_file(int fd, t_parse *rt);
int				store_info(char **info, t_parse *rt);
int				parse_ambient(char **info, t_parse *rt);
int				parse_camera(char **info, t_parse *rt);
int				parse_light(char **info, t_parse *rt);
int				parse_plane(char **info, t_parse_obj *obj, t_parse *rt);
int				parse_sphere(char **info, t_parse_obj *obj, t_parse *rt);
int				parse_cy_cone(char **info, t_parse_obj *obj, t_parse *rt);

//laod into world and camera
void			load_camera(t_camera *cam, t_parse_camera *parse);
void			load_world(t_world *world, t_parse *parse);

//load objects
t_obj			*load_sphere(t_shape *p_sphere);
t_obj			*load_plane(t_shape *p_plane);
t_obj			*load_cyl(t_shape *p_cyl);
t_obj			*load_cone(t_shape *p_cone);
t_obj			*load_dcone(t_shape *p_cone);
t_obj			*load_cyl_cone(t_obj *obj, t_shape *p_cyl_cone);

void			init_obj(t_parse_obj *obj, t_obj_id id, t_parse *rt);
t_parse_light	*init_light(t_parse_light *light, t_parse *rt);
void			init_txr_bump(t_parse_obj *obj, char **info);
int				ft_arrlen(char **arr);
void			align_orientation(t_obj *obj, t_tuple orient);

int				check_coords_vector(char **info, char ***vector, char ***coords);
int				check_color(char **info, char ***color, char ***coords, char ***vector);
int				check_arrlen(char **arr, int length);

#endif
