/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:02:42 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 18:19:02 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
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

t_double_point	calc_origin(t_int_point win_mouse_pnt,
		t_double_point mouse_pnt, double step)
{
	double	x;
	double	y;

	x = mouse_pnt.x - step * win_mouse_pnt.x;
	y = mouse_pnt.y + step * win_mouse_pnt.y;
	return ((t_double_point){x, y});
}

void	put_ctx_to_window(t_ctx *ctx)
{
	t_rgb			red;
	char			*str;
	int				height;

	clear_win_rect(ctx->mlx_ptr, ctx->win_ptr,
		(t_rect){FRACT_WIDTH, 0, HELP_WIDTH, HELP_HEIGHT});
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
