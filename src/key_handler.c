/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:35:45 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 10:37:13 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <keysymdef.h>

int	key_handler(int keycode, void *param)
{
	t_ctx	*ctx;

	print_keycode(keycode);
	ctx = (t_ctx *)param;
	if (keycode == XK_Escape)
	{
		close_window(ctx);
		return (0);
	}
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
	return (0);
}
