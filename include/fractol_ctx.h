/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_ctx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:27:36 by susami            #+#    #+#             */
/*   Updated: 2022/09/11 00:06:12 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CTX_H
# define FRACTOL_CTX_H
# include "fractol.h"

// custom types
typedef struct s_ctx		t_ctx;
typedef struct s_img		t_img;
typedef enum e_mode			t_mode;
typedef enum e_fractal_type	t_fractal_type;

// ctx.c
void	ctx_on_update(t_ctx *ctx);
void	ctx_next_color_mode(t_ctx *ctx);
void	ctx_next_julia_mode(t_ctx *ctx);
void	ctx_next_fractal_type(t_ctx *ctx);

// ctx_put.c
void	put_ctx_to_window(t_ctx *ctx);
void	ctx_string_put(const t_ctx *ctx, int *height, char *str);

// ctx_put_config.c
// ctx_put_config2.c
void	ctx_put_config_fractal_mode(const t_ctx *ctx, int *height);
void	ctx_put_config_color_mode(const t_ctx *ctx, int *height);
void	ctx_put_config_julia_mode(const t_ctx *ctx, int *height);
void	ctx_put_config_max_loop(const t_ctx *ctx, int *height);
void	ctx_put_config_step(const t_ctx *ctx, int *height);
void	ctx_put_config_hue(const t_ctx *ctx, int *height);
void	ctx_put_config_radian(const t_ctx *ctx, int *height);
void	ctx_put_config_mouse_point(const t_ctx *ctx, int *height);

// custom type definitions
/*
   minilibx img container

   bpp         —   bits per pixel
   size_line   —   size of the line
   endian      —   endian
*/
struct s_img {
	void	*mlx_ptr;
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
};

enum e_mode { normal, psyc };
enum e_fractal_type { mandelbrot, julia, barnsley };

/*
    Fract-ol Context
*/
struct s_ctx {
	void			*mlx_ptr;
	void			*win_ptr;
	t_ipoint		win_mouse_pnt;
	t_dpoint		mouse_pnt;
	int				step_n;
	double			step;
	uint8_t			hue;
	uint32_t		max_loop;
	t_mode			color_mode;
	t_mode			julia_mode;
	t_fractal_type	fractal_type;
	double			c_radian;
	t_complex		c;
	t_img			fractal_img;
	t_img			config_img;
	t_dpoint		o;
};
#endif
