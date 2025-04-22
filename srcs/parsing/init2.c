/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:54:13 by hni-xuan            #+#    #+#           */
/*   Updated: 2025/04/18 16:49:43 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

t_parse_light	*init_light(t_parse_light *light, t_parse *rt)
{
	t_parse_light	*tmp;

	light = ft_calloc(sizeof(t_parse_light), 1);
	light->next = NULL;
	if (!(rt->light_list))
		rt->light_list = light;
	else
	{
		tmp = rt->light_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = light;
	}
	return (light);
}

void	init_cy_cone(t_cy_cone *cy_cone, char **coords,
			char **vector, t_parse *rt)
{
	int		i;

	i = -1;
	while (++i < NUM_ARG_FIXED)
	{
		cy_cone->coordinate.elems[i] = ft_atod(coords[i], rt);
		cy_cone->vector.elems[i] = ft_atod(vector[i], rt);
	}
	cy_cone->coordinate.w = 1;
	cy_cone->vector.w = 0;
	cy_cone->vector = vector_normalize(cy_cone->vector);
}

void	init_plane(t_plane *plane, char **coords, char **vector, t_parse *rt)
{
	int		i;

	i = -1;
	while (++i < NUM_ARG_FIXED)
	{
		plane->coordinate.elems[i] = ft_atod(coords[i], rt);
		plane->vector.elems[i] = ft_atod(vector[i], rt);
	}
	plane->coordinate.w = 1;
	plane->vector.w = 0;
	plane->vector = vector_normalize(plane->vector);
}
