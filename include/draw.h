/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:06:35 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 22:58:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdbool.h>
# include "fractol_core.h"
# include "complex.h"

// mandelbrot.c
bool		mandelbrot(t_fractal *f);

// draw.c
double		pixel_width(int zoom_level);
bool		draw_fractal_to_img(t_fractal *f);
void		put_speeds_to_img(t_fractal *f);

// win_to_complex.c
t_complex	win_to_complex(int x, int y, t_dpoint center, double pixel_width);

// normalize_speeds.c
void		normalize_speeds(t_speeds speeds);
#endif
