/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:15:08 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 21:00:37 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

static void			update(t_speeds speeds, const t_ctx *ctx);
static void			normalize_speeds(t_speeds speeds);
static unsigned int	min(unsigned int a, unsigned int b);
static unsigned int	max(unsigned int a, unsigned int b);

void	draw_julia(const t_ctx *ctx)
{
	t_int_point		p;
	t_hsv			hsv;
	unsigned int	speed;
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
			hsv = (t_hsv){ctx->hue, 255, 150 * speed / 255, 0};
			put_pixel_in_img(&ctx->fractal_img, p.x, p.y, hsv2rgb(hsv).mlxint);
		}
	}
}

static unsigned int	min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

static unsigned int	max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

// Update julia speeds
static void	update(t_speeds speeds, const t_ctx *ctx)
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
					complex_new(ctx->o.x + ctx->step * (double)p.x,
						ctx->o.y - ctx->step * (double)p.y),
					ctx->c, ctx->max_loop);
			speeds[p.x][p.y] = speed;
		}
	}
	normalize_speeds(speeds);
}

// normalize to 0-255
static void	normalize_speeds(t_speeds speeds)
{
	t_int_point		p;
	unsigned int	max_speed;
	unsigned int	min_speed;

	max_speed = speeds[0][0];
	min_speed = speeds[0][0];
	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
		{
			max_speed = max(max_speed, speeds[p.x][p.y]);
			min_speed = min(min_speed, speeds[p.x][p.y]);
		}
	}
	max_speed = min(max_speed, min_speed + 10);
	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
			speeds[p.x][p.y] = (speeds[p.x][p.y] - min_speed) * 255
				/ (max_speed - min_speed);
	}
}
