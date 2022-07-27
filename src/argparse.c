/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:27:47 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 10:29:57 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "libft.h"
#include "math.h"
#include <unistd.h>

void	ctx_update_step(t_ctx *ctx);
void	usageErr(void) __attribute__((noreturn));

void	usageErr(void)
{
	ft_dprintf(STDERR_FILENO, "Usage: ./fractol {Fractal Type} [--psychedelic | -p]\n");
	ft_dprintf(STDERR_FILENO, "Fractal Type: [Mandelbrot] [Julia] [Barnsley]\n");
	exit(EXIT_FAILURE);
}

t_fractal_type parse_fractal_type(char *arg)
{
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		return (Mandelbrot);
	else if (ft_strcmp(arg, "Julia") == 0)
		return (Julia);
	else if (ft_strcmp(arg, "Barnsley") == 0)
		return (Barnsley);
	else
		usageErr();
}

t_ctx	argparse(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc != 2)
		usageErr();
	ctx = (t_ctx){0};
	ctx.win_mouse_pnt = (t_int_point){FRACT_WIDTH / 2, FRACT_HEIGHT / 2};
	ctx.mouse_pnt = (t_double_point){0, 0};
	ctx.max_loop = 50;
	ctx.color_mode = Normal;
	ctx.julia_mode = Normal;
	ctx.fractal_type = parse_fractal_type(argv[1]);
	ctx.hue = 128;
	ctx.c_radian = M_PI / 180 * 120;
	ctx.c = cmul(complex_new(0.7885, 0), complex_new(cos(ctx.c_radian), sin(ctx.c_radian)));
	ctx_update_step(&ctx);
	return (ctx);
}

