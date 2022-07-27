/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:18:25 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 21:51:12 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

t_complex	mandelbrot(t_complex z, t_complex c)
{
	return (cadd(cmul(z, z), c));
}

int	divergence_speed(t_complex z, t_complex c, int max_loop)
{
	int			i;

	i = -1;
	while (++i < max_loop)
	{
		z = mandelbrot(z, c);
		if (isinf(z.re) || isinf(z.im))
			return (i);
	}
	return (i);
}

t_int_point	calc_xy_in_window(t_double_point point, t_ctx *ctx)
{
	t_int_point	ret;

	ret.x = (point.x - ctx->o.x) / ctx->step;
	ret.y = (ctx->o.y - point.y) / ctx->step;
	return (ret);
}

void	draw_barnsley(t_ctx *ctx)
{
	float			rng;
	t_complex		c;
	int				x;
	int				y;
	unsigned int	i;

	clear_img_rect(&ctx->fractal_img,
		(t_rect){0, 0, FRACT_WIDTH, FRACT_HEIGHT});
	i = 0;
	while (++i < pow(10, 4 + (double)ctx->max_loop / 100))
	{
		rng = ((float)rand()) / RAND_MAX;
		if (rng <= 0.01f)
			c = complex_new(0, 0.16f * c.im);
		else if (rng <= 0.06f)
			c = complex_new(-0.15f * c.re + 0.28f * c.im,
					0.26f * c.re + 0.24f * c.im + 0.44f);
		else if (rng <= 0.06f)
			c = complex_new(0.2f * c.re + -0.26f * c.im,
					0.23f * c.re + 0.22f * c.im + 1.6f);
		else
			c = complex_new(0.85f * c.re + 0.04f * c.im,
					-0.04f * c.re + 0.85f * c.im + 1.6f);
		x = (c.re - ctx->o.x) / ctx->step;
		y = (ctx->o.y - c.im) / ctx->step;
		if (x >= 0 && y >= 0 && x <= FRACT_WIDTH && y <= FRACT_HEIGHT)
			put_pixel_in_img(&ctx->fractal_img, x, y, green());
	}
}

void	draw_mandelbrot(t_ctx *ctx, int speeds[FRACT_WIDTH][FRACT_HEIGHT])
{
	t_int_point	p;
	int			speed;

	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
		{
			if (ctx->fractal_type == Mandelbrot)
				speed = divergence_speed(
						complex_new(0, 0),
						complex_new(ctx->o.x + ctx->step * (double)p.x,
							ctx->o.y - ctx->step * (double)p.y),
						ctx->max_loop);
			else if (ctx->fractal_type == Julia)
				speed = divergence_speed(
						complex_new(ctx->o.x + ctx->step * (double)p.x,
							ctx->o.y - ctx->step * (double)p.y),
						ctx->c,
						ctx->max_loop);
			speed = speed * 256 / ctx->max_loop;
			speeds[p.x][p.y] = speed;
		}
	}
}

void	draw_fractal(t_ctx *ctx)
{
	t_int_point	p;
	t_hsv		hsv;
	int			speed;
	static int	speeds[FRACT_WIDTH][FRACT_HEIGHT];

	if (ctx->fractal_type == Barnsley)
	{
		if (ctx_is_updated(ctx))
			draw_barnsley(ctx);
		return ;
	}
	if (ctx_is_updated(ctx))
		draw_mandelbrot(ctx, speeds);
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
