/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:59:10 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 10:46:15 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Looked up this conversion code from here
// https://stackoverflow.com/a/14733008
t_rgb	hsv2rgb(t_hsv in)
{
	unsigned char	region;
	unsigned char	remainder;
	unsigned char	p;
	unsigned char	q;
	unsigned char	t;

	if (in.s == 0)
		return ((t_rgb){.r = in.v, .g = in.v, .b = in.v, .alpha = in.alpha});
	region = in.h / 43;
	remainder = (in.h - (region * 43)) * 6;
	p = (in.v * (255 - in.s)) >> 8;
	q = (in.v * (255 - ((in.s * remainder) >> 8))) >> 8;
	t = (in.v * (255 - ((in.s * (255 - remainder)) >> 8))) >> 8;
	if (region == 0)
		return ((t_rgb){.r = in.v, .g = t, .b = p, .alpha = in.alpha});
	else if (region == 1)
		return ((t_rgb){.r = q, .g = in.v, .b = p, .alpha = in.alpha});
	else if (region == 2)
		return ((t_rgb){.r = p, .g = in.v, .b = t, .alpha = in.alpha});
	else if (region == 3)
		return ((t_rgb){.r = p, .g = q, .b = in.v, .alpha = in.alpha});
	else if (region == 4)
		return ((t_rgb){.r = t, .g = p, .b = in.v, .alpha = in.alpha});
	else
		return ((t_rgb){.r = in.v, .g = p, .b = q, .alpha = in.alpha});
}

int	rgb2mlxint(t_rgb rgb)
{
	return (*(int *)&rgb);
}

int	hsv2mlxint(t_hsv hsv)
{
	return (rgb2mlxint(hsv2rgb(hsv)));
}

int	green(void)
{
	return (rgb2mlxint(((t_rgb){0, 255, 0, 0})));
}

int	red(void)
{
	return (rgb2mlxint(((t_rgb){255, 0, 0, 0})));
}
