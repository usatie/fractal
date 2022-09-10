/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:00:10 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 15:42:32 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdbool.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 400
# define WIN_TITLE "fract-ol"

# define FRACT_WIDTH 400
# define FRACT_HEIGHT 400

# define HELP_WIDTH 400
# define HELP_HEIGHT 400

/*
**  HSV Color
*/

/*
** h — Hue
** s — Saturation
** v — Value
** alpha — Alpha
*/
typedef struct s_hsv {
	unsigned char	h;
	unsigned char	s;
	unsigned char	v;
	unsigned char	alpha;
}	t_hsv;

/*
**  RGB Color
*/

/*
** r — Red
** g — Green
** b — Blue
** alpha — Alpha
*/
typedef struct __attribute__((packed)) s_rgb {
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	alpha;
}	t_rgb;

t_rgb			hsv2rgb(t_hsv in);
int				rgb2mlxint(t_rgb rgb);
int				hsv2mlxint(t_hsv hsv);
/*
**  Complex number
*/

/*
** re — real part
** im — imaginary part
*/
typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

t_complex		complex_new(double re, double im);
t_complex		cadd(t_complex lhs, t_complex rhs);
t_complex		csub(t_complex lhs, t_complex rhs);
t_complex		cmul(t_complex lhs, t_complex rhs);
t_complex		cdiv(t_complex c, t_complex b);
char			*cstr(t_complex z);
t_complex		mandelbrot(t_complex z, t_complex c);

/*
**  Integer Point
*/

/*
** x — int x
** y — int y
*/
typedef struct s_int_point {
	int	x;
	int	y;
}	t_int_point;

/*
**  Double Point
*/

/*
** x — double x
** y — double y
*/
typedef struct s_double_point {
	double	x;
	double	y;
}	t_double_point;

typedef struct s_img_info {
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img_info;

typedef enum e_mode { Normal, Psyc }	t_mode;
typedef enum e_fractal_type {Mandelbrot, Julia, Barnsley}	t_fractal_type;

typedef struct s_rect {
	int	x;
	int	y;
	int	width;
	int	height;
}	t_rect;

typedef unsigned int	t_speeds[400][400];
static const t_rect		g_rect_fractal
	= (t_rect){0, 0, FRACT_WIDTH, FRACT_HEIGHT};
static const t_rect		g_rect_help
	= (t_rect){FRACT_WIDTH, 0, HELP_WIDTH, HELP_HEIGHT};
bool			rect_contains(t_int_point p, t_rect rect);

/*
**  minilibx img container
*/

/*
** bpp — bits per pixel
** size_line — size of the line
** endian — endian
*/
typedef struct s_img {
	void	*mlx_ptr;
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

/*
**  Fract-ol Context
*/

/*
** mlx_ptr — 
** win_ptr — 
** img_ptr — 
** win_mouse_pnt — 
** mouse_pnt — 
** step_n — 
** step — 
** hue — 
*/
typedef struct s_ctx {
	void			*mlx_ptr;
	void			*win_ptr;
	t_int_point		win_mouse_pnt;
	t_double_point	mouse_pnt;
	int				step_n;
	double			step;
	unsigned char	hue;
	t_hsv			base_hsv;
	unsigned int	max_loop;
	t_mode			color_mode;
	t_mode			julia_mode;
	t_fractal_type	fractal_type;
	double			c_radian;
	t_complex		c;
	t_img			fractal_img;
	t_img			help_img;
	t_double_point	o;
}	t_ctx;
	//enum			fractal_type;

bool			is_equal(t_ctx l, t_ctx r);

// Returns img_ptr
unsigned int	divergence_speed(t_complex z, t_complex c,
					unsigned int max_loop);
void			draw_fractal(const t_ctx *ctx);
int				key_handler(int keycode, t_ctx *ctx);
int				mouse_handler(int button, int x, int y, t_ctx *ctx);
int				loop_handler(t_ctx *ctx);

// print mlx keycode as readable format
void			print_keycode(int keycode);
//t_double_point	calc_origin(t_int_point win_mouse_pnt,
					//t_double_point mouse_pnt, double step);
int				close_window(t_ctx *ctx);
void			init_img(t_img *img, void *mlx_ptr, int width, int height);
void			clear_win_rect(void *mlx_ptr, void *win_ptr, t_rect rect);
void			clear_img_rect(const t_img *img, t_rect rect);
void			put_pixel_in_img(const t_img *img, int x, int y, int color);
void			draw_mandelbrot(const t_ctx *ctx);
void			draw_julia(const t_ctx *ctx);
void			draw_barnsley(const t_ctx *ctx);
unsigned int	mandelbrot_div_speed(t_complex z, t_complex c,
					unsigned int max_loop);

t_ctx			argparse(int argc, char **argv);

//void			ctx_update_step(t_ctx *ctx);
void			ctx_next_color_mode(t_ctx *ctx);
void			ctx_next_julia_mode(t_ctx *ctx);
void			ctx_next_fractal_type(t_ctx *ctx);
void			ctx_on_update(t_ctx *ctx);
bool			ctx_is_updated(t_ctx *ctx);
bool			need_fractal_update(const t_ctx *ctx);

void			put_ctx_to_window(t_ctx *ctx);

int				green(void);
int				red(void);
#endif
