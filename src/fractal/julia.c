/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:15:08 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 21:45:32 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_printf.h"
#include "fractol.h"
#include "complex.h"
#include "fractol_ctx.h"

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
// Initial degree is zero.
static uint32_t	div_f(t_complex z0, uint32_t max_loop, const t_ctx *ctx)
{
	static int			degree = 0;
	static t_complex	c = (t_complex){JULIA_LEN, 0};
	uint32_t			speed;

	if (degree != ctx->julia_degree)
	{
		degree = ctx->julia_degree;
		c = complex_new(
				JULIA_LEN * cos(M_PI * (double)degree / 180),
				JULIA_LEN * sin(M_PI * (double)degree / 180));
	}
	speed = complex_iteration_div(
			z0,
			c,
			max_loop);
	return (speed);
}
