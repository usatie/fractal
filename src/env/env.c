/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:18:40 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 18:09:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	setup_fractal(t_fractal *f, enum e_fractal type)
{
	if (f->type == type)
		return ;
	f->type = type;
	f->color_rotation_enabled = false;
	f->julia_rotation_enabled = false;
	f->julia_degree = 0;
	if (type == MANDELBROT || type == JULIA)
	{
		f->max_loop = 100;
		f->center = (t_dpoint){0, 0};
		f->zoom_level = 0;
		f->hue = 0;
	}
	else if (type == BARNSLEY)
	{
		f->max_loop = 100000;
		f->center = (t_dpoint){0.5, 5.0};
		f->zoom_level = -20;
		f->hue = 100;
	}
}
