/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:36:22 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 11:04:32 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	mouse_handler(int button, int x, int y, t_ctx *ctx)
{
	t_double_point	o;

	if (button == 4)
		ctx->step_n--;
	else if (button == 5)
		ctx->step_n++;
	else
		return (0);
	o = calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, ctx->step);
	ctx->mouse_pnt = (t_double_point){o.x + ctx->step * x, o.y - ctx->step * y};
	ctx->win_mouse_pnt = (t_int_point){x, y};
	ctx->step = 0.01 * pow(2, (double)ctx->step_n / 10);
	return (0);
}
