/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:06:35 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 23:20:29 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdbool.h>
# include "fractol.h"
# include "complex.h"

extern t_fractal	g_prev;

// mandelbrot.c
bool		mandelbrot(t_fractal *f);

// julia.c
bool		julia(t_fractal *f);

// barnsley.c
bool		barnsley(t_fractal *f);

// help_msg.c
void		put_help_msg_to_window(void *mlx_ptr, void *win_ptr);

// draw.c
double		pixel_width(int zoom_level);
bool		draw_fractal_to_img(t_fractal *f);
void		put_speeds_to_img(t_fractal *f);

// win_to_complex.c
t_complex	win_to_complex(int x, int y, t_dpoint center, double pixel_width);

// normalize_speeds.c
void		normalize_speeds(t_speeds speeds);
#endif
