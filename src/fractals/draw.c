/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:03:17 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 22:53:16 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "draw.h"
#include "img.h"
#include "complex.h"

#define DEFAULT_PIXEL_WIDTH 0.01
#define ZOOM_LEVEL_PER_2X 10

bool	draw_fractal_to_img(t_fractal *f)
{
	bool	updated;

	updated = false;
	if (f->type == MANDELBROT)
		updated = mandelbrot(f);
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
	zoom_factor = pow(2, (double)zoom_level / ZOOM_LEVEL_PER_2X);
	cache = DEFAULT_PIXEL_WIDTH * zoom_factor;
	return (cache);
}

void	put_speeds_to_img(t_fractal *f)
{
	int				x;
	int				y;

	y = 0;
	while (y < FRACT_HEIGHT)
	{
		x = 0;
		while (x < FRACT_WIDTH)
		{
			put_pixel(f->img, x, y, f->speeds[x][y]);
			x++;
		}
		y++;
	}
}
