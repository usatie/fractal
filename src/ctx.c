/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:02:42 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 10:38:44 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>

void	ctx_update_step(t_ctx *ctx)
{
	ctx->step = 0.01 * pow(2, (double)ctx->step_n / 10);
}

void	ctx_next_color_mode(t_ctx *ctx)
{
	ctx->color_mode = (ctx->color_mode + 1) % 2;
}

void	ctx_next_julia_mode(t_ctx *ctx)
{
	ctx->julia_mode = (ctx->julia_mode + 1) % 2;
}

void	ctx_next_fractal_type(t_ctx *ctx)
{
	ctx->fractal_type = (ctx->fractal_type + 1) % 3;
	ctx->win_mouse_pnt = (t_int_point){FRACT_WIDTH / 2, FRACT_HEIGHT / 2};
	if (ctx->fractal_type == Barnsley)
	{
		ctx->mouse_pnt = (t_double_point){0.5, 5};
		ctx->max_loop = 100;
		ctx->step_n = 20;
	}
	else
	{
		ctx->mouse_pnt = (t_double_point){0, 0};
		ctx->max_loop = 100;
		ctx->step_n = 0;
	}
	ctx_update_step(ctx);
}

bool	is_equal(t_ctx l, t_ctx r)
{
	(void)l;
	(void)r;
	return (false);
	/*
	return (
		l.win_mouse_pnt.x == r.win_mouse_pnt.x
		&& l.win_mouse_pnt.y == r.win_mouse_pnt.y
		&& l.mouse_pnt.x == r.mouse_pnt.x
		&& l.mouse_pnt.y == r.mouse_pnt.y
		&& l.step == r.step
		&& l.hue == r.hue
		&& l.max_loop == r.max_loop
		&& l.mode == r.mode
	);
	*/
}
