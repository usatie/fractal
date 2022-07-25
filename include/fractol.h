/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:00:10 by susami            #+#    #+#             */
/*   Updated: 2022/07/25 11:19:52 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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

t_rgb		hsv2rgb(t_hsv in);
int			rgb2mlxint(t_rgb rgb);
int			hsv2mlxint(t_hsv hsv);
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

t_complex	complex_new(double re, double im);
t_complex	cadd(t_complex lhs, t_complex rhs);
t_complex	csub(t_complex lhs, t_complex rhs);
t_complex	cmul(t_complex lhs, t_complex rhs);
t_complex	cdiv(t_complex c, t_complex b);
char		*cstr(t_complex z);
t_complex	mandelbrot(t_complex z, t_complex c);

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
**  Fract-ol Context
*/

/*
** re — real part
** im — imaginary part
*/
typedef struct s_ctx {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_int_point		win_mouse_pnt;
	t_double_point	mouse_pnt;
	int				step_n;
	double			step;
	unsigned char	hue;
}	t_ctx;
	//enum			fractal_type;

// Returns img_ptr
void		*get_fractal_img(void *mlx_ptr, t_double_point o,
				double step, unsigned char hue);
int			key_handler(int keycode, void *param);
int			mouse_handler(int button, int x, int y, void *param);
#endif
