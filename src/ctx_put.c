/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:22:58 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 17:24:53 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_util.h"
#include "ft_printf.h"
#include "mlx.h"
#include <math.h>

static bool	is_updated(const t_ctx *ctx);
void		ctx_put_fractal_mode(const t_ctx *ctx, int *height);
void		ctx_put_color_mode(const t_ctx *ctx, int *height);
void		ctx_put_julia_mode(const t_ctx *ctx, int *height);
void		ctx_put_max_loop(const t_ctx *ctx, int *height);
void		ctx_put_step(const t_ctx *ctx, int *height);
void		ctx_put_hue(const t_ctx *ctx, int *height);
void		ctx_put_radian(const t_ctx *ctx, int *height);
void		ctx_put_mouse_point(const t_ctx *ctx, int *height);
void		ctx_string_put(const t_ctx *ctx, int *height, char *str);

void	put_ctx_to_window(t_ctx *ctx)
{
	int	height;

	if (is_updated(ctx))
	{
		clear_win_rect(ctx->mlx_ptr, ctx->win_ptr, g_rect_help);
		height = 50;
		ctx_put_fractal_mode(ctx, &height);
		ctx_put_color_mode(ctx, &height);
		ctx_put_julia_mode(ctx, &height);
		ctx_put_max_loop(ctx, &height);
		ctx_put_step(ctx, &height);
		ctx_put_hue(ctx, &height);
		ctx_put_radian(ctx, &height);
		ctx_put_mouse_point(ctx, &height);
	}
}

static bool	is_updated(const t_ctx *ctx)
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
				|| neq(prev.mouse_pnt.x, ctx->mouse_pnt.x)
				|| neq(prev.mouse_pnt.y, ctx->mouse_pnt.y)
				|| neq(prev.step, ctx->step)
				|| (prev.hue != ctx->hue)
				|| neq(prev.o.x, ctx->o.x)
				|| neq(prev.o.y, ctx->o.y)
				|| (prev.max_loop != ctx->max_loop)
				|| (prev.color_mode != ctx->color_mode)
				|| (prev.julia_mode != ctx->julia_mode)
				|| (prev.fractal_type != ctx->fractal_type)
				|| neq(prev.c_radian, ctx->c_radian));
	initialized = true;
	prev = *ctx;
	return (is_updated);
}

void	ctx_string_put(const t_ctx *ctx, int *height, char *str)
{
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		g_rect_help.x + 50, *height, red(), str);
	*height += 30;
}

void	ctx_put_fractal_mode(const t_ctx *ctx, int *height)
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

void	ctx_put_color_mode(const t_ctx *ctx, int *height)
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

void	ctx_put_julia_mode(const t_ctx *ctx, int *height)
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

void	ctx_put_max_loop(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "max_loop: %d", ctx->max_loop);
	ctx_string_put(ctx, height, str);
}

void	ctx_put_step(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "step[= 1 pixel] : %.20f", ctx->step);
	ctx_string_put(ctx, height, str);
}

void	ctx_put_hue(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "hue: %d", ctx->hue);
	ctx_string_put(ctx, height, str);
}

void	ctx_put_radian(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "c_radian: %lfpi",
		(ctx->c_radian / M_PI - (double)(int)(ctx->c_radian / M_PI / 2) * 2));
	ctx_string_put(ctx, height, str);
}

void	ctx_put_mouse_point(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "mouse_pnt in xy: (%lf, %lf)",
		ctx->mouse_pnt.x, ctx->mouse_pnt.y);
	ctx_string_put(ctx, height, str);
	ft_sprintf(str, "mouse_pnt in window: (%d, %d)",
		ctx->win_mouse_pnt.x, ctx->win_mouse_pnt.y);
	ctx_string_put(ctx, height, str);
}
