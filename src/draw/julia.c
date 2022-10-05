/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:22:18 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 15:59:44 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "complex.h"
#include "img.h"
#include "draw.h"

#define JULIA_LEN 0.7885

static t_complex	julia_c(t_fractal *f);
static bool			need_to_update(t_fractal *f);
static void			update_julia_speeds(t_fractal *f);

// Returns true if img is updated
bool	julia(t_fractal *f)
{
	if (need_to_update(f))
	{
		update_julia_speeds(f);
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

static void	update_julia_speeds(t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			x;
	int			y;

	c = julia_c(f);
	y = 0;
	while (y < FRACT_HEIGHT)
	{
		x = 0;
		while (x < FRACT_WIDTH)
		{
			z = win_to_complex(x, y, f->center, pixel_width(f->zoom_level));
			f->speeds[x][y] = complex_iteration(z, c, f->max_loop);
			x++;
		}
		y++;
	}
}

static t_complex	julia_c(t_fractal *f)
{
	static uint32_t		degree = 0;
	static t_complex	c = (t_complex){JULIA_LEN, 0};

	if (degree != f->julia_degree)
	{
		degree = f->julia_degree;
		c = complex_new(
				JULIA_LEN * cos(M_PI * (double)degree / 180),
				JULIA_LEN * sin(M_PI * (double)degree / 180));
	}
	return (c);
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
			|| (f->julia_rotation_enabled
				&& prev.julia_degree != f->julia_degree)
			);
	prev = *f;
	return (is_f_updated);
}
