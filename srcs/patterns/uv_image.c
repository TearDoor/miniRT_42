/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:24:50 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/27 21:52:35 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "objects.h"
#include <math.h>

static t_color	pixel_at(t_canvas *cvs, int x, int y)
{
	return (cvs->pixels[y][x]);
}

t_color	uv_image_pattern_at(const t_pattern *patt, t_point2d uv)
{
	t_uv_image	*uv_img;
	double		x;
	double		y;

	uv_img = (t_uv_image *)patt;
	uv.v = 1 - uv.v;
	x = uv.u * (uv_img->cvs->width - 1);
	y = uv.v * (uv_img->cvs->height - 1);
	return (pixel_at(uv_img->cvs, round(x), round(y)));
}

t_pattern	*uv_image(t_canvas *cvs)
{
	t_uv_image	*uv_image;

	if (cvs == NULL)
	{
		ft_putendl_fd("No image saved in object's material", STDERR_FILENO);
		return (NULL);
	}
	uv_image = malloc(sizeof(t_uv_image));
	uv_image->pattern = init_pattern();
	uv_image->pattern.pattern_at = pattern_at_3d_to_2d;
	uv_image->uv_pattern_at = &uv_image_pattern_at;
	uv_image->cvs = cvs;
	return ((t_pattern *)uv_image);
}

void	set_img_from_file(t_obj *obj, char *filename)
{
	obj->material.image = parse_map(filename);
}
