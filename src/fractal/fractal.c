/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:18:25 by susami            #+#    #+#             */
/*   Updated: 2022/09/17 22:26:18 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fractol.h"

static t_complex	to_complex(t_ipoint p, t_dpoint o, double step);
static void			update(t_div_f f, t_speeds speeds, const t_ctx *ctx);

void	draw_fractal(const t_ctx *ctx)
{
	if (ctx->fractal_type == MANDELBROT)
		draw_mandelbrot(ctx);
	else if (ctx->fractal_type == JULIA)
		draw_julia(ctx);
	else if (ctx->fractal_type == BARNSLEY)
		draw_barnsley(ctx);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
		ctx->fractal_img.img_ptr, 0, 0);
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
	is_updated = (prev.step_n != ctx->step_n
			|| neq(prev.o.x, ctx->o.x)
			|| neq(prev.o.y, ctx->o.y)
			|| (prev.max_loop != ctx->max_loop)
			|| neq(prev.c_radian, ctx->c_radian)
			|| (prev.fractal_type != ctx->fractal_type));
	prev = *ctx;
	return (is_updated);
}

void	draw_complex_iteration_fractal(t_div_f f, const t_ctx *ctx)
{
	t_ipoint		p;
	t_hsv			hsv;
	uint32_t		speed;
	static t_speeds	speeds;

	if (need_fractal_update(ctx))
		update(f, speeds, ctx);
	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
		{
			speed = speeds[p.x][p.y];
			hsv = (t_hsv){ctx->hue, 255, (uint8_t)(speed), 0};
			put_pixel_in_img(&ctx->fractal_img, p.x, p.y, hsv2rgb(hsv).mlxint);
		}
	}
}

// Update speeds using f
static void	update(t_div_f f, t_speeds speeds, const t_ctx *ctx)
{
	t_ipoint	p;
	uint32_t	speed;

	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
		{
			speed = f(
					to_complex(p, ctx->o, step(ctx->step_n)),
					ctx->max_loop,
					ctx);
			speeds[p.x][p.y] = speed;
		}
	}
	normalize_speeds(speeds);
}

// Calculate the (x, y) coordinate from window's o and coordinate in the window.
static t_complex	to_complex(t_ipoint p, t_dpoint o, double step)
{
	t_complex	c;

	c = complex_new(
			o.x + step * (double)p.x,
			o.y - step * (double)p.y);
	return (c);
}
