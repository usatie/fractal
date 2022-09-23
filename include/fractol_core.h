/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_core.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:14:59 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 15:15:05 by susami           ###   ########.fr       */
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

typedef struct s_complex			t_complex;
typedef struct s_point				t_point;
typedef struct s_dpoint				t_dpoint;
typedef struct s_hsv				t_hsv;
typedef struct s_rgb				t_rgb;
typedef struct s_img				t_img;
typedef struct s_mandelbrot_ctx		t_mandelbrot_ctx;

enum e_fractal {
	MANDELBROT,
	JULIA,
	BARNSLEY
};

/*
   Complex number
   re — real part
   im — imaginary part
*/
struct s_complex {
	double	re;
	double	im;
};

struct s_point {
	int	x;
	int	y;
};

struct s_dpoint {
	double	x;
	double	y;
};

/*
   HSV Color
   h — Hue
   s — Saturation
   v — Value
   alpha — Alpha
*/
struct s_hsv {
	uint8_t	h;
	uint8_t	s;
	uint8_t	v;
	uint8_t	alpha;
};

/*
** r — Red
** g — Green
** b — Blue
** alpha — Alpha
*/
struct s_rgb {
	uint8_t	b:8;
	uint8_t	g:8;
	uint8_t	r:8;
	uint8_t	alpha:8;
};

union u_rgb {
	struct s_rgb	rgb;
	int32_t			mlx_color;
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
