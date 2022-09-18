/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_put_config2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:35:38 by susami            #+#    #+#             */
/*   Updated: 2022/09/18 18:21:18 by susami           ###   ########.fr       */
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

void	ctx_put_config_julia_degree(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "julia_degree: %d", ctx->julia_degree);
	ctx_string_put(ctx, height, str);
}

void	ctx_put_config_o(const t_ctx *ctx, int *height)
{
	char	str[128];

	ft_sprintf(str, "o: (%f, %f)", ctx->o.x, ctx->o.y);
	ctx_string_put(ctx, height, str);
}
