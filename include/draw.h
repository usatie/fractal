/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:06:35 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 22:36:30 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdbool.h>
# include "fractol_core.h"
# include "complex.h"

// win_to_complex.c
t_complex	win_to_complex(int x, int y, t_dpoint center, double pixel_width);

// draw_fractal.c
double		pixel_width(int zoom_level);
bool		draw_fractal_to_img(t_fractal *f);
#endif
