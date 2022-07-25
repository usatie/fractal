/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:45:30 by susami            #+#    #+#             */
/*   Updated: 2022/07/25 17:31:46 by susami           ###   ########.fr       */
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

#define WIN_WIDTH 500
#define WIN_HEIGHT 300
#define WIN_TITLE "fract-ol"

#define FRACT_WIDTH 300
#define FRACT_HEIGHT 300

#define HELP_WIDTH 200
#define HELP_HEIGHT 300

void			mlx_playground(void);
void			math_playground(void);

t_double_point	calc_origin(t_int_point win_mouse_pnt,
					t_double_point mouse_pnt, double step);
void			close_window(void *param);

t_double_point	calc_origin(t_int_point win_mouse_pnt,
		t_double_point mouse_pnt, double step)
{
	double	x;
	double	y;

	x = mouse_pnt.x - step * win_mouse_pnt.x;
	y = mouse_pnt.y + step * win_mouse_pnt.y;
	return ((t_double_point){x, y});
}

void	close_window(void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)param;
	mlx_key_hook(ctx->win_ptr, NULL, NULL);
	mlx_mouse_hook(ctx->win_ptr, NULL, NULL);
	mlx_expose_hook(ctx->win_ptr, NULL, NULL);
	mlx_loop_hook(ctx->mlx_ptr, NULL, NULL);
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

void	*get_fractal_img(void *mlx_ptr, t_double_point o,
				double step, unsigned char hue, int max_loop)
{
	int						x;
	int						y;
	int						speed;
	t_hsv					hsv;
	void					*img_ptr;
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
	img_ptr = mlx_new_image(mlx_ptr, FRACT_WIDTH, FRACT_HEIGHT);
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
			hsv = (t_hsv){(hue + speed) % 360, 255, 150, 0};
			*((int *)img + FRACT_HEIGHT * y + x) = hsv2mlxint(hsv);
		}
	}
	return (img_ptr);
}

void	put_ctx_info(t_ctx *ctx)
{
	t_rgb			red;
	char			*str;
	static t_ctx	prev_ctx;
	bool			is_updated;

	is_updated = (prev_ctx.step != ctx->step)
		|| (prev_ctx.max_loop != ctx->max_loop);
	prev_ctx = *ctx;
	if (!is_updated)
		return ;
	red = (t_rgb){.r = 255};
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH, 50, rgb2mlxint(red), "This is sample help message->");
	asprintf(&str, "max_loop: %d", ctx->max_loop);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, FRACT_WIDTH, 100, rgb2mlxint(red), str);
	free(str);
}

void	print_keycode(int keycode)
{
	if (ft_isprint(keycode) || keycode == XK_Tab)
		write(STDOUT_FILENO, &keycode, 1);
	else if (keycode == XK_BackSpace)
		ft_printf("[BACK_SPACE]");
	else if (keycode == XK_Linefeed)
		ft_printf("[LINE_FEED]");
	else if (keycode == XK_Clear)
		ft_printf("[CLEAR]");
	else if (keycode == XK_Return)
		ft_printf("[RETURN]");
	else if (keycode == XK_Pause)
		ft_printf("[PAUSE]");
	else if (keycode == XK_Delete)
		ft_printf("[DELETE]");
	else if (keycode == XK_F1)
		ft_printf("[F1]");
	else if (keycode == XK_F2)
		ft_printf("[F2]");
	else if (keycode == XK_F3)
		ft_printf("[F3]");
	else if (keycode == XK_F4)
		ft_printf("[F4]");
	else if (keycode == XK_F5)
		ft_printf("[F5]");
	else if (keycode == XK_F6)
		ft_printf("[F6]");
	else if (keycode == XK_F7)
		ft_printf("[F7]");
	else if (keycode == XK_F8)
		ft_printf("[F8]");
	else if (keycode == XK_F9)
		ft_printf("[F9]");
	else if (keycode == XK_F10)
		ft_printf("[F10]");
	else if (keycode == XK_F11)
		ft_printf("[F11]");
	else if (keycode == XK_F12)
		ft_printf("[F12]");
	else if (keycode == XK_Shift_L)
		ft_printf("[SHIFT_L]");
	else if (keycode == XK_Shift_R)
		ft_printf("[SHIFT_R]");
	else if (keycode == XK_Control_L)
		ft_printf("[CTRL_L]");
	else if (keycode == XK_Left)
		ft_printf("[←]");
	else if (keycode == XK_Up)
		ft_printf("[↑]");
	else if (keycode == XK_Right)
		ft_printf("[→]");
	else if (keycode == XK_Down)
		ft_printf("[↓]");
	else if (keycode == XK_Meta_L)
		ft_printf("[CMD_L]");
	else if (keycode == XK_Meta_R)
		ft_printf("[CMD_R]");
	else if (keycode == XK_ISO_Group_Shift)
		ft_printf("[Option]");
	else if (keycode == XK_Escape)
		ft_printf("[Esc]");
	else
		ft_printf("key_hook is called. keycode = %x\n", keycode);
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
	else if (keycode == ']' && ctx->max_loop < 1000)
		ctx->max_loop += 10;
	else if (keycode == XK_Left)
		ctx->win_mouse_pnt.x += 10;
	else if (keycode == XK_Up)
		ctx->win_mouse_pnt.y += 10;
	else if (keycode == XK_Right)
		ctx->win_mouse_pnt.x -= 10;
	else if (keycode == XK_Down)
		ctx->win_mouse_pnt.y -= 10;
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
	ctx->hue += 1;
	if (ctx->img_ptr != NULL)
		mlx_destroy_image(ctx->mlx_ptr, ctx->img_ptr);
	ctx->img_ptr = get_fractal_img(ctx->mlx_ptr,
			calc_origin(ctx->win_mouse_pnt, ctx->mouse_pnt, ctx->step),
			ctx->step,
			ctx->hue,
			ctx->max_loop);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, ctx->img_ptr, 0, 0);
	mlx_string_put(ctx->mlx_ptr, ctx->img_ptr, 0, 50, 0, "This is sample help message");
	//put_ctx_info(ctx);
	lock = false;
	return (0);
}

int	main(void)
{
	t_ctx	ctx;

	ft_printf(" %-9p %-10p ", (void *)10, (void *)999);
	ctx.step_n = 0;
	ctx.step = 0.01 * pow(2, (double)ctx.step_n / 10);
	ctx.win_mouse_pnt = (t_int_point){FRACT_WIDTH / 2, FRACT_HEIGHT / 2};
	ctx.mouse_pnt = (t_double_point){0, 0};
	ctx.mlx_ptr = mlx_init();
	ctx.win_ptr = mlx_new_window(ctx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	ctx.max_loop = 50;
	ctx.img_ptr = NULL;
	/*
	put_ctx_info(&ctx);
	ctx.img_ptr = get_fractal_img(ctx.mlx_ptr,
			calc_origin(ctx.win_mouse_pnt, ctx.mouse_pnt, ctx.step),
			ctx.step,
			ctx.hue,
			ctx.max_loop);
	mlx_put_image_to_window(ctx.mlx_ptr, ctx.win_ptr, ctx.img_ptr, 0, 0);
	*/
	mlx_key_hook(ctx.win_ptr, key_handler, &ctx);
	mlx_mouse_hook(ctx.win_ptr, mouse_handler, &ctx);
	mlx_loop_hook(ctx.mlx_ptr, loop_handler, &ctx);
	mlx_loop(ctx.mlx_ptr);
	return (0);
}
