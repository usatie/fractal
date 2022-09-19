/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:15:04 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 21:45:44 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "complex.h"
#include "ft_printf.h"

static uint32_t	div_f(t_complex point, uint32_t max_loop, const t_ctx *ctx);

void	draw_mandelbrot(const t_ctx *ctx)
{
	draw_complex_iteration_fractal(div_f, ctx);
}

// Mandelbrot set : f(z) = z^2 + c
//
// z0 : (0, 0)
// c  : (x, y)
static uint32_t	div_f(t_complex c, uint32_t max_loop, const t_ctx *ctx)
{
	static const t_complex	z = (t_complex){0};
	uint32_t				speed;

	(void)ctx;
	speed = complex_iteration_div(
			z,
			c,
			max_loop);
	return (speed);
}
