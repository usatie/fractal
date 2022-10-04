/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:09 by susami            #+#    #+#             */
/*   Updated: 2022/10/04 22:42:35 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keymap.h"
#include "draw.h"
#include "hooks.h"

static void	change_type(int keycode, t_fractal *f);
static void	increase_max_loop(t_fractal *f);
static void	decrease_max_loop(t_fractal *f);

int	key_handler(int keycode, t_env *e)
{
	t_fractal	*f;

	f = e->fractal;
	if (keycode == MK_ESCAPE)
		close_window(e);
	else if (keycode == MK_BRACKETLEFT && f->max_loop > 10)
		decrease_max_loop(f);
	else if (keycode == MK_BRACKETRIGHT && f->max_loop)
		increase_max_loop(f);
	else if (keycode == MK_LEFT)
		f->center.x -= pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_UP)
		f->center.y += pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_RIGHT)
		f->center.x += pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_DOWN)
		f->center.y -= pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_J || keycode == MK_M || keycode == MK_B)
		change_type(keycode, f);
	else if (keycode == MK_D)
		f->julia_rotation_enabled = !f->julia_rotation_enabled;
	else if (keycode == MK_C)
		f->color_rotation_enabled = !f->color_rotation_enabled;
	e->fractal->force_update_flag = true;
	return (0);
}

static void	increase_max_loop(t_fractal *f)
{
	if (f->type == MANDELBROT || f->type == JULIA)
		f->max_loop += 10;
	else if (f->type == BARNSLEY)
		f->max_loop = f->max_loop * 11 / 10;
}

static void	decrease_max_loop(t_fractal *f)
{
	if (f->type == MANDELBROT || f->type == JULIA)
		f->max_loop -= 10;
	else if (f->type == BARNSLEY)
		f->max_loop = f->max_loop * 10 / 11;
}

static void	change_type(int keycode, t_fractal *f)
{
	if (keycode == MK_J)
	{
		f->type = JULIA;
		f->max_loop = 100;
	}
	else if (keycode == MK_M)
	{
		f->type = MANDELBROT;
		f->max_loop = 100;
	}
	else if (keycode == MK_B)
	{
		f->type = BARNSLEY;
		f->max_loop = 100000;
	}
}
