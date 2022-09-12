/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speeds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:27:09 by susami            #+#    #+#             */
/*   Updated: 2022/09/12 17:26:14 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

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
	t_ipoint	p;
	uint32_t	max_speed;
	uint32_t	min_speed;

	max_speed = speeds[0][0];
	min_speed = speeds[0][0];
	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
		{
			max_speed = max(max_speed, speeds[p.x][p.y]);
			min_speed = min(min_speed, speeds[p.x][p.y]);
		}
	}
	max_speed = min(max_speed, min_speed + 10);
	p.y = -1;
	while (++p.y < FRACT_HEIGHT)
	{
		p.x = -1;
		while (++p.x < FRACT_WIDTH)
			speeds[p.x][p.y] = (speeds[p.x][p.y] - min_speed) * 255
				/ (max_speed - min_speed);
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
