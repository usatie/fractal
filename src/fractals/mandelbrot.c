/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:38:17 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 22:58:40 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_core.h"
#include "complex.h"
#include "img.h"
#include "draw.h"

static bool	is_cache_available(t_fractal *f);

// Returns true if img is updated
bool	mandelbrot(t_fractal *f)
{
	const t_complex	z = (t_complex){0};
	t_complex		c;
	int				x;
	int				y;

	if (is_cache_available(f))
		return (false);
	y = 0;
	while (y < FRACT_HEIGHT)
	{
		x = 0;
		while (x < FRACT_WIDTH)
		{
			c = win_to_complex(x, y, f->center, pixel_width(f->zoom_level));
			f->speeds[x][y] = complex_iteration(z, c, f->max_loop);
			put_pixel(f->img, x, y, f->speeds[x][y]);
			x++;
		}
		y++;
	}
	normalize_speeds(f->speeds);
	put_speeds_to_img(f);
	return (true);
}

static bool	is_cache_available(t_fractal *f)
{
	static t_fractal	prev;
	bool				is_f_updated;

	is_f_updated = (
			prev.win_ptr == NULL
			|| prev.zoom_level != f->zoom_level
			|| prev.max_loop != f->max_loop
			|| prev.type != f->type
			);
	prev = *f;
	return (is_f_updated);
}
