/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:46 by susami            #+#    #+#             */
/*   Updated: 2022/09/12 15:36:39 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "fractol.h"
#include "libft.h"
#include "math.h"

#include <stdio.h>

t_fractal_type	parse_fractal_type(const char *arg);
int				parse_julia_param(const char *v, t_ctx *ctx);

t_fractal_type	parse_fractal_type(const char *arg)
{
	printf("parse_fractal_type: %s\n", arg);
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		return (mandelbrot);
	else if (ft_strcmp(arg, "Julia") == 0)
		return (julia);
	else if (ft_strcmp(arg, "Barnsley") == 0)
		return (barnsley);
	else
		usage_err();
}

int	parse_julia_param(const char *v, t_ctx *ctx)
{
	long	res;
	char	*endptr;

	errno = 0;
	res = ft_strtol(v, &endptr, 10);
	if (errno != 0)
		usage_err();
	if (*endptr != '\0')
		usage_err();
	if (res < 0 || res >= 360)
		usage_err();
	ctx->c_radian = M_PI / 180 * (double)res;
	return (0);
}
