/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_put_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:30:53 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 23:48:03 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include "ft_printf.h"

void	ctx_put_config_fractal_mode(const t_ctx *ctx, int *height)
{
	char	str[128];

	if (ctx->fractal_type == mandelbrot)
		ft_sprintf(str, "fractal type: %s", "Mandelbrot");
	else if (ctx->fractal_type == julia)
		ft_sprintf(str, "fractal type: %s", "Julia");
	else if (ctx->fractal_type == barnsley)
		ft_sprintf(str, "fractal type: %s", "Barnsley");
	else
		ft_sprintf(str, "fractal type: %s", "Unknown");
	ctx_string_put(ctx, height, str);
}

void	ctx_put_config_color_mode(const t_ctx *ctx, int *height)
{
	char	str[128];

	if (ctx->color_mode == normal)
		ft_sprintf(str, "color mode: %s", "Normal");
	else if (ctx->color_mode == psyc)
		ft_sprintf(str, "color mode: %s", "Psychedelic");
	else
		ft_sprintf(str, "color mode: %s", "Unknown");
	ctx_string_put(ctx, height, str);
}

void	ctx_put_config_julia_mode(const t_ctx *ctx, int *height)
{
	char	str[128];

	if (ctx->julia_mode == normal)
		ft_sprintf(str, "julia mode: %s", "Normal");
	else if (ctx->julia_mode == psyc)
		ft_sprintf(str, "julia mode: %s", "Psychedelic");
	else
		ft_sprintf(str, "julia mode: %s", "Unknown");
	ctx_string_put(ctx, height, str);
}

void	ctx_put_config_max_loop(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "max_loop: %d", ctx->max_loop);
	ctx_string_put(ctx, height, str);
}

void	ctx_put_config_step(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "step[= 1 pixel] : %.20f", ctx->step);
	ctx_string_put(ctx, height, str);
}
