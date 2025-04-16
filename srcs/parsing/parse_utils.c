/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 06:34:58 by root              #+#    #+#             */
/*   Updated: 2025/04/16 15:28:59 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static void	parse_decimal_part(char *arg, t_atod *d_arg, t_parse *rt)
{
	while (*arg)
	{
		if (*arg >= '0' && *arg <= '9')
		{
			if (!d_arg->decimal_point)
				d_arg->whole_num = d_arg->whole_num * 10 + (*arg - '0');
			else
			{
				d_arg->fraction += (double)(*arg - '0') / d_arg->divisor;
				d_arg->divisor *= 10;
			}
		}
		else if (*arg == '.')
		{
			if (d_arg->decimal_point)
				rt->decimal_error = 1;
			d_arg->decimal_point = 1;
		}
		else
			rt->decimal_error = 1;
		arg++;
	}
}

double	ft_atod(char *arg, t_parse *rt)
{
	t_atod	d_arg;

	d_arg.neg = 1;
	d_arg.whole_num = 0;
	d_arg.divisor = 10;
	d_arg.fraction = 0;
	d_arg.decimal_point = 0;
	while (*arg == ' ' || (*arg >= 9 && *arg <= 13))
		arg++;
	if (*arg == '-')
	{
		d_arg.neg = -1;
		arg++;
	}
	else if (*arg == '+')
		arg++;
	parse_decimal_part(arg, &d_arg, rt);
	// printf("result = %f\n", d_arg.neg * (d_arg.whole_num + d_arg.fraction)); // debug
	return (d_arg.neg * (d_arg.whole_num + d_arg.fraction));
}

/*
	This is essential for cases where info are separated by tab
*/
void	filter_line(char *line, char ***info)
{
	int		i;

	i = -1;
	while (line && line[++i])
		if (line[i] == '\t' || line[i] == '\n')
			line[i] = ' ';
	// printf("line = (%s)\n", line);
	*info = ft_split(line, ' ');
}

int	print_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	return (1);
}

int	validate_file(t_parse *rt)
{
	if (!rt->ambient.id)
		return (print_error("Missing ambient lighting (A)"));
	if (!rt->camera.id)
		return (print_error("Missing camera (C)"));
	if (!rt->light_list)
		return (print_error("Missing light (L)"));
	return (0);
}
