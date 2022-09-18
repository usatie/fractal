/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:46 by susami            #+#    #+#             */
/*   Updated: 2022/09/18 18:25:12 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "fractol.h"
#include "libft.h"
#include "math.h"

t_fractal_type	parse_fractal_type(const char *arg);
int				parse_julia_param(const char *v, t_ctx *ctx);
static bool		contains_numeric(const char *s);

t_fractal_type	parse_fractal_type(const char *arg)
{
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		return (MANDELBROT);
	else if (ft_strcmp(arg, "Julia") == 0)
		return (JULIA);
	else if (ft_strcmp(arg, "Barnsley") == 0)
		return (BARNSLEY);
	else
		usage_err();
}

int	parse_julia_param(const char *v, t_ctx *ctx)
{
	long	res;
	char	*endptr;

	if (!contains_numeric(v))
		usage_err();
	errno = 0;
	res = ft_strtol(v, &endptr, 10);
	if (errno != 0)
		usage_err();
	if (*endptr != '\0')
		usage_err();
	if (res < 0 || res >= 360)
		usage_err();
	ctx->julia_degree = (int)res;
	return (0);
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
