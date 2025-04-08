/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:33:35 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/29 14:54:01 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

t_color	color(double r, double g, double b)
{
	t_color	new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

void	print_color(t_color color)
{
	printf("r: %.5f g: %.5f b: %.5f\n", color.r, color.g, color.b);
}
