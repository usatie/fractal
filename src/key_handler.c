/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:35:45 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 22:27:10 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include "mlx.h"
#include "mlx_keymap.h"

int	close_window(t_ctx *ctx)
{
	mlx_key_hook(ctx->win_ptr, NULL, NULL);
	mlx_mouse_hook(ctx->win_ptr, NULL, NULL);
	mlx_expose_hook(ctx->win_ptr, NULL, NULL);
	mlx_loop_hook(ctx->mlx_ptr, NULL, NULL);
	mlx_destroy_image(ctx->mlx_ptr, ctx->fractal_img.img_ptr);
	mlx_destroy_image(ctx->mlx_ptr, ctx->config_img.img_ptr);
	mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
	free(ctx->mlx_ptr);
	exit(0);
}

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
		ctx->win_mouse_pnt.x += 10;
	else if (keycode == MK_UP)
		ctx->win_mouse_pnt.y += 10;
	else if (keycode == MK_RIGHT)
		ctx->win_mouse_pnt.x -= 10;
	else if (keycode == MK_DOWN)
		ctx->win_mouse_pnt.y -= 10;
	else if (keycode == MK_C)
		ctx_next_color_mode(ctx);
	else if (keycode == MK_J)
		ctx_next_julia_mode(ctx);
	else if (keycode == MK_F)
		ctx_next_fractal_type(ctx);
	else
		return (0);
	ctx_on_update(ctx);
	return (0);
}
