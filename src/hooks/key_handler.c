/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:09 by susami            #+#    #+#             */
/*   Updated: 2022/09/26 15:07:28 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_core.h"
#include "keymap.h"
#include "draw.h"
#include "hooks.h"

int	key_handler(int keycode, t_env *e)
{
	t_fractal	*f;

	f = e->fractal;
	if (keycode == MK_ESCAPE)
		close_window(e);
	else if (keycode == MK_BRACKETLEFT && f->max_loop > 10)
		f->max_loop -= 10;
	else if (keycode == MK_BRACKETRIGHT && f->max_loop)
		f->max_loop += 10;
	else if (keycode == MK_LEFT)
		f->center.x -= pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_UP)
		f->center.y += pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_RIGHT)
		f->center.x += pixel_width(f->zoom_level) * 10;
	else if (keycode == MK_DOWN)
		f->center.y -= pixel_width(f->zoom_level) * 10;
	return (0);
}
