/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:09 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 20:51:15 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "keymap.h"
#include "draw.h"
#include "hooks.h"

static void	move_center(int keycode, t_fractal *f);
static void	change_type(t_fractal *f);
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
	else if (keycode == MK_LEFT || keycode == MK_RIGHT
		|| keycode == MK_UP || keycode == MK_DOWN)
		move_center(keycode, f);
	else if (keycode == MK_SPACE)
		change_type(f);
	else if (keycode == MK_J)
		f->julia_rotation_enabled = !f->julia_rotation_enabled;
	else if (keycode == MK_C)
		f->color_rotation_enabled = !f->color_rotation_enabled;
	return (0);
}

static void	move_center(int keycode, t_fractal *f)
{
	if (keycode == MK_LEFT)
		f->center.x -= pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_UP)
		f->center.y += pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_RIGHT)
		f->center.x += pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_DOWN)
		f->center.y -= pixel_width(f->zoom_level) * 10;
	f->force_update_flag = true;
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

static void	change_type(t_fractal *f)
{
	if (f->type == MANDELBROT)
		setup_fractal(f, JULIA);
	else if (f->type == JULIA)
		setup_fractal(f, BARNSLEY);
	else if (f->type == BARNSLEY)
		setup_fractal(f, CYCLOSORUS);
	else if (f->type == CYCLOSORUS)
		setup_fractal(f, FRACTAL_TREE);
	else if (f->type == FRACTAL_TREE)
		setup_fractal(f, GOLDEN_BEE);
	else if (f->type == GOLDEN_BEE)
		setup_fractal(f, MANDELBROT);
}
