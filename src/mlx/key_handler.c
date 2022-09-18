/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:35:45 by susami            #+#    #+#             */
/*   Updated: 2022/09/18 11:27:50 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include "mlx_keymap.h"

int	key_handler(int keycode, t_ctx *ctx)
{
	print_keycode(keycode);
	if (keycode == MK_ESCAPE)
		close_window(ctx);
	else if (keycode == MK_BRACKETLEFT && ctx->max_loop > 10)
		ctx->max_loop -= 10;
	else if (keycode == MK_BRACKETRIGHT && ctx->max_loop)
		ctx->max_loop += 10;
	else if (keycode == MK_LEFT)
		ctx->o.x -= step(ctx->step_n) * 10;
	else if (keycode == MK_UP)
		ctx->o.y += step(ctx->step_n) * 10;
	else if (keycode == MK_RIGHT)
		ctx->o.x += step(ctx->step_n) * 10;
	else if (keycode == MK_DOWN)
		ctx->o.y -= step(ctx->step_n) * 10;
	else if (keycode == MK_C)
		ctx_next_color_mode(ctx);
	else if (keycode == MK_J)
		ctx_next_julia_mode(ctx);
	else if (keycode == MK_F)
		ctx_next_fractal_type(ctx);
	return (0);
}
