/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:13:44 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/17 22:26:02 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

// a helper function to create a glassy sphere
t_obj	*glass_sphere(void)
{
	t_obj	*gsphere;

	gsphere = sphere();
	gsphere->material.transparency = 1.0;
	gsphere->material.refractive_index = 1.5;
	return (gsphere);
}

void	calculate_n(t_intersect *hit, t_comps *comps, t_list *xs)
{
	t_list		*ptr;
	t_intersect	*curr_x;
	t_list		*containers;
	t_obj		*last;

	containers = NULL;
	ptr = xs;
	while (ptr)
	{
		curr_x = ptr->content;
		if (curr_x == hit)
		{
			if (containers == NULL)
				comps->n1 = 1.0;
			else
			{
				last = ft_lstlast(containers)->content;
				comps->n1 = last->material.refractive_index;
			}
		}
		if (lstfind(containers, (void *)curr_x->obj) != 0)
			lstfind_and_del(&containers, curr_x->obj);
		else
			ft_lstadd_back(&containers, ft_lstnew(curr_x->obj));
		if (curr_x == hit)
		{
			if (containers == NULL)
				comps->n2 = 1.0;
			else
			{
				last = ft_lstlast(containers)->content;
				comps->n2 = last->material.refractive_index;
			}
			break ;
		}
		ptr = ptr->next;
	}
	ft_lstclear(&containers, nothing);
}
