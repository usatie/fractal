/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:15:04 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 21:00:19 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

static void	update_mandelbrot(t_speeds speeds, const t_ctx *ctx);

void	draw_mandelbrot(const t_ctx *ctx)
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
			hsv = (t_hsv){
				(unsigned char)(ctx->hue + 255 * speed / ctx->max_loop),
				255 * speed / ctx->max_loop,
				150 * speed / ctx->max_loop,
				0};
			if (speed == 0)
				hsv = (t_hsv){0};
			put_pixel_in_img(&ctx->fractal_img, p.x, p.y, hsv2rgb(hsv).mlxint);
		}
	}
}

static void	update_mandelbrot(t_speeds speeds, const t_ctx *ctx)
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
			speeds[p.x][p.y] = speed;
		}
	}
}
