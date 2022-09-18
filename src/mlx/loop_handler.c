/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:08:09 by susami            #+#    #+#             */
/*   Updated: 2022/09/18 18:24:02 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include <math.h>

#define LOOP_PER_FRAME 1000
#define HUE_INCREASE_PER_FRAME 4
#define JULIA_DEGREE_INCREASE_PER_FRAME 3

static void	update_ctx_in_loop(t_ctx *ctx);

int	loop_handler(t_ctx *ctx)
{
	static bool		lock;
	static size_t	cnt;
	const bool		skip_upadte = ((cnt % LOOP_PER_FRAME) != 0 || lock);

	cnt++;
	if (skip_upadte)
		return (0);
	lock = true;
	update_ctx_in_loop(ctx);
	draw_fractal(ctx);
	put_ctx_to_window(ctx);
	lock = false;
	return (0);
}

static void	update_ctx_in_loop(t_ctx *ctx)
{
	if (ctx->color_mode == PSYCHEDELIC_MODE)
		ctx->hue += HUE_INCREASE_PER_FRAME;
	if (ctx->julia_mode == PSYCHEDELIC_MODE)
	{
		ctx->julia_degree += JULIA_DEGREE_INCREASE_PER_FRAME;
		ctx->julia_degree %= 360;
	}
}
