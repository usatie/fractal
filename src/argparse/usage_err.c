/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:47:32 by susami            #+#    #+#             */
/*   Updated: 2022/10/04 22:48:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_functions.h"
#include "argparse.h"

void	usage_err(void)
{
	err_exit(
		"Usage: ./fractol [options] fractal_type\n"
		"options:\n"
		"    -j <angle>      Julia set parameter. <0-359>\n"
		"fractal_type:\n"
		"    Mandelbrot\n"
		"    Julia\n"
		"    Barnsley\n");
}
