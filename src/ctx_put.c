/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:22:58 by susami            #+#    #+#             */
/*   Updated: 2022/09/11 00:16:19 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include "mlx.h"

static bool	is_updated(const t_ctx *ctx);

void	put_ctx_to_window(t_ctx *ctx)
{
	int	height;

	if (is_updated(ctx))
	{
		clear_win_rect(ctx->mlx_ptr, ctx->win_ptr, g_rect_config);
		height = 50;
		ctx_put_config_fractal_mode(ctx, &height);
		ctx_put_config_color_mode(ctx, &height);
		ctx_put_config_julia_mode(ctx, &height);
		ctx_put_config_max_loop(ctx, &height);
		ctx_put_config_step(ctx, &height);
		ctx_put_config_hue(ctx, &height);
		ctx_put_config_radian(ctx, &height);
		ctx_put_config_mouse_point(ctx, &height);
	}
}

void	ctx_string_put(const t_ctx *ctx, int *height, char *str)
{
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		g_rect_config.x + 50, *height, red().mlxint, str);
	*height += 30;
}

static bool	is_updated(const t_ctx *ctx)
{
	static bool		is_first_time = true;
	static t_ctx	prev;
	bool			is_updated;

	if (is_first_time)
	{
		is_first_time = false;
		prev = *ctx;
		return (true);
	}
	is_updated = (
			(prev.win_mouse_pnt.x != ctx->win_mouse_pnt.x)
			|| (prev.win_mouse_pnt.y != ctx->win_mouse_pnt.y)
			|| neq(prev.mouse_pnt.x, ctx->mouse_pnt.x)
			|| neq(prev.mouse_pnt.y, ctx->mouse_pnt.y)
			|| neq(prev.step, ctx->step)
			|| (prev.hue != ctx->hue)
			|| neq(prev.o.x, ctx->o.x) || neq(prev.o.y, ctx->o.y)
			|| (prev.max_loop != ctx->max_loop)
			|| (prev.color_mode != ctx->color_mode)
			|| (prev.julia_mode != ctx->julia_mode)
			|| (prev.fractal_type != ctx->fractal_type)
			|| neq(prev.c_radian, ctx->c_radian));
	prev = *ctx;
	return (is_updated);
}
