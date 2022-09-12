/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:32:05 by susami            #+#    #+#             */
/*   Updated: 2022/09/12 00:08:31 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_dpoint	calc_origin(t_ipoint win_mouse_pnt, t_dpoint mouse_pnt,
				double step);

t_dpoint	calc_origin(t_ipoint win_mouse_pnt, t_dpoint mouse_pnt, double step)
{
	double	x;
	double	y;

	x = mouse_pnt.x - step * win_mouse_pnt.x;
	y = mouse_pnt.y + step * win_mouse_pnt.y;
	return ((t_dpoint){x, y});
}
