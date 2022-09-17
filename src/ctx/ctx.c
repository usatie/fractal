/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:02:42 by susami            #+#    #+#             */
/*   Updated: 2022/09/17 22:45:35 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include <math.h>

#define INITIAL_JULIA_DEGREE 150

t_dpoint	calc_origin(t_ipoint win_mouse_pnt, t_dpoint mouse_pnt,
				double step);

double	step(int step_n)
{
	return (0.01 * pow(2, (double)step_n / 10));
}

void	init_ctx(t_ctx *ctx)
{
	ctx->max_loop = 100;
	ctx->mouse_pnt = (t_dpoint){0, 0};
	ctx->win_mouse_pnt = (t_ipoint){FRACT_WIDTH / 2, FRACT_HEIGHT / 2};
	ctx->color_mode = NORMAL_MODE;
	ctx->julia_mode = NORMAL_MODE;
	ctx->hue = 0;
	ctx->step_n = 0;
	ctx->c_radian = M_PI / 180 * INITIAL_JULIA_DEGREE;
	ctx->o = calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, step(ctx->step_n));
}

void	ctx_next_color_mode(t_ctx *ctx)
{
	if (ctx->color_mode == NORMAL_MODE)
		ctx->color_mode = PSYCHEDELIC_MODE;
	else if (ctx->color_mode == PSYCHEDELIC_MODE)
		ctx->color_mode = NORMAL_MODE;
}

void	ctx_next_julia_mode(t_ctx *ctx)
{
	if (ctx->julia_mode == NORMAL_MODE)
		ctx->julia_mode = PSYCHEDELIC_MODE;
	else if (ctx->julia_mode == PSYCHEDELIC_MODE)
		ctx->julia_mode = NORMAL_MODE;
}

void	ctx_next_fractal_type(t_ctx *ctx)
{
	if (ctx->fractal_type == MANDELBROT)
		ctx->fractal_type = JULIA;
	else if (ctx->fractal_type == JULIA)
		ctx->fractal_type = BARNSLEY;
	else if (ctx->fractal_type == BARNSLEY)
		ctx->fractal_type = MANDELBROT;
	init_ctx(ctx);
	if (ctx->fractal_type == BARNSLEY)
	{
		ctx->mouse_pnt = (t_dpoint){0.5, 5};
		ctx->step_n = 40;
	}
}
