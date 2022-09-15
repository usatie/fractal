/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:08:09 by susami            #+#    #+#             */
/*   Updated: 2022/09/15 17:09:16 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include "mlx.h"
#include <math.h>

int	loop_handler(t_ctx *ctx)
{
	static bool		lock;
	static size_t	cnt;

	if (cnt++ % 1000 != 0 || lock)
		return (0);
	lock = true;
	if (ctx->color_mode == PSYCHEDELIC_MODE)
		ctx->hue += 4;
	if (ctx->julia_mode == PSYCHEDELIC_MODE)
		ctx->c_radian += M_PI / 60;
	draw_fractal(ctx);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
		ctx->fractal_img.img_ptr, 0, 0);
	put_ctx_to_window(ctx);
	lock = false;
	return (0);
}
