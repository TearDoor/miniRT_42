/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   earth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:24:46 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/03/13 22:33:48 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_tuple	color_to_normal(t_color clr)
{
	double	x;
	double	y;
	double	z;

	x = (clr.r * 2.0) - 1.0;
	y = (clr.g * 2.0) - 1.0;
	z = (clr.b * 2.0) - 1.0;
	return (vector(x, y, z));
}

t_tuple	**colormap_to_normalmap(t_canvas *cvs)
{
	t_tuple	**normals;
	int		i;
	int		j;

	normals = malloc(sizeof(t_tuple *) * cvs->height + 1);
	printf("%d %d\n", cvs->width, cvs->height);
	j = 0;
	while (j < cvs->height)
	{
		normals[j] = malloc(sizeof(t_tuple) * cvs->width);
		i = 0;
		while (i < cvs->width)
		{
			normals[j][i] = color_to_normal(cvs->pixels[j][i]);
			i++;
		}
		j++;
	}
	normals[j] = NULL;
	return (normals);
}

void	earth(t_rt rt)
{
	t_world		w;
	t_camera	cam;
	t_obj		*s1;
	t_canvas	temp;
	t_tuple		**normals;

	temp = canvas_from_ppm("earthbump1k.ppm");
	normals = colormap_to_normalmap(&temp);
	free_split((void **)normals);
	w = new_world();
	w.light = point_light(color(1, 1, 1), point(0, 1, -2));
	s1 = sphere();
	t_canvas img = canvas_from_ppm("earthmap1k.ppm");
	s1->material.ambient = 0.5;
	s1->material.specular = 0.1;
	set_transform(s1, scaling_mat(1.5, 1.5, 1.5));
	s1->material.pattern = uv_image(&img);
	add_obj_to_world(&w, s1);
	cam = new_camera(WIDTH, HEIGHT, M_PI / 3);
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 0, 0), vector(0, 1, 0));
	rt.canvas = render(cam, w);
	canvas_to_mlxwin(&rt.canvas, &rt);
}
