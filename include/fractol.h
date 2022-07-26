/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:00:10 by susami            #+#    #+#             */
/*   Updated: 2022/07/26 22:38:41 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdbool.h>
# define XK_MISCELLANY 1
# define XK_XKB_KEYS 1

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

/*
**  minilibx img info
*/

/*
** bits_per_pixel — bits per pixel
** size_line — size of the line
** endian — endian
*/

typedef struct s_img_info {
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img_info;

typedef enum e_mode { Normal, Psyc }	t_mode;
typedef enum e_fractal_type {Mandelbrot, Julia, Barnsley}	t_fractal_type;

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
	void			*img_ptr;
	void			*help_img_ptr;
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
}	t_ctx;
	//enum			fractal_type;

bool			is_equal(t_ctx l, t_ctx r);

// Returns img_ptr
int				divergence_speed(t_complex z, t_complex c, int max_loop);
void			draw_fractal(void *img_ptr, t_double_point o,
					double step, unsigned char hue, int max_loop, t_fractal_type fractal_type, t_ctx ctx);
int				key_handler(int keycode, void *param);
int				mouse_handler(int button, int x, int y, void *param);

// print mlx keycode as readable format
void			print_keycode(int keycode);
t_double_point	calc_origin(t_int_point win_mouse_pnt,
					t_double_point mouse_pnt, double step);
int				close_window(t_ctx *ctx);

#endif
