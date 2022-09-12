/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:15:04 by susami            #+#    #+#             */
/*   Updated: 2022/09/12 15:29:12 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

static void	update(t_speeds speeds, const t_ctx *ctx);

void	draw_mandelbrot(const t_ctx *ctx)
{
	t_ipoint		p;
	t_hsv			hsv;
	uint32_t		speed;
	static t_speeds	speeds;

	if (need_fractal_update(ctx))
		update(speeds, ctx);
	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
		{
			speed = speeds[p.x][p.y];
			hsv = (t_hsv){ctx->hue, 255, (uint8_t)(150 * speed / 255), 0};
			if (speed == 0)
				hsv = (t_hsv){0};
			put_pixel_in_img(&ctx->fractal_img, p.x, p.y, hsv2rgb(hsv).mlxint);
		}
	}
}

static void	update(t_speeds speeds, const t_ctx *ctx)
{
	t_ipoint	p;
	uint32_t	speed;

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
	normalize_speeds(speeds);
}
