/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:04:53 by susami            #+#    #+#             */
/*   Updated: 2022/07/29 11:17:59 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>
#include "ft_printf.h"

void		ctx_string_put(t_ctx *ctx, int *height, char *str);
void		ctx_put_fractal_mode(t_ctx *ctx, int *height);
void		ctx_put_color_mode(t_ctx *ctx, int *height);
void		ctx_put_julia_mode(t_ctx *ctx, int *height);
void		ctx_put_max_loop(t_ctx *ctx, int *height);
void		ctx_put_step(t_ctx *ctx, int *height);
void		ctx_put_hue(t_ctx *ctx, int *height);
void		ctx_put_radian(t_ctx *ctx, int *height);
void		ctx_put_mouse_point(t_ctx *ctx, int *height);
static bool	need_help_update(t_ctx *ctx);

void	put_ctx_to_window(t_ctx *ctx)
{
	int				height;

	if (!need_help_update(ctx))
		return ;
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

void	ctx_string_put(t_ctx *ctx, int *height, char *str)
{
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr,
		g_rect_help.x + 50, *height, red(), str);
	*height += 30;
}
