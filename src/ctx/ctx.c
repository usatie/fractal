/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:02:42 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 13:11:37 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include <math.h>

#define INITIAL_JULIA_DEGREE 150

double	step(int step_n)
{
	static int		prev_n = 0;
	static double	cache = 0.01;

	if (prev_n == step_n)
		return (cache);
	prev_n = step_n;
	cache = 0.01 * pow(2, (double)step_n / 10);
	return (cache);
}

/*
    ctx->o is calculated from center and step.
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
		ctx->step_n = 40;
		ctx->o.x = 0.5 - step(ctx->step_n) * FRACT_WIDTH / 2;
		ctx->o.y = 5.0 + step(ctx->step_n) * FRACT_WIDTH / 2;
	}
	else
	{
		ctx->step_n = 0;
		ctx->o.x = 0.0 - step(ctx->step_n) * FRACT_WIDTH / 2;
		ctx->o.y = 0.0 + step(ctx->step_n) * FRACT_HEIGHT / 2;
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
