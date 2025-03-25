/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:53 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/25 22:51:33 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "linux_keys.h"

struct	s_rt;

int	close_win(struct s_rt *rt);
int	keypress(t_keycodes key, struct s_rt *rt);

#endif
