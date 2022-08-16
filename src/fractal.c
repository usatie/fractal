/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:18:25 by susami            #+#    #+#             */
/*   Updated: 2022/07/29 19:44:10 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

void	draw_fractal(t_ctx *ctx)
{
	if (ctx->fractal_type == Mandelbrot)
		draw_mandelbrot(ctx);
	else if (ctx->fractal_type == Julia)
		draw_julia(ctx);
	else if (ctx->fractal_type == Barnsley)
		draw_barnsley(ctx);
}

bool	need_fractal_update(t_ctx *ctx)
{
	static bool		initialized;
	static t_ctx	prev;
	bool			is_updated;

	if (!initialized)
		is_updated = true;
	else
		is_updated = ((prev.step != ctx->step)
				|| (prev.o.x != ctx->o.x)
				|| (prev.o.y != ctx->o.y)
				|| (prev.max_loop != ctx->max_loop)
				|| (prev.c_radian != ctx->c_radian)
				|| (prev.fractal_type != ctx->fractal_type));
	initialized = true;
	prev = *ctx;
	return (is_updated);
}

unsigned int	mandelbrot_div_speed(t_complex z, t_complex c,
		unsigned int max_loop)
{
	unsigned int	i;

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
