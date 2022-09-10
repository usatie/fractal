/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:36:22 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 20:22:12 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include <math.h>

int	mouse_handler(int button, int x, int y, t_ctx *ctx)
{
	if (button == 4)
		ctx->step_n--;
	else if (button == 5)
		ctx->step_n++;
	else
		return (0);
	ctx->mouse_pnt = (t_double_point){ctx->o.x + ctx->step * x,
		ctx->o.y - ctx->step * y};
	ctx->win_mouse_pnt = (t_int_point){x, y};
	ctx_on_update(ctx);
	return (0);
}
