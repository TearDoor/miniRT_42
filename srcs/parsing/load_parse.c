/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:00:11 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/11 14:49:47 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "raytracing.h"
#include "minirt.h"

double	deg_to_rad(int deg)
{
	return ((double)deg * (M_PI / 180));
}

void	load_camera(t_camera *cam, t_parse_camera *p_cam)
{
	t_tuple	to_point;

	*cam = new_camera(WIDTH, HEIGHT, deg_to_rad(p_cam->fov));
	to_point = tuple_add(p_cam->coordinate, p_cam->vector);
	init_view_matrix(cam, p_cam->coordinate, to_point, vector(0, 1, 0));
}

void	load_lights(t_world *world, t_parse_light *p_light)
{
	t_parse_light	*ptr;
	t_light			*new_light;

	ptr = p_light;
	while (ptr)
	{
		new_light = point_light(ptr->color, ptr->coordinate, ptr->ratio);
		add_light_to_world(world, new_light);
		ptr = ptr->next;
	}
}

t_obj	*load_sphere(t_shape *p_sphere)
{
	t_obj	*new_sphere;

	new_sphere = plane();
	new_sphere->material.color = p_sphere->plane.color;
	return (new_sphere);
}

void	load_objects(t_world *world, t_parse_obj *p_obj_list)
{
	t_parse_obj				*ptr;
	t_obj					*new_obj;
	const t_obj_cons_ptr	obj_cons[] = {
	[SPHERE] = load_sphere,
	};

	ptr = p_obj_list;
	while (ptr)
	{
		ptr = ptr->next;
	}
}

void	load_world(t_world *world, t_parse *parse)
{
	*world = new_world();
	load_lights(world, parse->light_list);
	load_objects(world, parse->obj_list);
	world->ambient
		= color_scalar_mult(parse->ambient.color, parse->ambient.ratio);
}
