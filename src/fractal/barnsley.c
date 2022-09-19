/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:15:14 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 21:45:10 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// rand()
#include <stdlib.h>
#include <math.h>
#include "fractol.h"
#include "complex.h"
#include "fractol_ctx.h"
#include "fractol_color.h"

static t_ipoint	to_window_coord(t_dpoint point, const t_ctx *ctx);
static t_dpoint	barnsley_next(t_dpoint p);

void	draw_barnsley(const t_ctx *ctx)
{
	t_dpoint	c;
	t_ipoint	p;
	uint32_t	i;

	if (!need_fractal_update(ctx))
		return ;
	clear_img_rect(&ctx->fractal_img, g_rect_fractal);
	i = 0;
	c = (t_dpoint){0, 0};
	while (++i < pow(10, 4 + (double)ctx->max_loop / 100))
	{
		c = barnsley_next(c);
		p = to_window_coord(c, ctx);
		if (rect_contains(p, g_rect_fractal))
			put_pixel_in_img(&ctx->fractal_img, p.x, p.y, green().mlxint);
	}
}

static t_dpoint	barnsley_next(t_dpoint p)
{
	float			rng;

	rng = rand() / (float)RAND_MAX;
	if (rng <= 0.01f)
		return ((t_dpoint){
			.x = 0,
			.y = 0.16 * p.y
		});
	else if (rng <= 0.08f)
		return ((t_dpoint){
			.x = -0.15 * p.x + 0.28 * p.y,
			.y = 0.26 * p.x + 0.24 * p.y + 0.44
		});
	else if (rng <= 0.15f)
		return ((t_dpoint){
			.x = 0.2 * p.x + -0.26 * p.y,
			.y = 0.23 * p.x + 0.22 * p.y + 1.6
		});
	else
		return ((t_dpoint){
			.x = 0.85 * p.x + 0.04 * p.y,
			.y = -0.04 * p.x + 0.85 * p.y + 1.6
		});
}

static t_ipoint	to_window_coord(t_dpoint point, const t_ctx *ctx)
{
	t_ipoint	ret;

	ret.x = FRACT_WIDTH / 2;
	ret.y = FRACT_HEIGHT / 2;
	ret.x += (int)((point.x - ctx->center.x) / pixel_width(ctx->zoom_level));
	ret.y -= (int)((point.y - ctx->center.y) / pixel_width(ctx->zoom_level));
	return (ret);
}
