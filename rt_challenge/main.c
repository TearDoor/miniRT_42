/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:59:15 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/05 16:49:12 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "mlx.h"

int	main(void)
{
	t_color		c1, c2, c3;
	void		*mlx;

	mlx = mlx_init();
	c1 = color(1.5, 0, 0);
	c2 = color(0, 0.5, 0);
	c3 = color(-0.5, 0, 1);
	return (0);
}
