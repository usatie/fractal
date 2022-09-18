/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:00:10 by susami            #+#    #+#             */
/*   Updated: 2022/09/18 21:26:12 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include "fractol_color.h"
# include "fractol_util.h"
# include "fractol_ctx.h"

# define FRACT_WIDTH 400
# define FRACT_HEIGHT 400

# define CONFIG_WIDTH 400
# define CONFIG_HEIGHT 400

# define WIN_WIDTH 800
# define WIN_HEIGHT 400
# define WIN_TITLE "fract-ol"

// const values
extern const t_rect			g_rect_fractal;
extern const t_rect			g_rect_config;

// custom type
typedef uint32_t			t_speeds[400][400];
typedef uint32_t			t_div_f(t_complex point, uint32_t max_loop,
		const t_ctx *ctx);

// main.c
int			main(int argc, char **argv);
int			close_window(t_ctx *ctx);

// argparse.c
t_ctx		argparse(int argc, char **argv);
void		usage_err(void) __attribute__((noreturn));

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

// mlx_util.c
void		print_keycode(int keycode);

#endif
