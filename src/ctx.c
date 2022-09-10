/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:02:42 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 22:30:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_util.h"
#include "fractol_ctx.h"
#include <math.h>

static t_double_point	calc_origin(t_int_point win_mouse_pnt,
							t_double_point mouse_pnt, double step);

void	ctx_on_update(t_ctx *ctx)
{
	static bool		initialized;
	static t_ctx	prev;

	if (prev.fractal_type != ctx->fractal_type || !initialized)
	{
		ctx->julia_mode = Normal;
		ctx->max_loop = 100;
		ctx->mouse_pnt = (t_double_point){0, 0};
		if (ctx->fractal_type == Barnsley)
			ctx->mouse_pnt = (t_double_point){0.5, 5};
		ctx->step_n = 0;
		if (ctx->fractal_type == Barnsley)
			ctx->step_n = 40;
	}
	if (prev.step_n != ctx->step_n || !initialized)
		ctx->step = 0.01 * pow(2, (double)ctx->step_n / 10);
	if (neq(prev.step, ctx->step)
		|| neq(prev.mouse_pnt.x, ctx->mouse_pnt.x)
		|| neq(prev.mouse_pnt.y, ctx->mouse_pnt.y)
		|| prev.win_mouse_pnt.x != ctx->win_mouse_pnt.x
		|| prev.win_mouse_pnt.y != ctx->win_mouse_pnt.y
		|| !initialized)
		ctx->o = calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, ctx->step);
	initialized = true;
	prev = *ctx;
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
	ctx_on_update(ctx);
}

static t_double_point	calc_origin(t_int_point win_mouse_pnt,
		t_double_point mouse_pnt, double step)
{
	double	x;
	double	y;

	x = mouse_pnt.x - step * win_mouse_pnt.x;
	y = mouse_pnt.y + step * win_mouse_pnt.y;
	return ((t_double_point){x, y});
}
