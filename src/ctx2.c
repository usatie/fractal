/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:04:53 by susami            #+#    #+#             */
/*   Updated: 2022/07/28 00:29:57 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

void	put_ctx_to_window(t_ctx *ctx)
{
	t_rgb			red;
	char			*str;
	int				height;

	clear_win_rect(ctx->mlx_ptr, ctx->win_ptr, g_rect_help);
	red = (t_rgb){.r = 255};
	height = 30;
	if (ctx->fractal_type == Mandelbrot)
		asprintf(&str, "fractal type: %s", "Mandelbrot");
	else if (ctx->fractal_type == Julia)
		asprintf(&str, "fractal type: %s", "Julia");
	else if (ctx->fractal_type == Barnsley)
		asprintf(&str, "fractal type: %s", "Barnsley");
	else
		asprintf(&str, "fractal type: %s", "Unknown");
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	if (ctx->color_mode == Normal)
		asprintf(&str, "color mode: %s", "Normal");
	else if (ctx->color_mode == Psyc)
		asprintf(&str, "color mode: %s", "Psychedelic");
	else
		asprintf(&str, "color mode: %s", "Unknown");
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	if (ctx->julia_mode == Normal)
		asprintf(&str, "julia mode: %s", "Normal");
	else if (ctx->julia_mode == Psyc)
		asprintf(&str, "julia mode: %s", "Psychedelic");
	else
		asprintf(&str, "julia mode: %s", "Unknown");
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "max_loop: %d", ctx->max_loop);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "step[= 1 pixel] : %.20f", ctx->step);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "hue: %d", ctx->hue);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "c_radian: %lfpi",
		(ctx->c_radian / M_PI - (double)(int)(ctx->c_radian / M_PI / 2) * 2));
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "win_mouse_pnt: (%d, %d)",
		ctx->win_mouse_pnt.x, ctx->win_mouse_pnt.y);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "mouse_pnt: (%lf, %lf)",
		ctx->mouse_pnt.x, ctx->mouse_pnt.y);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
}
