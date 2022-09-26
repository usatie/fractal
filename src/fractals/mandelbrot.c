/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:38:17 by susami            #+#    #+#             */
/*   Updated: 2022/09/26 14:37:21 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_core.h"
#include "complex.h"
#include "img.h"
#include "draw.h"

static bool	is_cache_available(t_fractal *f);
static void	update_mandelbrot_speeds(t_fractal *f);

// Returns true if img is updated
bool	mandelbrot(t_fractal *f)
{
	if (is_cache_available(f))
		return (false);
	update_mandelbrot_speeds(f);
	normalize_speeds(f->speeds);
	put_speeds_to_img(f);
	return (true);
}

static void	update_mandelbrot_speeds(t_fractal *f)
{
	const t_complex	z = (t_complex){0};
	t_complex		c;
	int				x;
	int				y;

	y = 0;
	while (y < FRACT_HEIGHT)
	{
		x = 0;
		while (x < FRACT_WIDTH)
		{
			c = win_to_complex(x, y, f->center, pixel_width(f->zoom_level));
			f->speeds[x][y] = complex_iteration(z, c, f->max_loop);
			x++;
		}
		y++;
	}
}

static bool	is_cache_available(t_fractal *f)
{
	static t_fractal	prev;
	bool				need_to_update;

	need_to_update = (
			prev.win_ptr == NULL
			|| prev.zoom_level != f->zoom_level
			|| prev.max_loop != f->max_loop
			|| prev.type != f->type
			);
	prev = *f;
	return (need_to_update);
}
