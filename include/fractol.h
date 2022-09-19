/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:00:10 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 21:12:56 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

# define FRACT_WIDTH 400
# define FRACT_HEIGHT 400

# define CONFIG_WIDTH 400
# define CONFIG_HEIGHT 400

# define WIN_WIDTH 800
# define WIN_HEIGHT 400
# define WIN_TITLE "fract-ol"

// custom type
typedef struct s_complex	t_complex;
typedef struct s_ipoint		t_ipoint;
typedef struct s_dpoint		t_dpoint;
typedef struct s_rect		t_rect;
typedef struct s_ctx		t_ctx;
typedef struct s_img		t_img;
typedef uint32_t			t_speeds[400][400];
typedef uint32_t			t_div_f(t_complex point, uint32_t max_loop,
		const t_ctx *ctx);
typedef enum e_mode {
	NORMAL_MODE,
	PSYCHEDELIC_MODE
}	t_mode;
typedef enum e_fractal_type {
	MANDELBROT,
	JULIA,
	BARNSLEY
}	t_fractal_type;

//typedef enum e_fractal_type { MANDELBROT, JULIA, BARNSLEY }	t_fractal_type;

// const values
extern const t_rect			g_rect_fractal;
extern const t_rect			g_rect_config;

// main.c
int			main(int argc, char **argv);
int			close_window(t_ctx *ctx);

// key_handler.c
int			key_handler(int keycode, t_ctx *ctx);

// mouse_handler.c
int			mouse_handler(int button, int x, int y, t_ctx *ctx);

// loop_handler.c
int			loop_handler(t_ctx *ctx);

// expose_handler.c
int			expose_handler(t_ctx *ctx);

// fractal.c
void		draw_fractal(const t_ctx *ctx);
bool		need_fractal_update(const t_ctx *ctx);
void		draw_complex_iteration_fractal(t_div_f f, const t_ctx *ctx);

// mandelbrot.c
void		draw_mandelbrot(const t_ctx *ctx);
// julia.c
void		draw_julia(const t_ctx *ctx);
// barnsley.c
void		draw_barnsley(const t_ctx *ctx);
// speeds.c
uint32_t	complex_iteration_div(t_complex z, t_complex c, uint32_t max_loop);
void		normalize_speeds(t_speeds speeds);

// img.c
void		init_img(t_img *img, void *mlx_ptr, int width, int height);
void		clear_img_rect(const t_img *img, t_rect rect);
void		put_pixel_in_img(const t_img *img, int x, int y, int color);

// complex.c
t_complex	complex_new(double re, double im);
t_complex	cadd(t_complex lhs, t_complex rhs);
t_complex	cmul(t_complex lhs, t_complex rhs);

// rect.c
bool		rect_contains(t_ipoint p, t_rect rect);

// double_util.c
bool		neq(double a, double b);

/*
   Complex number

   re — real part
   im — imaginary part
*/
struct s_complex {
	double	re;
	double	im;
};

struct s_ipoint {
	int	x;
	int	y;
};

struct s_dpoint {
	double	x;
	double	y;
};

struct s_rect {
	int	x;
	int	y;
	int	width;
	int	height;
};
#endif
