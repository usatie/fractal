/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:14:59 by susami            #+#    #+#             */
/*   Updated: 2022/10/06 14:47:59 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

# define FRACT_WIDTH 400
# define FRACT_HEIGHT 400

# define FOOTER_WIDTH 400
# define FOOTER_HEIGHT 30

# define WIN_WIDTH 800
# define WIN_HEIGHT 430

# define DEBUG_WIN_W 400
# define DEBUG_WIN_H 400

# define WIN_TITLE "fract-ol"
# define DEBUG_WIN_TITLE "debug window"

typedef uint32_t			t_speeds[400][400];
typedef struct s_point		t_point;
typedef struct s_dpoint		t_dpoint;
typedef struct s_img		t_img;
typedef struct s_fractal	t_fractal;
typedef struct s_window		t_window;
typedef struct s_env		t_env;

enum e_fractal {
	MANDELBROT,
	JULIA,
	BARNSLEY,
	CYCLOSORUS,
	FRACTAL_TREE,
	GOLDEN_BEE,
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
   bits_per_pixel  —   bits per pixel to store color for one pixel.
   bytes_per_pixel —   [bits_per_pixel / 8]
   bytes_per_line  —   the number of bytes used to store one line of the image 
                       in memory. [bytes_per_pixel * img_width]
   endian          —   endian (0 = little endian, 1 = big endian)
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

struct s_fractal {
	enum e_fractal	type;

	void			*win_ptr;
	t_img			*img;
	t_img			*footer_img;

	int32_t			zoom_level;
	t_dpoint		center;

	uint8_t			hue;
	uint32_t		max_loop;

	bool			color_rotation_enabled;

	t_speeds		speeds;
	bool			force_update_flag;

	bool			julia_rotation_enabled;
	uint32_t		julia_degree;
};

struct s_env {
	void		*mlx_ptr;
	t_fractal	*fractal;
	void		*debug_win_ptr;
	t_img		*debug_img;
};

#endif
