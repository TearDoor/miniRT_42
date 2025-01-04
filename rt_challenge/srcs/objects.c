/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:54 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/04 21:40:52 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_obj	*new_obj(void)
{
	t_obj	*newobj;

	newobj = malloc(sizeof(t_obj));
	newobj->transform = id_matrix();
	newobj->material = material();
	return (newobj);
}

void	line_sphere_intersection(t_obj sphere, t_ray ray, t_list **list)
{
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;
	double	roots[2];

	sphere_to_ray = tuple_subtract(ray.origin, point(0, 0, 0));
	a = vector_dot_product(ray.direction, ray.direction);
	b = 2 * vector_dot_product(ray.direction, sphere_to_ray);
	c = vector_dot_product(sphere_to_ray, sphere_to_ray) - 1;
	if (!solve_quadratic(a, b, c, roots))
		return ;
	lstadd_sorted(list, ft_lstnew((void *)intersection(roots[0], sphere)), \
					&lstcmp_xs);
	lstadd_sorted(list, ft_lstnew((void *)intersection(roots[1], sphere)), \
					&lstcmp_xs);
}

t_tuple	sphere_normal_at(t_tuple local_point)
{
	return (vector(local_point.x, local_point.y, local_point.z));
}

t_obj	*sphere(int id)
{
	t_obj	*new;

	new = new_obj();
	new->type = OBJ_SPHERE;
	new->local_intersect = &line_sphere_intersection;
	new->local_normal_at = &sphere_normal_at;
	return (new);
}
