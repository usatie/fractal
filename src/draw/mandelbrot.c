/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:38:17 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 15:59:38 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "img.h"
#include "draw.h"

static bool	need_to_update(t_fractal *f);
static void	update_mandelbrot_speeds(t_fractal *f);

// Returns true if img is updated
bool	mandelbrot(t_fractal *f)
{
	if (need_to_update(f))
	{
		update_mandelbrot_speeds(f);
		normalize_speeds(f->speeds);
		put_speeds_to_img(f);
		return (true);
	}
	else if (f->color_rotation_enabled)
	{
		put_speeds_to_img(f);
		return (true);
	}
	else
		return (false);
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

static bool	need_to_update(t_fractal *f)
{
	static t_fractal	prev;
	bool				is_f_updated;

	if (f->force_update_flag)
	{
		prev = *f;
		f->force_update_flag = false;
		return (true);
	}
	is_f_updated = (
			prev.win_ptr == NULL
			|| prev.zoom_level != f->zoom_level
			|| prev.max_loop != f->max_loop
			|| prev.type != f->type
			);
	prev = *f;
	return (is_f_updated);
}
