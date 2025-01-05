/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:59:15 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/05 16:12:33 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx.h"
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 550

typedef struct s_proj
{
	t_tuple	position;
	t_tuple	velocity;
}	t_proj;

typedef struct s_env
{
	t_tuple	gravity;
	t_tuple	wind;
}	t_env;

t_proj	tick(t_proj proj, t_env env)
{
	proj.position = tuple_add(proj.position, proj.velocity);
	proj.velocity = tuple_add(proj.velocity, env.gravity);
	proj.velocity = tuple_add(proj.velocity, env.wind);
	return (proj);
}

t_canvas	cannon(void)
{
	t_proj	proj;
	t_env	env;
	int		ticks;
	t_canvas	cvs;
	t_color		c;

	proj.position = point(0, 1, 0);
	proj.velocity = vector_normalize(vector(1, 1.8, 0));
	env.gravity = vector(0, -0.1, 0);
	env.wind = vector(-0.01, 0, 0);

	cvs = canvas(WIDTH, HEIGHT);
	c = color(0.5, 0.5, 0.5);

	proj.velocity = tuple_scalar_mult(proj.velocity, 11.25);
	ticks = 0;
	while (proj.position.y > 0)
	{
		printf("position: X=%.2f Y=%.2f\n", proj.position.x, proj.position.y);
		printf("veclocity: X=%.2f Y=%.2f\n", proj.velocity.x, proj.velocity.y);
		write_pixel(cvs, proj.position.x, HEIGHT - proj.position.y, c);
		proj = tick(proj, env);
		ticks++;
	}
	printf("position: X=%.2f Y=%.2f\n", proj.position.x, proj.position.y);
	printf("ticks: %d\n", ticks);
	return (cvs);
}
