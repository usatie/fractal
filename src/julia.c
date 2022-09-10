/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:15:08 by susami            #+#    #+#             */
/*   Updated: 2022/09/11 00:51:26 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

static void		update(t_speeds speeds, const t_ctx *ctx);
static void		normalize_speeds(t_speeds speeds);
static uint32_t	min(uint32_t a, uint32_t b);
static uint32_t	max(uint32_t a, uint32_t b);

void	draw_julia(const t_ctx *ctx)
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
			put_pixel_in_img(&ctx->fractal_img, p.x, p.y, hsv2rgb(hsv).mlxint);
		}
	}
}

static uint32_t	min(uint32_t a, uint32_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static uint32_t	max(uint32_t a, uint32_t b)
{
	if (a > b)
		return (a);
	return (b);
}

// Update julia speeds
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
	t_ipoint	p;
	uint32_t	max_speed;
	uint32_t	min_speed;

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
