/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:59:10 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 16:03:24 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "fractol_color.h"

// Looked up this conversion code from here
// https://stackoverflow.com/a/14733008
t_rgb	hsv2rgb(t_hsv in)
{
	uint8_t	region;
	uint8_t	remainder;
	uint8_t	p;
	uint8_t	q;
	uint8_t	t;

	if (in.s == 0)
		return (rgb(in.v, in.v, in.v, in.alpha));
	region = in.h / 43;
	remainder = (in.h - (region * 43)) * 6;
	p = (in.v * (255 - in.s)) >> 8;
	q = (in.v * (255 - ((in.s * remainder) >> 8))) >> 8;
	t = (in.v * (255 - ((in.s * (255 - remainder)) >> 8))) >> 8;
	if (region == 0)
		return (rgb(in.v, t, p, in.alpha));
	else if (region == 1)
		return (rgb(q, in.v, p, in.alpha));
	else if (region == 2)
		return (rgb(p, in.v, t, in.alpha));
	else if (region == 3)
		return (rgb(p, q, in.v, in.alpha));
	else if (region == 4)
		return (rgb(t, p, in.v, in.alpha));
	else
		return (rgb(in.v, p, q, in.alpha));
}

t_rgb	green(void)
{
	return (rgb(0, 255, 0, 0));
}

t_rgb	red(void)
{
	return (rgb(255, 0, 0, 0));
}

t_rgb	black(void)
{
	return (rgb(0, 0, 0, 0));
}

t_rgb	rgb(uint8_t r, uint8_t g, uint8_t b,
				uint8_t alpha)
{
	struct s_rgb	color;

	color = (struct s_rgb){.r = r, .g = g, .b = b, .alpha = alpha};
	return ((t_rgb){color});
}
