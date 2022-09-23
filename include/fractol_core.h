/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_core.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:14:59 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 13:56:31 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CORE_H
# define FRACTOL_CORE_H

# include <stdbool.h>
# include <stdint.h>

# define FRACT_WIDTH 400
# define FRACT_HEIGHT 400

# define CONFIG_WIDTH 400
# define CONFIG_HEIGHT 400

# define WIN_TITLE "fract-ol"

enum e_fractal {
	MANDELBROT,
	JULIA,
	BARNSLEY
};

struct s_complex {
	double	re;
	double	im;
};

struct s_dpoint {
	double	x;
	double	y;
};

/*
   minilibx img container
   bpp         —   bits per pixel
   size_line   —   the number of bytes used to store one line of the image 
                   in memory (size_line = bpp * img_width)
   endian      —   endian (0 = little endian, 1 = big endian)
*/
struct s_img {
	void	*ptr;
	char	*data;
	int		*bpp;
	int		*size_line;
	int		*endian;
};

struct s_mandelbrot_ctx {
	t_img			fractal_img;
	int32_t			zoom_level;
	struct s_dpoint	center;

	uint8_t			hue;
	uint32_t		max_loop;

	bool			psychedelic_color_enabled;
};

#endif
