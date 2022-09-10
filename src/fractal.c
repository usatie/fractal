/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:18:25 by susami            #+#    #+#             */
/*   Updated: 2022/09/11 00:14:09 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	draw_fractal(const t_ctx *ctx)
{
	if (ctx->fractal_type == mandelbrot)
		draw_mandelbrot(ctx);
	else if (ctx->fractal_type == julia)
		draw_julia(ctx);
	else if (ctx->fractal_type == barnsley)
		draw_barnsley(ctx);
}

bool	need_fractal_update(const t_ctx *ctx)
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
	is_updated = (neq(prev.step, ctx->step)
			|| neq(prev.o.x, ctx->o.x)
			|| neq(prev.o.y, ctx->o.y)
			|| (prev.max_loop != ctx->max_loop)
			|| neq(prev.c_radian, ctx->c_radian)
			|| (prev.fractal_type != ctx->fractal_type));
	prev = *ctx;
	return (is_updated);
}

uint32_t	mandelbrot_div_speed(t_complex z, t_complex c,
		uint32_t max_loop)
{
	uint32_t	i;

	i = 0;
	while (i < max_loop)
	{
		z = cadd(cmul(z, z), c);
		if (isinf(z.re) || isinf(z.im))
			return (i);
		i++;
	}
	return (i);
}
