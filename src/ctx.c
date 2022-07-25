/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:02:42 by susami            #+#    #+#             */
/*   Updated: 2022/07/25 19:18:30 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

bool	is_equal(t_ctx l, t_ctx r)
{
	(void)l;
	(void)r;
	return (false);
	/*
	return (
		l.win_mouse_pnt.x == r.win_mouse_pnt.x
		&& l.win_mouse_pnt.y == r.win_mouse_pnt.y
		&& l.mouse_pnt.x == r.mouse_pnt.x
		&& l.mouse_pnt.y == r.mouse_pnt.y
		&& l.step == r.step
		&& l.hue == r.hue
		&& l.max_loop == r.max_loop
		&& l.mode == r.mode
	);
	*/
}
