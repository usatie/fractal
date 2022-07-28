/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:04:53 by susami            #+#    #+#             */
/*   Updated: 2022/07/29 00:44:49 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>
#include "ft_printf.h"

static void	ctx_string_put(t_ctx *ctx, int *height, char *str)
{
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		g_rect_help.x + 50, *height, red(), str);
	*height += 30;
}

static void	put_fractal_mode(t_ctx *ctx, int *height)
{
	char	str[128];

	if (ctx->fractal_type == Mandelbrot)
		ft_sprintf(str, "fractal type: %s", "Mandelbrot");
	else if (ctx->fractal_type == Julia)
		ft_sprintf(str, "fractal type: %s", "Julia");
	else if (ctx->fractal_type == Barnsley)
		ft_sprintf(str, "fractal type: %s", "Barnsley");
	else
		ft_sprintf(str, "fractal type: %s", "Unknown");
	ctx_string_put(ctx, height, str);
}

static void	put_color_mode(t_ctx *ctx, int *height)
{
	char	str[128];

	if (ctx->color_mode == Normal)
		ft_sprintf(str, "color mode: %s", "Normal");
	else if (ctx->color_mode == Psyc)
		ft_sprintf(str, "color mode: %s", "Psychedelic");
	else
		ft_sprintf(str, "color mode: %s", "Unknown");
	ctx_string_put(ctx, height, str);
}

static void	put_julia_mode(t_ctx *ctx, int *height)
{
	char	str[128];

	if (ctx->julia_mode == Normal)
		ft_sprintf(str, "julia mode: %s", "Normal");
	else if (ctx->julia_mode == Psyc)
		ft_sprintf(str, "julia mode: %s", "Psychedelic");
	else
		ft_sprintf(str, "julia mode: %s", "Unknown");
	ctx_string_put(ctx, height, str);
}

static void	put_max_loop(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "max_loop: %d", ctx->max_loop);
	ctx_string_put(ctx, height, str);
}

static void	put_step(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "step[= 1 pixel] : %.20f", ctx->step);
	ctx_string_put(ctx, height, str);
}

static void	put_hue(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "hue: %d", ctx->hue);
	ctx_string_put(ctx, height, str);
}

static void	put_radian(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "c_radian: %lfpi",
		(ctx->c_radian / M_PI - (double)(int)(ctx->c_radian / M_PI / 2) * 2));
	ctx_string_put(ctx, height, str);
}

static void	put_mouse_point(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "mouse_pnt in xy: (%lf, %lf)",
		ctx->mouse_pnt.x, ctx->mouse_pnt.y);
	ctx_string_put(ctx, height, str);
	ft_sprintf(str, "mouse_pnt in window: (%d, %d)",
		ctx->win_mouse_pnt.x, ctx->win_mouse_pnt.y);
	ctx_string_put(ctx, height, str);
}

static bool	need_help_update(t_ctx *ctx)
{
	static bool		initialized;
	static t_ctx	prev;
	bool			is_updated;

	if (!initialized)
		is_updated = true;
	else
		is_updated = (
				(prev.win_mouse_pnt.x != ctx->win_mouse_pnt.x)
				|| (prev.win_mouse_pnt.y != ctx->win_mouse_pnt.y)
				|| (prev.mouse_pnt.x != ctx->mouse_pnt.x)
				|| (prev.mouse_pnt.y != ctx->mouse_pnt.y)
				|| (prev.step != ctx->step)
				|| (prev.hue != ctx->hue)
				|| (prev.o.x != ctx->o.x)
				|| (prev.o.y != ctx->o.y)
				|| (prev.max_loop != ctx->max_loop)
				|| (prev.color_mode != ctx->color_mode)
				|| (prev.julia_mode != ctx->julia_mode)
				|| (prev.fractal_type != ctx->fractal_type)
				|| (prev.c_radian != ctx->c_radian));
	initialized = true;
	prev = *ctx;
	return (is_updated);
}

void	put_ctx_to_window(t_ctx *ctx)
{
	int				height;

	if (!need_help_update(ctx))
		return ;
	clear_win_rect(ctx->mlx_ptr, ctx->win_ptr, g_rect_help);
	put_fractal_mode(ctx, &height);
	put_color_mode(ctx, &height);
	put_julia_mode(ctx, &height);
	put_max_loop(ctx, &height);
	put_step(ctx, &height);
	put_hue(ctx, &height);
	put_radian(ctx, &height);
	put_mouse_point(ctx, &height);
}
