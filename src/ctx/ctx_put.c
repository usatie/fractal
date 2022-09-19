/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:22:58 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 16:09:20 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include "fractol_color.h"

#include "mlx.h"

static bool	is_updated(const t_ctx *ctx);
static void	clear_config_rect(const t_ctx *ctx);

void	draw_ctx(t_ctx *ctx, bool force_update)
{
	int	height;

	if (force_update || is_updated(ctx))
	{
		clear_config_rect(ctx);
		height = 50;
		put_fractal_type(ctx, &height);
		put_color_mode(ctx, &height);
		put_julia_mode(ctx, &height);
		put_max_loop(ctx, &height);
		put_pixel_width(ctx, &height);
		put_hue(ctx, &height);
		put_julia_degree(ctx, &height);
		put_center(ctx, &height);
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
			prev.zoom_level != ctx->zoom_level
			|| (prev.hue != ctx->hue)
			|| neq(prev.center.x, ctx->center.x)
			|| neq(prev.center.y, ctx->center.y)
			|| (prev.max_loop != ctx->max_loop)
			|| (prev.color_mode != ctx->color_mode)
			|| (prev.julia_mode != ctx->julia_mode)
			|| (prev.fractal_type != ctx->fractal_type)
			|| prev.julia_degree != ctx->julia_degree);
	prev = *ctx;
	return (is_updated);
}

static void	clear_config_rect(const t_ctx *ctx)
{
	mlx_put_image_to_window(
		ctx->mlx_ptr,
		ctx->win_ptr,
		ctx->clear_img.img_ptr,
		g_rect_config.x,
		g_rect_config.y);
}
