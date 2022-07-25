/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:45:30 by susami            #+#    #+#             */
/*   Updated: 2022/07/25 23:59:11 by susami           ###   ########.fr       */
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

#define WIN_WIDTH 600
#define WIN_HEIGHT 300
#define WIN_TITLE "fract-ol"

#define FRACT_WIDTH 300
#define FRACT_HEIGHT 300

#define HELP_WIDTH 300
#define HELP_HEIGHT 300

void			mlx_playground(void);
void			math_playground(void);

t_double_point	calc_origin(t_int_point win_mouse_pnt,
		t_double_point mouse_pnt, double step)
{
	double	x;
	double	y;

	x = mouse_pnt.x - step * win_mouse_pnt.x;
	y = mouse_pnt.y + step * win_mouse_pnt.y;
	return ((t_double_point){x, y});
}

int	close_window(void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)param;
	mlx_key_hook(ctx->win_ptr, NULL, NULL);
	mlx_mouse_hook(ctx->win_ptr, NULL, NULL);
	mlx_expose_hook(ctx->win_ptr, NULL, NULL);
	mlx_loop_hook(ctx->mlx_ptr, NULL, NULL);
	(void)mlx_destroy_image(ctx->mlx_ptr, ctx->img_ptr);
	(void)mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
	exit(0);
}

int	mandelbrot_divergence_speed(double a, double b, int max_loop)
{
	int			i;
	t_complex	c;
	t_complex	z;

	z = complex_new(0, 0);
	c = complex_new(a, b);
	i = -1;
	while (++i < max_loop)
	{
		z = mandelbrot(z, c);
		if (isinf(z.re) || isinf(z.im))
			return (i);
	}
	return (i);
}

void	*get_clear_img(void *mlx_ptr, int width, int height)
{
	int						x;
	int						y;
	void					*img_ptr;
	t_img_info				img_info;
	char					*img;

	img_ptr = mlx_new_image(mlx_ptr, height, height);
	img = mlx_get_data_addr(img_ptr,
			&img_info.bits_per_pixel, &img_info.size_line, &img_info.endian);
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			*((int *)img + height * y + x) = rgb2mlxint((t_rgb){0, 0, 0, 0});
	}
	return (img_ptr);
}

void	draw_mandelbrot(void *img_ptr, t_double_point o,
				double step, unsigned char hue, int max_loop)
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
	static int				speeds[FRACT_WIDTH][FRACT_HEIGHT];
	bool					is_updated;

	is_updated = (prev_step != step)
		|| (prev_o.x != o.x)
		|| (prev_o.y != o.y)
		|| (prev_max_loop != max_loop);
	prev_o = o;
	prev_step = step;
	prev_max_loop = max_loop;
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
				speed = mandelbrot_divergence_speed(o.x + step * (double)x,
						o.y - step * (double)y,
						max_loop);
				speeds[x][y] = speed;
			}
			else
				speed = speeds[x][y];
			hsv = (t_hsv){(hue + speed) % 256, 255, 150, 0};
			*((int *)img + FRACT_HEIGHT * y + x) = hsv2mlxint(hsv);
		}
	}
}

void	put_ctx_info(t_ctx *ctx)
{
	t_rgb			red;
	char			*str;
	int				height;
	void			*img_ptr;

	img_ptr = get_clear_img(ctx->mlx_ptr, HELP_WIDTH, HELP_HEIGHT);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, img_ptr, FRACT_WIDTH, 0);
	mlx_destroy_image(ctx->mlx_ptr, img_ptr);
	red = (t_rgb){.r = 255};
	height = 50;
	if (ctx->mode == Normal)
		asprintf(&str, "mode: %s", "Normal");
	else if (ctx->mode == Psyc)
		asprintf(&str, "mode: %s", "Psychedelic");
	else
		asprintf(&str, "mode: %s", "Unknown");
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
	asprintf(&str, "win_mouse_pnt: (%d, %d)", ctx->win_mouse_pnt.x, ctx->win_mouse_pnt.y);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
	asprintf(&str, "mouse_pnt: (%lf, %lf)", ctx->mouse_pnt.x, ctx->mouse_pnt.y);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH + 50, height, rgb2mlxint(red), str);
	free(str);
	height += 30;
}

int	key_handler(int keycode, void *param)
{
	t_ctx	*ctx;

	print_keycode(keycode);
	ctx = (t_ctx *)param;
	if (keycode == XK_Escape)
	{
		close_window(param);
		return (0);
	}
	else if (keycode == '[' && ctx->max_loop > 100)
		ctx->max_loop -= 10;
	else if (keycode == ']' && ctx->max_loop < 10000)
		ctx->max_loop += 10;
	else if (keycode == XK_Left)
		ctx->win_mouse_pnt.x += 10;
	else if (keycode == XK_Up)
		ctx->win_mouse_pnt.y += 10;
	else if (keycode == XK_Right)
		ctx->win_mouse_pnt.x -= 10;
	else if (keycode == XK_Down)
		ctx->win_mouse_pnt.y -= 10;
	else if (keycode == 'p')
		ctx->mode = (ctx->mode + 1) % 2;
	else
		return (0);
	return (0);
}

int	mouse_handler(int button, int x, int y, void *param)
{
	t_ctx			*ctx;
	t_double_point	o;

	ctx = (t_ctx *)param;
	if (button == 4)
		ctx->step_n--;
	else if (button == 5)
		ctx->step_n++;
	else
		return (0);
	o = calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, ctx->step);
	ctx->mouse_pnt = (t_double_point){o.x + ctx->step * x, o.y - ctx->step * y};
	ctx->win_mouse_pnt = (t_int_point){x, y};
	ctx->step = 0.01 * pow(2, (double)ctx->step_n / 10);
	return (0);
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
	if (ctx->mode == Psyc)
		ctx->hue += 1;
	draw_mandelbrot(ctx->img_ptr,
			calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, ctx->step),
			ctx->step,
			ctx->hue,
			ctx->max_loop);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, ctx->img_ptr, 0, 0);
	put_ctx_info(ctx);
	lock = false;
	return (0);
}

int	expose_handler(void *param)
{
	printf("expose_hook is called. param = %p\n", param);
	return (0);
}

int	main(void)
{
	t_ctx	ctx;

	ctx.step_n = 0;
	ctx.step = 0.01 * pow(2, (double)ctx.step_n / 10);
	ctx.win_mouse_pnt = (t_int_point){FRACT_WIDTH / 2, FRACT_HEIGHT / 2};
	ctx.mouse_pnt = (t_double_point){0, 0};
	ctx.mlx_ptr = mlx_init();
	ctx.win_ptr = mlx_new_window(ctx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	ctx.max_loop = 50;
	ctx.img_ptr = mlx_new_image(ctx.mlx_ptr, FRACT_WIDTH, FRACT_HEIGHT);
	ctx.mode = Normal;
	put_ctx_info(&ctx);
	mlx_expose_hook(ctx.win_ptr, expose_handler, &ctx);
	mlx_key_hook(ctx.win_ptr, key_handler, &ctx);
	mlx_mouse_hook(ctx.win_ptr, mouse_handler, &ctx);
	mlx_loop_hook(ctx.mlx_ptr, loop_handler, &ctx);
	//mlx_hook(ctx.win_ptr, CLIENT_MESSAGE, STRUCTURE_NOTIFY_MASK, close_window, &ctx);
	mlx_hook(ctx.win_ptr, ClientMessage, StructureNotifyMask, close_window, &ctx);
	mlx_loop(ctx.mlx_ptr);
	return (0);
}
