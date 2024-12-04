/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:59:15 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/12/04 16:56:17 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

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

int	main(void)
{
	t_proj	proj;
	t_env	env;
	int		ticks;

	proj.position = point(0, 1, 0);
	proj.velocity = vector_normalize(vector(1, 1, 0));
	env.gravity = vector(0, -0.1, 0);
	env.wind = vector(-0.01, 0, 0);

	proj.velocity = tuple_scalar_mult(proj.velocity, 1.0);
	ticks = 0;
	while (proj.position.y > 0)
	{
		printf("position: X=%.2f Y=%.2f\n", proj.position.x, proj.position.y);
		printf("veclocity: X=%.2f Y=%.2f\n", proj.velocity.x, proj.velocity.y);
		proj = tick(proj, env);
		ticks++;
	}
	printf("position: X=%.2f Y=%.2f\n", proj.position.x, proj.position.y);
	printf("ticks: %d\n", ticks);
	return (0);
}
