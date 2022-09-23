/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_speeds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:57:31 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 22:58:01 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol_core.h"

static void		get_range(const t_speeds speeds,
					uint32_t *min_s, uint32_t *max_s);
static uint32_t	min(uint32_t a, uint32_t b);
static uint32_t	max(uint32_t a, uint32_t b);

// normalize to 0-255
void	normalize_speeds(t_speeds speeds)
{
	int			x;
	int			y;
	uint32_t	max_s;
	uint32_t	min_s;

	get_range(speeds, &min_s, &max_s);
	y = 0;
	while (y < FRACT_HEIGHT)
	{
		x = 0;
		while (x < FRACT_WIDTH)
		{
			speeds[x][y] -= min_s;
			if (max_s > min_s)
				speeds[x][y] = 255 * speeds[x][y] / (max_s - min_s);
			x++;
		}
		y++;
	}
}

static void	get_range(const t_speeds speeds, uint32_t *min_s, uint32_t *max_s)
{
	int	x;
	int	y;

	*min_s = speeds[0][0];
	*max_s = speeds[0][0];
	y = 0;
	while (y < FRACT_HEIGHT)
	{
		x = 0;
		while (x < FRACT_WIDTH)
		{
			*max_s = max(*max_s, speeds[x][y]);
			*min_s = min(*min_s, speeds[x][y]);
			x++;
		}
		y++;
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
