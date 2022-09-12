/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speeds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:27:09 by susami            #+#    #+#             */
/*   Updated: 2022/09/12 15:28:04 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			normalize_speeds(t_speeds speeds);
static uint32_t	min(uint32_t a, uint32_t b);
static uint32_t	max(uint32_t a, uint32_t b);

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
