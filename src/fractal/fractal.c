/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:18:25 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 21:45:26 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fractol.h"
#include "complex.h"
#include "fractol_ctx.h"
#include "fractol_color.h"

static t_complex	to_complex(int x, int y,
						t_dpoint center, double pixel_width);
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
	is_updated = (prev.zoom_level != ctx->zoom_level
			|| neq(prev.center.x, ctx->center.x)
			|| neq(prev.center.y, ctx->center.y)
			|| (prev.max_loop != ctx->max_loop)
			|| (prev.julia_degree != ctx->julia_degree)
			|| (prev.fractal_type != ctx->fractal_type));
	prev = *ctx;
	return (is_updated);
}

void	draw_complex_iteration_fractal(t_div_f f, const t_ctx *ctx)
{
	int				x;
	int				y;
	t_hsv			hsv;
	uint32_t		speed;
	static t_speeds	speeds;

	if (need_fractal_update(ctx))
		update(f, speeds, ctx);
	y = 0;
	while (y < FRACT_HEIGHT)
	{
		x = 0;
		while (x < FRACT_WIDTH)
		{
			speed = speeds[x][y];
			hsv = (t_hsv){ctx->hue, 255, (uint8_t)(speed), 0};
			put_pixel_in_img(&ctx->fractal_img, x, y, hsv2rgb(hsv).mlxint);
			x++;
		}
		y++;
	}
}

// Update speeds using f
static void	update(t_div_f f, t_speeds speeds, const t_ctx *ctx)
{
	int			x;
	int			y;
	uint32_t	speed;

	y = 0;
	while (y < FRACT_HEIGHT)
	{
		x = 0;
		while (x < FRACT_WIDTH)
		{
			speed = f(
					to_complex(x, y, ctx->center, pixel_width(ctx->zoom_level)),
					ctx->max_loop,
					ctx);
			speeds[x][y] = speed;
			x++;
		}
		y++;
	}
	normalize_speeds(speeds);
}

// Calculate the (x, y) coordinate from window's center and coordinate in
// the window.
static t_complex	to_complex(int x, int y,
						t_dpoint center, double pixel_width)
{
	t_complex	c;

	c = complex_new(
			center.x + pixel_width * (double)(x - FRACT_WIDTH / 2),
			center.y - pixel_width * (double)(y - FRACT_HEIGHT / 2));
	return (c);
}
