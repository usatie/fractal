/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_core.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:14:59 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 18:00:59 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CORE_H
# define FRACTOL_CORE_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

# define FRACT_WIDTH 400
# define FRACT_HEIGHT 400

# define CONFIG_WIDTH 400
# define CONFIG_HEIGHT 400

# define WIN_TITLE "fract-ol"

typedef struct s_point				t_point;
typedef struct s_dpoint				t_dpoint;
typedef struct s_img				t_img;
typedef struct s_mandelbrot_ctx		t_mandelbrot_ctx;
typedef struct s_window				t_window;
typedef struct s_env				t_env;

enum e_fractal {
	MANDELBROT,
	JULIA,
	BARNSLEY
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
   minilibx img container
   bpp         —   bits per pixel
   size_line   —   the number of bytes used to store one line of the image 
                   in memory (size_line = bpp * img_width)
   endian      —   endian (0 = little endian, 1 = big endian)
*/
struct s_img {
	void	*mlx_ptr;
	void	*ptr;
	char	*data;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		bytes_per_line;
	int		endian;
};

struct s_mandelbrot_ctx {
	t_img			fractal_img;
	int32_t			zoom_level;
	struct s_dpoint	center;

	uint8_t			hue;
	uint32_t		max_loop;

	bool			psychedelic_color_enabled;
};

struct s_window {
	void	*ptr;
	int		width;
	int		height;
	char	*title;
};

struct s_env {
	void			*mlx_ptr;
	struct s_window	*fractal_win;
	t_img			*fractal_img;
};

#endif
