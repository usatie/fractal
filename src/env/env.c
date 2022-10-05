/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:18:40 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 20:58:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	setup_barnsley(t_fractal *f);
static void	setup_golden_bee(t_fractal *f);
static void	setup_fractal_tree(t_fractal *f);

void	setup_fractal(t_fractal *f, enum e_fractal type)
{
	f->type = type;
	f->color_rotation_enabled = false;
	f->julia_rotation_enabled = false;
	f->julia_degree = 0;
	f->center = (t_dpoint){0, 0};
	f->zoom_level = 0;
	f->hue = 0;
	if (type == MANDELBROT || type == JULIA)
		f->max_loop = 100;
	else if (type == BARNSLEY || type == CYCLOSORUS)
		setup_barnsley(f);
	else if (type == GOLDEN_BEE)
		setup_golden_bee(f);
	else if (type == FRACTAL_TREE)
		setup_fractal_tree(f);
}

static void	setup_barnsley(t_fractal *f)
{
	f->max_loop = 100000;
	f->center = (t_dpoint){0.5, 5.0};
	f->zoom_level = -20;
	f->hue = 100;
}

static void	setup_golden_bee(t_fractal *f)
{
	f->zoom_level = 5;
	f->max_loop = 100000;
	f->hue = 40;
}

static void	setup_fractal_tree(t_fractal *f)
{
	f->zoom_level = 20;
	f->max_loop = 100000;
	f->hue = 100;
}