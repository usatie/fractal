/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:45:30 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 10:47:15 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>
#include <keysymdef.h>
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <X11/X.h>

void	clear_win_rect(void *mlx_ptr, void *win_ptr, t_rect rect);

t_double_point	calc_origin(t_int_point win_mouse_pnt,
		t_double_point mouse_pnt, double step)
{
	double	x;
	double	y;

	x = mouse_pnt.x - step * win_mouse_pnt.x;
	y = mouse_pnt.y + step * win_mouse_pnt.y;
	return ((t_double_point){x, y});
}

int	close_window(t_ctx *ctx)
{
	mlx_key_hook(ctx->win_ptr, NULL, NULL);
	mlx_mouse_hook(ctx->win_ptr, NULL, NULL);
	mlx_expose_hook(ctx->win_ptr, NULL, NULL);
	mlx_loop_hook(ctx->mlx_ptr, NULL, NULL);
	mlx_destroy_image(ctx->mlx_ptr, ctx->img_ptr);
	mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
	free(ctx->mlx_ptr);
	exit(0);
}

int	divergence_speed(t_complex z, t_complex c, int max_loop)
{
	int			i;

	i = -1;
	while (++i < max_loop)
	{
		z = mandelbrot(z, c);
		if (isinf(z.re) || isinf(z.im))
			return (i);
	}
	return (i);
}

void	draw_barnsley(void *img_ptr, t_ctx ctx)
{
	float		rng;
	t_complex	c;
	int			x;
	int			y;
	char		*img;
	t_img_info	img_info;
	unsigned int			i;
	t_double_point	o;

	(void)img_ptr;
	img = mlx_get_data_addr(ctx.img_ptr,
			&img_info.bits_per_pixel, &img_info.size_line, &img_info.endian);
	y = -1;
	while (++y < FRACT_HEIGHT)
	{
		x = -1;
		while (++x < FRACT_WIDTH)
			*((int *)img + FRACT_HEIGHT * y + x) = rgb2mlxint((t_rgb){0, 0, 0, 0});
	}

	o = calc_origin(ctx.win_mouse_pnt, ctx.mouse_pnt, ctx.step),
	i = 0;
	while (++i < pow(10, 4 + (double)ctx.max_loop / 100))
	{
		rng = ((float)rand()) / RAND_MAX;
		if (rng <= 0.01f)
			c = complex_new(0, 0.16f * c.im);
		else if (rng <= 0.06f)
			c = complex_new(-0.15f * c.re + 0.28f * c.im,
					0.26f * c.re + 0.24f * c.im + 0.44f);
		else if (rng <= 0.06f)
			c = complex_new(0.2f * c.re + -0.26f * c.im,
					0.23f * c.re + 0.22f * c.im + 1.6f);
		else
			c = complex_new(0.85f * c.re + 0.04f * c.im,
					-0.04f * c.re + 0.85f * c.im + 1.6f);
		x = (c.re - o.x) / ctx.step;
		y = (o.y - c.im) / ctx.step;
		if (x >= 0 && y >= 0 && x <= FRACT_WIDTH && y <= FRACT_HEIGHT)
			*((int *)img + FRACT_HEIGHT * y + x) = green();
	}
}

void	draw_fractal(void *img_ptr, t_double_point o,
				double step, unsigned char hue, int max_loop, t_fractal_type fractal_type, t_ctx ctx)
{
	int						x;
	int						y;
	int						speed;
	t_hsv					hsv;
	t_img_info				img_info;
	char					*img;
	static t_double_point	prev_o;
	static double			prev_step;
	static int				prev_max_loop;
	static double			prev_c_radian;
	static t_fractal_type	prev_fractal_type;
	static int				speeds[FRACT_WIDTH][FRACT_HEIGHT];
	bool					is_updated;

	is_updated = (prev_step != step)
		|| (prev_o.x != o.x)
		|| (prev_o.y != o.y)
		|| (prev_max_loop != max_loop)
		|| (prev_c_radian != ctx.c_radian)
		|| (prev_fractal_type != ctx.fractal_type);
	prev_o = o;
	prev_step = step;
	prev_max_loop = max_loop;
	prev_c_radian = ctx.c_radian;
	prev_fractal_type = ctx.fractal_type;
	if (is_updated && ctx.fractal_type == Barnsley)
		draw_barnsley(ctx.img_ptr, ctx);
	if (ctx.fractal_type == Barnsley)
		return ;
	img = mlx_get_data_addr(img_ptr,
			&img_info.bits_per_pixel, &img_info.size_line, &img_info.endian);
	y = -1;
	while (++y < FRACT_HEIGHT)
	{
		x = -1;
		while (++x < FRACT_WIDTH)
		{
			if (is_updated)
			{
				if (fractal_type == Mandelbrot)
					speed = divergence_speed(
							complex_new(0, 0),
							complex_new(o.x + step * (double)x, o.y - step * (double)y),
							max_loop);
				else if (fractal_type == Julia)
					speed = divergence_speed(
							complex_new(o.x + step * (double)x, o.y - step * (double)y),
							ctx.c,
							max_loop);
				else
					exit(EXIT_FAILURE);
				speeds[x][y] = speed;
			}
			else
				speed = speeds[x][y];
			hsv = (t_hsv){(hue + speed * 256 / ctx.max_loop) % 256, 255, 150, 0};
			*((int *)img + FRACT_HEIGHT * y + x) = hsv2mlxint(hsv);
		}
	}
}

