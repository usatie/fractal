/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_iteration.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:08:26 by susami            #+#    #+#             */
/*   Updated: 2022/09/27 09:57:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// rand()
#include <stdlib.h>
#include <math.h>
#include "fractol_core.h"
#include "color.h"
#include "img.h"
#include "draw.h"
#include "affine.h"

static t_dpoint	probablistic_affine(t_dpoint v,
					const t_ifs_config *config, int num_config);
static t_dpoint	affine_transform(t_dpoint v, t_affine t);
static void		put_pixel_in_window(t_dpoint v, t_fractal *f);

// Iterated Fuction System.
// Applies Affine Transformation iteratively.
void	affine_iteration(t_fractal *f, const t_ifs_config *configv)
{
	static t_dpoint	v = (t_dpoint){.x = 0, .y = 0};
	uint32_t		i;

	i = 0;
	while (i < f->max_loop)
	{
		v = probablistic_affine(v, configv, 4);
		put_pixel_in_window(v, f);
		i++;
	}
}

// Apply Affine Transformation based on probabilities.
static t_dpoint	probablistic_affine(t_dpoint v,
		const t_ifs_config *configv, int num_config)
{
	int		i;
	double	rng;

	rng = rand() / (double)RAND_MAX;
	i = 0;
	while (true)
	{
		if (rng < configv[i].p || i == num_config - 1)
			return (affine_transform(v, configv[i].affine));
		rng -= configv[i].p;
		i++;
	}
}

/*
Apply Affine Transformation.

          ┌     ┐ ┌   ┐     ┌   ┐
f(x, y) = │ a b │ │ x │  +  │ e │  
          │ c d │ │ y │     │ f │
          └     ┘ └   ┘     └   ┘
*/
static t_dpoint	affine_transform(t_dpoint v, t_affine t)
{
	t_dpoint	ret;

	ret.x = (t.a * v.x + t.b * v.y) + t.e;
	ret.y = (t.c * v.x + t.d * v.y) + t.f;
	return (ret);
}

// If `v` is in window, put pixel.
static void	put_pixel_in_window(t_dpoint v, t_fractal *f)
{
	double	width;
	int		x;
	int		y;

	width = pixel_width(f->zoom_level);
	if (fabs(v.x - f->center.x) > (double)FRACT_WIDTH * width)
		return ;
	else if (fabs(v.y - f->center.y) > (double)FRACT_HEIGHT * width)
		return ;
	x = FRACT_WIDTH / 2;
	y = FRACT_HEIGHT / 2;
	x += (int)((v.x - f->center.x) / width);
	y -= (int)((v.y - f->center.y) / width);
	if (x < 0 || x >= FRACT_WIDTH)
		return ;
	else if (y < 0 || y >= FRACT_HEIGHT)
		return ;
	put_pixel(f->img, x, y, green().mlx_color);
}
