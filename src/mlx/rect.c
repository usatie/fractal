/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:49:57 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 16:09:33 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const t_rect	g_rect_fractal = (t_rect){
	.x = 0,
	.y = 0,
	.width = FRACT_WIDTH,
	.height = FRACT_HEIGHT
};

const t_rect	g_rect_config = (t_rect){
	.x = FRACT_WIDTH,
	.y = 0,
	.width = CONFIG_WIDTH,
	.height = CONFIG_HEIGHT
};

bool	rect_contains(t_ipoint p, t_rect rect)
{
	return (p.x >= rect.x && p.y >= rect.y
		&& p.x <= rect.width && p.y <= rect.height);
}
