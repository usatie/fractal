/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:36:33 by susami            #+#    #+#             */
/*   Updated: 2022/07/29 11:11:02 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include <math.h>

void	ctx_string_put(t_ctx *ctx, int *height, char *str);

void	ctx_put_fractal_mode(t_ctx *ctx, int *height)
{
	char	str[128];

	if (ctx->fractal_type == Mandelbrot)
		ft_sprintf(str, "fractal type: %s", "Mandelbrot");
	else if (ctx->fractal_type == Julia)
		ft_sprintf(str, "fractal type: %s", "Julia");
	else if (ctx->fractal_type == Barnsley)
		ft_sprintf(str, "fractal type: %s", "Barnsley");
	else
		ft_sprintf(str, "fractal type: %s", "Unknown");
	ctx_string_put(ctx, height, str);
}

void	ctx_put_color_mode(t_ctx *ctx, int *height)
{
	char	str[128];

	if (ctx->color_mode == Normal)
		ft_sprintf(str, "color mode: %s", "Normal");
	else if (ctx->color_mode == Psyc)
		ft_sprintf(str, "color mode: %s", "Psychedelic");
	else
		ft_sprintf(str, "color mode: %s", "Unknown");
	ctx_string_put(ctx, height, str);
}

void	ctx_put_julia_mode(t_ctx *ctx, int *height)
{
	char	str[128];

	if (ctx->julia_mode == Normal)
		ft_sprintf(str, "julia mode: %s", "Normal");
	else if (ctx->julia_mode == Psyc)
		ft_sprintf(str, "julia mode: %s", "Psychedelic");
	else
		ft_sprintf(str, "julia mode: %s", "Unknown");
	ctx_string_put(ctx, height, str);
}
