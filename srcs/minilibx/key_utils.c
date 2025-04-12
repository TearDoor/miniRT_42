/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:42:04 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/12 22:12:10 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linux_keys.h"
#include "mlx_utils.h"
#include "minirt.h"
#include "raytracing.h"
#include <stdio.h>

int	camera_transform(t_keycodes key, t_rt *rt)
{
	const t_key_transform	cam_keys[] = {
	{UP, translate_mat(0, -1, 0)}, {DOWN, translate_mat(0, 1, 0)},
	{LEFT, translate_mat(-1, 0, 0)}, {RIGHT, translate_mat(1, 0, 0)},
	{KEY_Q, rotation_z(-M_PI / 16)}, {KEY_E, rotation_z(M_PI / 16)},
	{KEY_W, rotation_x(-M_PI / 16)}, {KEY_S, rotation_x(M_PI / 16)},
	{KEY_A, rotation_y(M_PI / 16)}, {KEY_D, rotation_y(-M_PI / 16)},
	{0, id_matrix()},
	};
	const t_key_transform	*ptr;

	ptr = cam_keys;
	while (ptr->key != 0)
	{
		if (key == ptr->key)
		{
			rt->cam.transform = matrix_mult(ptr->transform, rt->cam.transform);
			rt->low_res = 1;
			mlx_showimg(rt);
			return (1);
		}
		ptr++;
	}
	return (0);
}

static int	light_transform(t_keycodes key, t_light *light)
{
	if (key == KEY_W)
		++light->position.y;
	else if (key == KEY_S)
		--light->position.y;
	else if (key == KEY_A)
		--light->position.x;
	else if (key == KEY_D)
		++light->position.x;
	else if (key == KEY_R)
		++light->position.z;
	else if (key == KEY_F)
		--light->position.z;
	else
		return (0);
	return (1);
}

int	light_control(t_keycodes key, t_rt *rt)
{
	static t_list	*selected_light_node = NULL;
	t_light			*selected_light;

	if (selected_light_node == NULL)
		selected_light_node = rt->world.lights;
	if (key == TAB)
	{
		if (selected_light_node->next == NULL)
			selected_light_node = rt->world.lights;
		else
			selected_light_node = selected_light_node->next;
	}
	selected_light = selected_light_node->content;
	if (light_transform(key, selected_light))
	{
		mlx_showimg(rt);
		return (1);
	}
	else
		return (0);
}

/*
* looks for the object's current position
* moves it to the world origin, apply rotation, then move it back
*/
static int	obj_transform(t_keycodes key, t_obj *obj)
{
	const t_key_transform	cam_keys[] = {
	{KEY_Q, rotation_z(-M_PI / 16)}, {KEY_E, rotation_z(M_PI / 16)},
	{KEY_W, rotation_x(-M_PI / 16)}, {KEY_S, rotation_x(M_PI / 16)},
	{KEY_A, rotation_y(M_PI / 16)}, {KEY_D, rotation_y(-M_PI / 16)},
	{0, id_matrix()},
	};
	const t_key_transform	*ptr;
	t_tuple					pos;

	ptr = cam_keys;
	while (ptr->key != 0)
	{
		if (key == ptr->key)
		{
			pos = get_obj_position(obj);
			apply_transform(obj, translate_mat(-pos.x, -pos.y, -pos.z));
			apply_transform(obj, ptr->transform);
			apply_transform(obj, translate_mat(pos.x, pos.y, pos.z));
			return (1);
		}
		ptr++;
	}
	return (0);
}

int	obj_control(t_keycodes key, t_rt *rt)
{
	static t_list	*selected_obj_node = NULL;
	t_obj			*selected_obj;

	if (selected_obj_node == NULL)
		selected_obj_node = rt->world.objs;
	if (key == TAB)
	{
		if (selected_obj_node->next == NULL)
			selected_obj_node = rt->world.objs;
		else
			selected_obj_node = selected_obj_node->next;
	}
	selected_obj = selected_obj_node->content;
	if (obj_transform(key, selected_obj))
	{
		mlx_showimg(rt);
		return (1);
	}
	else
		return (0);
}
