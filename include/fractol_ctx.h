/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_ctx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:27:36 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 14:33:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CTX_H
# define FRACTOL_CTX_H
# include "fractol.h"

// custom types
typedef struct s_ctx		t_ctx;
typedef struct s_img		t_img;
typedef enum e_mode { NORMAL_MODE, PSYCHEDELIC_MODE }	t_mode;
typedef enum e_fractal_type { MANDELBROT, JULIA, BARNSLEY }	t_fractal_type;

// ctx.c
void	init_ctx(t_ctx *ctx);
void	next_color_mode(t_ctx *ctx);
void	next_julia_mode(t_ctx *ctx);
void	next_fractal(t_ctx *ctx);
double	pixel_width(int step_n);

// ctx_put.c
void	draw_ctx(t_ctx *ctx, bool force_update);
void	ctx_string_put(const t_ctx *ctx, int *height, char *str);

// ctx_put_config.c
// ctx_put_config2.c
void	put_fractal_type(const t_ctx *ctx, int *height);
void	put_color_mode(const t_ctx *ctx, int *height);
void	put_julia_mode(const t_ctx *ctx, int *height);
void	put_max_loop(const t_ctx *ctx, int *height);
void	put_pixel_width(const t_ctx *ctx, int *height);
void	put_hue(const t_ctx *ctx, int *height);
void	put_julia_degree(const t_ctx *ctx, int *height);
void	put_o(const t_ctx *ctx, int *height);

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

/*
    Fract-ol Context
*/
struct s_ctx {
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			fractal_img;
	t_img			clear_img;

	int				zoom_level;
	t_dpoint		center;

	uint32_t		max_loop;

	t_fractal_type	fractal_type;

	t_mode			color_mode;
	uint8_t			hue;

	t_mode			julia_mode;
	int				julia_degree;
};
#endif
