/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_to_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:03:33 by susami            #+#    #+#             */
/*   Updated: 2022/10/04 22:41:42 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_complex	win_to_complex(int x, int y, t_dpoint center, double pixel_width)
{
	t_complex	c;

	x -= FRACT_WIDTH / 2;
	y -= FRACT_HEIGHT / 2;
	c.re = center.x + pixel_width * (double)x;
	c.im = center.y - pixel_width * (double)y;
	return (c);
}
