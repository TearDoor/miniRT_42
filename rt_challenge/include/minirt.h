/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:40:49 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/31 10:50:03 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "utils.h"

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
}	t_imgdata;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

void		canvas_to_mlxwin(t_canvas *cvs, t_mlx *mlx);

t_canvas	cannon(void);
void		wall(void);
void		scene_one(void);

#endif
