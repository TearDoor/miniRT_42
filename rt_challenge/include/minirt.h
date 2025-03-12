/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:40:49 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/12 21:30:50 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1000
# define HEIGHT 1000

# include "utils.h"
# include "rays.h"

typedef struct s_imgdata
{
	void	*img_ptr;
	char	*addr;
	int		bbp;
	int		size_line;
	int		endian;
}	t_imgdata;

typedef struct s_rt
{
	void		*mlx;
	void		*mlx_win;
	t_imgdata	img;
	t_world		world;
	t_canvas	canvas;
}	t_rt;

void		canvas_to_mlxwin(t_canvas *cvs, t_rt *mlx);

void		error_exit(char *msg);

t_canvas	cannon(void);
void		wall(void);
void		scene_one(t_rt rt);
void		earth(t_rt rt);

#endif
