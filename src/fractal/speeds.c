/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speeds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:27:09 by susami            #+#    #+#             */
/*   Updated: 2022/09/12 19:22:22 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

static void		get_range(const t_speeds speeds,
					uint32_t *min_s, uint32_t *max_s);
static uint32_t	min(uint32_t a, uint32_t b);
static uint32_t	max(uint32_t a, uint32_t b);

// Returns the number of iterations needed to diverge.(for z to become infinite)
//
// Complex Iteration:
//   f(z) = z^2 + c
//
//   z1 = f(z0)
//   z2 = f(z1)
//   z3 = f(z2)
//   ...
uint32_t	complex_iteration_div(t_complex z, t_complex c,
		uint32_t max_loop)
{
	uint32_t	i;

	i = 0;
	while (i < max_loop)
	{
		z = cadd(cmul(z, z), c);
		if (isinf(z.re) || isinf(z.im))
			return (i);
		i++;
	}
	return (i);
}

// normalize to 0-255
void	normalize_speeds(t_speeds speeds)
{
	int			x;
	int			y;
	uint32_t	max_s;
	uint32_t	min_s;

	get_range(speeds, &min_s, &max_s);
	y = -1;
	while (++y < FRACT_HEIGHT)
	{
		x = -1;
		while (++x < FRACT_WIDTH)
		{
			speeds[x][y] -= min_s;
			if (max_s > min_s)
				speeds[x][y] = 255 * speeds[x][y] / (max_s - min_s);
		}
	}
}

static void	get_range(const t_speeds speeds, uint32_t *min_s, uint32_t *max_s)
{
	int	x;
	int	y;

	*min_s = speeds[0][0];
	*max_s = speeds[0][0];
	y = -1;
	while (++y < FRACT_HEIGHT)
	{
		x = -1;
		while (++x < FRACT_WIDTH)
		{
			*max_s = max(*max_s, speeds[x][y]);
			*min_s = min(*min_s, speeds[x][y]);
		}
	}
}

static uint32_t	min(uint32_t a, uint32_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static uint32_t	max(uint32_t a, uint32_t b)
{
	if (a > b)
		return (a);
	return (b);
}
