/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:36:22 by susami            #+#    #+#             */
/*   Updated: 2022/09/17 22:36:52 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include <math.h>

t_dpoint	calc_origin(t_ipoint win_mouse_pnt, t_dpoint mouse_pnt,
				double step);

int	mouse_handler(int button, int x, int y, t_ctx *ctx)
{
	double	prev_step;

	prev_step = step(ctx->step_n);
	if (button == 4)
		ctx->step_n--;
	else if (button == 5)
		ctx->step_n++;
	else
		return (0);
	ctx->mouse_pnt = (t_dpoint){ctx->o.x + prev_step * x,
		ctx->o.y - prev_step * y};
	ctx->win_mouse_pnt = (t_ipoint){x, y};
	ctx->o = calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt,
			step(ctx->step_n));
	return (0);
}
