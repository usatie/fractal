/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:47:32 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 21:10:44 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_functions.h"
#include "argparse.h"

void	usage_err(void)
{
	err_exit(
		"Usage: ./fractol [options] fractal_type\n"
		"options:\n"
		"    -c               Color rotation\n"
		"    -j               Julia set rotation\n"
		"    -d <degree>      Julia set's initial degree. <0-359>\n"
		"fractal_type:\n"
		"    Mandelbrot\n"
		"    Julia\n"
		"    Barnsley\n"
		"    Cyclosorus\n"
		"    GoldenBee\n"
		"    FractalTree\n"
		);
}
