/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_iteration.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:08:26 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 23:40:02 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rand.h"
#include "color.h"
#include "draw.h"
#include "affine.h"

static t_dpoint	ifs_affine(t_dpoint v,
					const t_ifs_config *config, int num_config);
static bool		put_to_speeds(t_dpoint v, t_fractal *f);

// Iterated Fuction System.
// Applies Affine Transformation iteratively.
bool	affine_iteration(t_fractal *f, const t_ifs_config *configv)
{
	t_dpoint	v;
	uint32_t	i;
	bool		updated;

	v = (t_dpoint){.x = 0, .y = 0};
	updated = false;
	i = 0;
	while (i < f->max_loop)
	{
		v = ifs_affine(v, configv, 4);
		updated |= put_to_speeds(v, f);
		i++;
	}
	return (updated);
}

// Apply Affine Transformation based on configured probabilities.
static t_dpoint	ifs_affine(t_dpoint v,
		const t_ifs_config *configv, int num_config)
{
	int		i;
	double	rng;

	rng = rand_one();
	i = 0;
	while (true)
	{
		if (rng < configv[i].p || i == num_config - 1)
			return (affine_transform(v, configv[i].affine));
		rng -= configv[i].p;
		i++;
	}
}

#define MAX_SPEED 255

// If `v` is in window, put to speeds.
static bool	put_to_speeds(t_dpoint v, t_fractal *f)
{
	double	width;
	int		x;
	int		y;

	width = pixel_width(f->zoom_level);
	if (fabs(v.x - f->center.x) > (double)FRACT_WIDTH * width)
		return (false);
	else if (fabs(v.y - f->center.y) > (double)FRACT_HEIGHT * width)
		return (false);
	x = FRACT_WIDTH / 2;
	y = FRACT_HEIGHT / 2;
	x += (int)((v.x - f->center.x) / width);
	y -= (int)((v.y - f->center.y) / width);
	if (x < 0 || x >= FRACT_WIDTH)
		return (false);
	else if (y < 0 || y >= FRACT_HEIGHT)
		return (false);
	if (f->speeds[x][y] == MAX_SPEED)
		return (false);
	f->speeds[x][y] = MAX_SPEED;
	return (true);
}
