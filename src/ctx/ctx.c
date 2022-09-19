/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:02:42 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 14:52:30 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include <math.h>

#define INITIAL_JULIA_DEGREE 150

double	pixel_width(int zoom_level)
{
	static int		prev_zoom_level = 0;
	static double	cache = 0.01;

	if (prev_zoom_level == zoom_level)
		return (cache);
	prev_zoom_level = zoom_level;
	cache = 0.01 * pow(2, (double)zoom_level / 10);
	return (cache);
}

/*
    ctx->o is calculated from center and pixel_width.
	For Mandelbrot/Julia, center is (0, 0)
	For Barnsley, center is (0.5, 5.0)
*/
void	init_ctx(t_ctx *ctx)
{
	ctx->max_loop = 100;
	ctx->color_mode = NORMAL_MODE;
	ctx->julia_mode = NORMAL_MODE;
	ctx->hue = 0;
	ctx->julia_degree = INITIAL_JULIA_DEGREE;
	if (ctx->fractal_type == BARNSLEY)
	{
		ctx->zoom_level = 40;
		ctx->center = (t_dpoint){0.5, 5.0};
	}
	else
	{
		ctx->zoom_level = 0;
		ctx->center = (t_dpoint){0, 0};
	}
}

void	next_color_mode(t_ctx *ctx)
{
	if (ctx->color_mode == NORMAL_MODE)
		ctx->color_mode = PSYCHEDELIC_MODE;
	else if (ctx->color_mode == PSYCHEDELIC_MODE)
		ctx->color_mode = NORMAL_MODE;
}

void	next_julia_mode(t_ctx *ctx)
{
	if (ctx->julia_mode == NORMAL_MODE)
		ctx->julia_mode = PSYCHEDELIC_MODE;
	else if (ctx->julia_mode == PSYCHEDELIC_MODE)
		ctx->julia_mode = NORMAL_MODE;
}

void	next_fractal(t_ctx *ctx)
{
	if (ctx->fractal_type == MANDELBROT)
		ctx->fractal_type = JULIA;
	else if (ctx->fractal_type == JULIA)
		ctx->fractal_type = BARNSLEY;
	else if (ctx->fractal_type == BARNSLEY)
		ctx->fractal_type = MANDELBROT;
	init_ctx(ctx);
}
