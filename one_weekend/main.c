/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:43:05 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/01 22:14:51 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	img_width;
	int	img_height;
	double	r;
	double	g;
	int		ir;
	int		ig;

	img_width = 256;
	img_height = 256;
	printf("P3\n");
	printf("%d %d\n255\n", img_width, img_height);
	for (int j = 0; j < img_height; j++)
		for (int i = 0; i < img_width; i++)
		{
			r = (double)i / (img_width - 1);
			g = (double)j / (img_height - 1);
			ir = (int)(255.999 * r);
			ig = (int)(255.999 * g);
			printf("%d %d 0\n", ir, ig);
		}
	return (0);
}
