/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:36:22 by susami            #+#    #+#             */
/*   Updated: 2022/09/18 17:59:51 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "fractol_ctx.h"

/*

step:
   each -/|'s size is step
             
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
	mouse_before = o + step * (x, -y)

zoom :
	step is updated.

after zooom : 
	o is updated.
	o = mouse_before - step * (x, -y)

* Note that y axis is upside down.

*/

#define MOUSE_WHEEL_UP 4
#define MOUSE_WHEEL_DOWN 5

// zoom in/out can be done by updating `step_n` and `o`
int	mouse_handler(int button, int x, int y, t_ctx *ctx)
{
	double	next_step;
	double	prev_step;

	prev_step = step(ctx->step_n);
	if (button == MOUSE_WHEEL_UP)
		ctx->step_n--;
	else if (button == MOUSE_WHEEL_DOWN)
		ctx->step_n++;
	else
		return (0);
	next_step = step(ctx->step_n);
	ctx->o.x += (double)x * (prev_step - next_step);
	ctx->o.y -= (double)y * (prev_step - next_step);
	return (0);
}
