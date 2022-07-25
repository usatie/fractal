/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_playground.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:13:23 by susami            #+#    #+#             */
/*   Updated: 2022/07/25 12:45:02 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>

int	mandelbrot_divergence_speed(double a, double b)
{
	int		i;
	t_complex	c;
	t_complex	z;

	z = complex_new(0, 0);
	c = complex_new(a, b);
	i = 0;
	while (i++ < 255)
	{
		z = mandelbrot(z, c);
		//printf("z = %s\n", cstr(z));
		if (isinf(z.re) || isinf(z.im))
			return (256 - i);
	}
	return (256 - i);
}

void	math_playground(void)
{
	//printf("speed(%lf, %lf) = %d\n", 0.5, 0.2, mandlebrot_divergence_speed(0.5, 0.2));
	static int	w = 250;
	static int	h = 250;
	double step;
	int	x;
	int	y;

	step = 0.004;
	y = 0;
	while (y++ < h)
	{
		x = 0;
		while (x++ < w)
		{
			double	a;
			double	b;

			a = (double)x * step;
			b = (double)y * step;
			printf("speed(%lf, %lf) = %d\n", a, b, mandelbrot_divergence_speed(a, b));
		}
	}
}
