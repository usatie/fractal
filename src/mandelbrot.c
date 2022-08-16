/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:15:04 by susami            #+#    #+#             */
/*   Updated: 2022/07/29 19:34:34 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_mandelbrot(unsigned int speeds[FRACT_WIDTH][FRACT_HEIGHT],
				t_ctx *ctx);

void	draw_mandelbrot(t_ctx *ctx)
{
	t_int_point			p;
	t_hsv				hsv;
	unsigned int		speed;
	static unsigned int	speeds[FRACT_WIDTH][FRACT_HEIGHT];

	if (need_fractal_update(ctx))
		update_mandelbrot(speeds, ctx);
	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
		{
			speed = speeds[p.x][p.y];
			hsv = (t_hsv){(ctx->hue + speed) % 256, 255, 150, 0};
			put_pixel_in_img(&ctx->fractal_img, p.x, p.y, hsv2mlxint(hsv));
		}
	}
}

static void	update_mandelbrot(unsigned int speeds[FRACT_WIDTH][FRACT_HEIGHT],
		t_ctx *ctx)
{
	t_int_point		p;
	unsigned int	speed;

	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
		{
			speed = mandelbrot_div_speed(
					complex_new(0, 0),
					complex_new(ctx->o.x + ctx->step * (double)p.x,
						ctx->o.y - ctx->step * (double)p.y),
					ctx->max_loop);
			speed = speed * 256 / ctx->max_loop;
			speeds[p.x][p.y] = speed;
		}
	}
}
