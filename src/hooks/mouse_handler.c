/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:31:48 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 18:08:09 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mousemap.h"
#include "draw.h"
#include "hooks.h"

int	mouse_handler(int button, int x, int y, t_env *e)
{
	double	next_pixel_width;
	double	prev_pixel_width;	

	(void)button;
	(void)x;
	(void)y;
	(void)e;
	x -= FRACT_WIDTH / 2;
	y -= FRACT_HEIGHT / 2;
	prev_pixel_width = pixel_width(e->fractal->zoom_level);
	if (button == MOUSE_WHEEL_UP)
		e->fractal->zoom_level++;
	else if (button == MOUSE_WHEEL_DOWN)
		e->fractal->zoom_level--;
	else
		return (0);
	next_pixel_width = pixel_width(e->fractal->zoom_level);
	e->fractal->center.x += (double)x * (prev_pixel_width - next_pixel_width);
	e->fractal->center.y -= (double)y * (prev_pixel_width - next_pixel_width);
	return (0);
}
