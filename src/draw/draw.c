/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:03:17 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 19:01:14 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "draw.h"
#include "img.h"
#include "complex.h"
#include "color.h"

#define DEFAULT_PIXEL_WIDTH 0.01
#define ZOOM_LEVEL_PER_2X 10

t_fractal	g_prev = {0};

bool	draw_fractal_to_img(t_fractal *f)
{
	bool	updated;

	updated = false;
	if (f->type == MANDELBROT)
		updated = mandelbrot(f);
	else if (f->type == JULIA)
		updated = julia(f);
	else if (f->type == BARNSLEY || f->type == CYCLOSORUS
		|| f->type == FRACTAL_TREE || f->type == GOLDEN_BEE)
		updated = barnsley(f);
	g_prev = *f;
	return (updated);
}

double	pixel_width(int zoom_level)
{
	static int		prev_zoom_level = 0;
	static double	cache = DEFAULT_PIXEL_WIDTH;
	double			zoom_factor;

	if (prev_zoom_level == zoom_level)
		return (cache);
	prev_zoom_level = zoom_level;
	zoom_factor = pow(2, -(double)zoom_level / ZOOM_LEVEL_PER_2X);
	cache = DEFAULT_PIXEL_WIDTH * zoom_factor;
	return (cache);
}

void	put_speeds_to_img(t_fractal *f)
{
	int		x;
	int		y;
	t_hsv	hsv;

	y = 0;
	while (y < FRACT_HEIGHT)
	{
		x = 0;
		while (x < FRACT_WIDTH)
		{
			hsv = (t_hsv){.h = f->hue, .s = 255, .v = (uint8_t)f->speeds[x][y],
				.alpha = 0};
			put_pixel(f->img, x, y, hsv2rgb(hsv).mlx_color);
			x++;
		}
		y++;
	}
}
