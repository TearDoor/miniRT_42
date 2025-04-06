/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:48:25 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/06 20:08:14 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_KEYS_H
# define LINUX_KEYS_H

typedef enum e_keycodes
{
	ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_Q = 113,
	KEY_E = 101,
	KEY_R = 114,
	KEY_F = 102,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
	SPC = 32,
	BSPC = 65288,
	TAB = 65289,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	MB_L = 1,
	MB_R = 3,
	MW_UP = 4,
	MW_DOWN = 5,
}	t_keycodes;

#endif
