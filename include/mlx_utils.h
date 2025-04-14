/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:53 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/14 17:51:57 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "linux_keys.h"
# include "matrix.h"

//how much distance moved while dragging to register one move
# define STEPS_PER_WIDTH 15

typedef struct s_rt		t_rt;
typedef struct s_obj	t_obj;
typedef int				(*t_ctrl_funcptr)(t_keycodes, t_rt *);

typedef struct s_key_transfrom
{
	t_keycodes	key;
	t_mat4		transform;
}	t_key_transform;

typedef enum e_control
{
	CONTROL_CAM,
	CONTROL_LIGHTS,
	CONTROL_OBJ,
}	t_control;

enum e_mouse_status
{
	LEFT_PRESSED,
	RIGHT_PRESSED,
	NOT_PRESSED,
};

typedef struct s_mouse
{
	int					last_x;
	int					last_y;
	enum e_mouse_status	status;
	struct s_obj		*held_obj;
	t_tuple				offset;
	t_tuple				initial_normal;
	t_tuple				initial_point;
}	t_mouse;

int		init_rt(char *path, t_rt *rt);
void	ft_mlx_hooks(t_rt *rt);
void	mlx_showimg(t_rt *rt);
int		close_win(t_rt *rt);

int		keypress(t_keycodes key, t_rt *rt);
int		camera_transform(t_keycodes key, t_rt *rt);
int		light_control(t_keycodes key, t_rt *rt);
int		obj_control(t_keycodes key, t_rt *rt);

int		mouse_press(t_keycodes button, int x, int y, t_rt *rt);
int		mouse_release(t_keycodes key, int x, int y, t_rt *rt);
int		mouse_move(int x, int y, t_rt *rt);

t_obj	*pick_object(t_rt *rt, int x, int y);
t_tuple	get_obj_position(t_obj *obj);
void	move_object(t_rt *obj, int x, int y);
t_tuple	get_obj_position(t_obj *obj);

#endif
