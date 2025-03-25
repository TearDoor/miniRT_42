/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:40:49 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/25 14:43:24 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 500
# define HEIGHT 500
# define UI_PAD	300

# include "utils.h"
# include "raytracing.h"

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
	t_camera	cam;
}	t_rt;

void		ft_mlx_pixel_put(t_imgdata *img, int x, int y, t_color color);
void		render_to_mlximg(t_camera *cam, t_world *w, t_imgdata *img);
void		canvas_to_mlxwin(t_canvas *cvs, t_rt *mlx);
void		ft_mlx_hooks(t_rt *rt);
void		mlx_showimg(t_rt *rt);

void		error_exit(char *msg);

t_canvas	cannon(void);
void		wall(void);
void		scene_one(t_rt rt);
void		earth(t_rt *rt);
void		leak_test(t_rt *rt);

#endif
