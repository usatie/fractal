/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:02:42 by susami            #+#    #+#             */
/*   Updated: 2022/09/15 17:10:42 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include <math.h>

t_dpoint	calc_origin(t_ipoint win_mouse_pnt, t_dpoint mouse_pnt,
				double step);

void	init_ctx(t_ctx *ctx)
{
	ctx->max_loop = 100;
	ctx->mouse_pnt = (t_dpoint){0, 0};
	ctx->win_mouse_pnt = (t_ipoint){FRACT_WIDTH / 2, FRACT_HEIGHT / 2};
	ctx->color_mode = NORMAL_MODE;
	ctx->julia_mode = NORMAL_MODE;
	ctx->hue = 0;
	ctx->step_n = 0;
	ctx->step = 0.01 * pow(2, (double)ctx->step_n / 10);
	ctx->c_radian = M_PI * 150 / 180;
	ctx->o = calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, ctx->step);
}

void	ctx_on_update(t_ctx *ctx)
{
	static bool		is_first_time = true;
	static t_ctx	prev;

	if (!is_first_time)
	{
		if (prev.fractal_type != ctx->fractal_type)
		{
			init_ctx(ctx);
			if (ctx->fractal_type == BARNSLEY)
			{
				ctx->mouse_pnt = (t_dpoint){0.5, 5};
				ctx->step_n = 40;
			}
		}
		if (prev.step_n != ctx->step_n)
			ctx->step = 0.01 * pow(2, (double)ctx->step_n / 10);
		if (neq(prev.step, ctx->step)
			|| neq(prev.mouse_pnt.x, ctx->mouse_pnt.x)
			|| neq(prev.mouse_pnt.y, ctx->mouse_pnt.y)
			|| prev.win_mouse_pnt.x != ctx->win_mouse_pnt.x
			|| prev.win_mouse_pnt.y != ctx->win_mouse_pnt.y)
			ctx->o = calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, ctx->step);
	}
	is_first_time = false;
	prev = *ctx;
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
	ctx_on_update(ctx);
}
