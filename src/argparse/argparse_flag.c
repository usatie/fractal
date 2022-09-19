/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:46 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 21:11:14 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdbool.h>
#include "argparse.h"
#include "libft.h"
#include "math.h"

static bool	contains_numeric(const char *s);

char	*parse_fractal_type(char *arg)
{
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		return (arg);
	else if (ft_strcmp(arg, "Julia") == 0)
		return (arg);
	else if (ft_strcmp(arg, "Barnsley") == 0)
		return (arg);
	else
		usage_err();
}

int	parse_julia_degree(const char *s)
{
	long	res;
	char	*endptr;

	if (!contains_numeric(s))
		usage_err();
	errno = 0;
	res = ft_strtol(s, &endptr, 10);
	if (errno != 0)
		usage_err();
	if (*endptr != '\0')
		usage_err();
	if (res < 0 || res >= 360)
		usage_err();
	return ((int)res);
}

static bool	contains_numeric(const char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s))
			return (true);
		s++;
	}
	return (false);
}
