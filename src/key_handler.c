/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:35:45 by susami            #+#    #+#             */
/*   Updated: 2022/07/28 00:02:55 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <keysymdef.h>

int	close_window(t_ctx *ctx)
{
	mlx_key_hook(ctx->win_ptr, NULL, NULL);
	mlx_mouse_hook(ctx->win_ptr, NULL, NULL);
	mlx_expose_hook(ctx->win_ptr, NULL, NULL);
	mlx_loop_hook(ctx->mlx_ptr, NULL, NULL);
	mlx_destroy_image(ctx->mlx_ptr, ctx->img_ptr);
	mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
	free(ctx->mlx_ptr);
	exit(0);
}

int	key_handler(int keycode, t_ctx *ctx)
{
	print_keycode(keycode);
	if (keycode == XK_Escape)
		close_window(ctx);
	else if (keycode == '[' && ctx->max_loop > 10)
		ctx->max_loop -= 10;
	else if (keycode == ']' && ctx->max_loop)
		ctx->max_loop += 10;
	else if (keycode == XK_Left)
		ctx->win_mouse_pnt.x += 10;
	else if (keycode == XK_Up)
		ctx->win_mouse_pnt.y += 10;
	else if (keycode == XK_Right)
		ctx->win_mouse_pnt.x -= 10;
	else if (keycode == XK_Down)
		ctx->win_mouse_pnt.y -= 10;
	else if (keycode == 'c')
		ctx_next_color_mode(ctx);
	else if (keycode == 'j')
		ctx_next_julia_mode(ctx);
	else if (keycode == 'f')
		ctx_next_fractal_type(ctx);
	else
		return (0);
	ctx_on_update(ctx);
	return (0);
}
