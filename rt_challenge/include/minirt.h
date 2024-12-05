/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:40:49 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/05 21:12:48 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include "utils.h"

typedef  struct s_imgdata
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

t_canvas	cannon(void);

#endif
