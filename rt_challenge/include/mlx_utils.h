/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:53 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/30 19:07:16 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "linux_keys.h"
# include "matrix.h"

struct	s_rt;

typedef struct s_key_transfrom
{
	t_keycodes	key;
	t_mat4		transform;
}	t_key_transform;

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
}	t_mouse;

void	ft_mlx_hooks(struct s_rt *rt);
void	mlx_showimg(struct s_rt *rt);
int		close_win(struct s_rt *rt);

int		keypress(t_keycodes key, struct s_rt *rt);

int		mouse_press(t_keycodes button, int x, int y, struct s_rt *rt);
int		mouse_release(t_keycodes key, int x, int y, struct s_rt *rt);
int		mouse_move(int x, int y, struct s_rt *rt);

#endif
