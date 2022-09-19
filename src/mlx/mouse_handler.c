/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:36:22 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 14:25:41 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "fractol_ctx.h"

/*

pixel_width:
   each -/|'s size is pixel_width
             
o:
   The coordinate of the left top point of the window.

                (0,0)                        (x, 0)
   this point -> o-----------------------------*-------------------.
	             |                                                 |
	             |                                                 |
	             |                                                 |
	             |                                                 |
	             |                     window                      |
	             |                                                 |
	      (0, y) *                             *                   |
	             |                           mouse (x, y)          |
	             |                                                 |
	             .-------------------------------------------------.


before zoom :
	mouse_before = o + pixel_width * (x, -y)

zoom :
	pixel_width is updated.

after zooom : 
	o is updated.
	o = mouse_before - pixel_width * (x, -y)

* Note that y axis is upside down.

*/

#define MOUSE_WHEEL_UP 4
#define MOUSE_WHEEL_DOWN 5

// zoom in/out can be done by updating `zoom_level` and `o`
int	mouse_handler(int button, int x, int y, t_ctx *ctx)
{
	double	next_pixel_width;
	double	prev_pixel_width;

	prev_pixel_width = pixel_width(ctx->zoom_level);
	if (button == MOUSE_WHEEL_UP)
		ctx->zoom_level--;
	else if (button == MOUSE_WHEEL_DOWN)
		ctx->zoom_level++;
	else
		return (0);
	next_pixel_width = pixel_width(ctx->zoom_level);
	ctx->o.x += (double)x * (prev_pixel_width - next_pixel_width);
	ctx->o.y -= (double)y * (prev_pixel_width - next_pixel_width);
	return (0);
}
