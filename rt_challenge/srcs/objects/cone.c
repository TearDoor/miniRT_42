/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:33:42 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/01/06 16:00:00 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>

void	intersect_cone(t_obj cone, t_ray ray, t_list **list)
{
	double	a;
	double	b;
	double	c;

}

t_obj	*cone(void)
{
	t_obj	*new_cone;

	new_cone = new_obj();
	new_cone->type = OBJ_CONE;
	return (new_cone);
}
