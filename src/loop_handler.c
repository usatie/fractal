/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:08:09 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 11:10:07 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

int	loop_handler(t_ctx *ctx)
{
	static bool		lock;
	static size_t	cnt;

	if (cnt++ % 1000 != 0 || lock)
		return (0);
	lock = true;
	if (ctx->color_mode == Psyc)
		ctx->hue += 4;
	if (ctx->julia_mode == Psyc)
	{
		ctx->c_radian += M_PI / 60;
		ctx->c = cmul(complex_new(0.7885, 0),
				complex_new(cos(ctx->c_radian), sin(ctx->c_radian)));
	}
	draw_fractal(ctx->img_ptr,
		calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, ctx->step),
		ctx->step,
		ctx->hue,
		ctx->max_loop,
		ctx->fractal_type,
		*ctx);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, ctx->img_ptr, 0, 0);
	put_ctx_to_window(ctx);
	lock = false;
	return (0);
}
