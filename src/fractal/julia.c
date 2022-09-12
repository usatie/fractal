/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:15:08 by susami            #+#    #+#             */
/*   Updated: 2022/09/12 17:43:53 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "ft_printf.h"

#define JULIA_LEN 0.7885

static uint32_t	div_f(t_complex point, uint32_t max_loop, const t_ctx *ctx);

void	draw_julia(const t_ctx *ctx)
{
	draw_complex_iteration_fractal(div_f, ctx);
}

// Julia set : f(z) = z^2 + c
//
// z0 : (x, y)
// c  : some const value
//
// Initial prev is nan(0.0 / 0.0).
static uint32_t	div_f(t_complex z0, uint32_t max_loop, const t_ctx *ctx)
{
	static double		prev = 0.0 / 0.0;
	static t_complex	c;
	uint32_t			speed;

	if (neq(prev, ctx->c_radian) || isnan(prev))
		c = complex_new(
				JULIA_LEN * cos(ctx->c_radian),
				JULIA_LEN * sin(ctx->c_radian));
	speed = complex_iteration_div(
			z0,
			c,
			max_loop);
	prev = ctx->c_radian;
	return (speed);
}
