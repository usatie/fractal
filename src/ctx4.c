/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:10:29 by susami            #+#    #+#             */
/*   Updated: 2022/07/29 11:10:44 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include <math.h>

void	ctx_string_put(t_ctx *ctx, int *height, char *str);

void	ctx_put_max_loop(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "max_loop: %d", ctx->max_loop);
	ctx_string_put(ctx, height, str);
}

void	ctx_put_step(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "step[= 1 pixel] : %.20f", ctx->step);
	ctx_string_put(ctx, height, str);
}

void	ctx_put_hue(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "hue: %d", ctx->hue);
	ctx_string_put(ctx, height, str);
}

void	ctx_put_radian(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "c_radian: %lfpi",
		(ctx->c_radian / M_PI - (double)(int)(ctx->c_radian / M_PI / 2) * 2));
	ctx_string_put(ctx, height, str);
}

void	ctx_put_mouse_point(t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "mouse_pnt in xy: (%lf, %lf)",
		ctx->mouse_pnt.x, ctx->mouse_pnt.y);
	ctx_string_put(ctx, height, str);
	ft_sprintf(str, "mouse_pnt in window: (%d, %d)",
		ctx->win_mouse_pnt.x, ctx->win_mouse_pnt.y);
	ctx_string_put(ctx, height, str);
}
