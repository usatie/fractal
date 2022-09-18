/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:36:22 by susami            #+#    #+#             */
/*   Updated: 2022/09/18 14:25:48 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "fractol_ctx.h"

int	mouse_handler(int button, int x, int y, t_ctx *ctx)
{
	double	next_step;
	double	prev_step;

	prev_step = step(ctx->step_n);
	if (button == 4)
		ctx->step_n--;
	else if (button == 5)
		ctx->step_n++;
	else
		return (0);
	next_step = step(ctx->step_n);
	ctx->o.x += x * (prev_step - next_step);
	ctx->o.y -= y * (prev_step - next_step);
	return (0);
}
