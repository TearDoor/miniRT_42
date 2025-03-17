/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-10 06:34:58 by root              #+#    #+#             */
/*   Updated: 2025-03-10 06:34:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_neg(char **arg, int *neg)
{
	while (**arg == ' ' || (**arg >= 9 && **arg <= 13))
		(*arg)++;
	if (**arg == '-')
	{
		*neg = -1;
		(*arg)++;
	}
	else if (**arg == '+')
		(*arg)++;
}

float	ft_atof(char *arg)
{
	t_atof	f_arg;
	
	f_arg.neg = 1;
	f_arg.whole_num = 0;
	f_arg.divisor = 10;
	f_arg.fraction = 0;
	f_arg.decimal_point = 0;
	check_neg(&arg, &f_arg.neg);
	while (*arg)
	{
		if (*arg >= '0' && *arg <= '9')
		{
			if (!f_arg.decimal_point)
			f_arg.whole_num = f_arg.whole_num * 10 + (*arg - '0');
			else if (f_arg.decimal_point)
			{
				// printf("arg = %c\n", *arg); // debug
				f_arg.fraction += (float)(*arg - '0') / f_arg.divisor;
				// printf("fraction = %f\n", f_arg.fraction); //debug
				f_arg.divisor *= 10;
			}
		}
		else if (*arg == '.')
			f_arg.decimal_point = 1;
		arg++;
	}
	// printf("result = %f\n", neg * (whole_num + fraction)); // debug
	return (f_arg.neg * (f_arg.whole_num + f_arg.fraction));
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
	printf("line = (%s)\n", line);
	*info = ft_split(line , ' ');
}

int	print_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	return (1);
}

int	validate_file(t_minirt *rt)
{
	if (!rt->ambient)
    	return (print_error("Missing ambient lighting (A)"));
	if (!rt->camera)
		return (print_error("Missing camera (C)"));
	if (!rt->light)
		return (print_error("Missing light (L)"));
	return (0);
}