void	put_ctx_info(t_ctx *ctx)
{
	t_rgb			red;
	char			*str;
	int				height;

	clear_win_rect(ctx->mlx_ptr, ctx->win_ptr, (t_rect){FRACT_WIDTH, 0, HELP_WIDTH, HELP_HEIGHT});
	red = (t_rgb){.r = 255};
	height = 30;
	if (ctx->fractal_type == Mandelbrot)
		asprintf(&str, "fractal type: %s", "Mandelbrot");
	else if (ctx->fractal_type == Julia)
		asprintf(&str, "fractal type: %s", "Julia");
	else if (ctx->fractal_type == Barnsley)
		asprintf(&str, "fractal type: %s", "Barnsley");
	else
		asprintf(&str, "fractal type: %s", "Unknown");
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	if (ctx->color_mode == Normal)
		asprintf(&str, "color mode: %s", "Normal");
	else if (ctx->color_mode == Psyc)
		asprintf(&str, "color mode: %s", "Psychedelic");
	else
		asprintf(&str, "color mode: %s", "Unknown");
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	if (ctx->julia_mode == Normal)
		asprintf(&str, "julia mode: %s", "Normal");
	else if (ctx->julia_mode == Psyc)
		asprintf(&str, "julia mode: %s", "Psychedelic");
	else
		asprintf(&str, "julia mode: %s", "Unknown");
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "max_loop: %d", ctx->max_loop);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "step[= 1 pixel] : %.20f", ctx->step);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "hue: %d", ctx->hue);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "c_radian: %lfpi", (ctx->c_radian / M_PI - (double)(int)(ctx->c_radian / M_PI / 2)*2));
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "win_mouse_pnt: (%d, %d)", ctx->win_mouse_pnt.x, ctx->win_mouse_pnt.y);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "mouse_pnt: (%lf, %lf)", ctx->mouse_pnt.x, ctx->mouse_pnt.y);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
}

int	loop_handler(void *param)
{
	static bool		lock;
	static size_t	cnt;
	t_ctx			*ctx;

	if (cnt++ % 1000 != 0 || lock)
		return (0);
	lock = true;
	ctx = (t_ctx *)param;
	if (ctx->color_mode == Psyc)
		ctx->hue += 4;
	if (ctx->julia_mode == Psyc)
	{
		ctx->c_radian += M_PI / 60;
		ctx->c = cmul(complex_new(0.7885, 0), complex_new(cos(ctx->c_radian), sin(ctx->c_radian)));
	}
	draw_fractal(ctx->img_ptr,
			calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, ctx->step),
			ctx->step,
			ctx->hue,
			ctx->max_loop,
			ctx->fractal_type,
			*ctx);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, ctx->img_ptr, 0, 0);
	put_ctx_info(ctx);
	lock = false;
	return (0);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	ctx = argparse(argc, argv);
	ctx.mlx_ptr = mlx_init();
	ctx.win_ptr = mlx_new_window(ctx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	ctx.img_ptr = mlx_new_image(ctx.mlx_ptr, FRACT_WIDTH, FRACT_HEIGHT);
	put_ctx_info(&ctx);
	mlx_do_key_autorepeaton(ctx.mlx_ptr);
	mlx_hook(ctx.win_ptr, KeyPress, KeyPressMask, key_handler, &ctx);
	mlx_mouse_hook(ctx.win_ptr, mouse_handler, &ctx);
	mlx_loop_hook(ctx.mlx_ptr, loop_handler, &ctx);
	mlx_hook(ctx.win_ptr, ClientMessage, StructureNotifyMask, close_window, &ctx);
	mlx_loop(ctx.mlx_ptr);
	return (0);
}
