/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_put_config2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:35:38 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 17:36:01 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include "ft_printf.h"
// M_PI is defined in math.h
#include <math.h>

void	ctx_put_config_hue(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "hue: %d", ctx->hue);
	ctx_string_put(ctx, height, str);
}

void	ctx_put_config_radian(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "c_radian: %lfpi",
		(ctx->c_radian / M_PI - (double)(int)(ctx->c_radian / M_PI / 2) * 2));
	ctx_string_put(ctx, height, str);
}

void	ctx_put_config_mouse_point(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "mouse_pnt in xy: (%lf, %lf)",
		ctx->mouse_pnt.x, ctx->mouse_pnt.y);
	ctx_string_put(ctx, height, str);
	ft_sprintf(str, "mouse_pnt in window: (%d, %d)",
		ctx->win_mouse_pnt.x, ctx->win_mouse_pnt.y);
	ctx_string_put(ctx, height, str);
}
