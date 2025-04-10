/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_pattern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:26:14 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/10 15:15:35 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "minirt.h"

/*
 * finds the corresponding 2d point of a 3d point
 * by calling the mapping function of the shape assigned to the pattern
 * during set_pattern()
 */
t_color	pattern_at_3d_to_2d(const t_pattern *patt, t_tuple p)
{
	t_point2d		uv_point;
	t_uv_pattern	*uv_patt;

	uv_patt = (t_uv_pattern *)patt;
	uv_point = patt->mapping_func(p);
	return (uv_patt->uv_pattern_at(patt, uv_point));
}

t_canvas	*parse_map(char *filename)
{
	char		*file_exten;
	t_canvas	*cvs;

	file_exten = ft_strrchr(filename, '.');
	if (!file_exten || ft_strcmp(file_exten, ".ppm") != 0)
		error_exit("Can only read from ppm files");
	cvs = malloc(sizeof(t_canvas));
	*cvs = canvas_from_ppm(filename);
	return (cvs);
}
