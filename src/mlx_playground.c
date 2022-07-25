/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_playground.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:11:55 by susami            #+#    #+#             */
/*   Updated: 2022/07/24 22:41:36 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "fractol.h"
#include "mlx.h"
#include <keysymdef.h>
#include <stdlib.h>

typedef struct s_mlx_ptrs {
	void	*mlx_ptr;
	void	*win_ptr;
} t_mlx_ptrs;

typedef struct s_img_info {
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img_info;

void	draw_img_sample(void *mlx_ptr, void *win_ptr, char hue_add);

int	expose_hook(void *param)
{
	printf("expose_hook is called. param = %p\n", param);
	return (0);
}

void	close_window(void *param)
{
	t_mlx_ptrs *ptrs;

	ptrs = (t_mlx_ptrs *)param;
	mlx_key_hook(ptrs->win_ptr, NULL, &ptrs);
	mlx_mouse_hook(ptrs->win_ptr, NULL, &ptrs);
	mlx_expose_hook(ptrs->win_ptr, NULL, &ptrs);
	mlx_loop_hook(ptrs->mlx_ptr, NULL, &ptrs);
	(void)mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
	exit(0);
}

int	key_hook(int keycode, void *param)
{
	t_mlx_ptrs *ptrs;

	ptrs = (t_mlx_ptrs *)param;
	if (keycode == 'j')
		draw_img_sample(ptrs->mlx_ptr, ptrs->win_ptr, -8);
	else if (keycode == 'k')
		draw_img_sample(ptrs->mlx_ptr, ptrs->win_ptr, +8);
	else if (isprint(keycode) || keycode == XK_Tab)
		write(STDOUT_FILENO, &keycode, 1);
	else if (keycode == XK_BackSpace)
		printf("[BACK_SPACE]");
	else if (keycode == XK_Linefeed)
		printf("[LINE_FEED]");
	else if (keycode == XK_Clear)
		printf("[CLEAR]");
	else if (keycode == XK_Return)
		printf("[RETURN]");
	else if (keycode == XK_Pause)
		printf("[PAUSE]");
	else if (keycode == XK_Delete)
		printf("[DELETE]");
	else if (keycode == XK_F1)
		printf("[F1]");
	else if (keycode == XK_F2)
		printf("[F2]");
	else if (keycode == XK_F3)
		printf("[F3]");
	else if (keycode == XK_F4)
		printf("[F4]");
	else if (keycode == XK_F5)
		printf("[F5]");
	else if (keycode == XK_F6)
		printf("[F6]");
	else if (keycode == XK_F7)
		printf("[F7]");
	else if (keycode == XK_F8)
		printf("[F8]");
	else if (keycode == XK_F9)
		printf("[F9]");
	else if (keycode == XK_F10)
		printf("[F10]");
	else if (keycode == XK_F11)
		printf("[F11]");
	else if (keycode == XK_F12)
		printf("[F12]");
	else if (keycode == XK_Shift_L)
		printf("[SHIFT_L]");
	else if (keycode == XK_Shift_R)
		printf("[SHIFT_R]");
	else if (keycode == XK_Control_L)
		printf("[CTRL_L]");
	else if (keycode == XK_Left)
		printf("[←]");
	else if (keycode == XK_Up)
		printf("[↑]");
	else if (keycode == XK_Right)
		printf("[→]");
	else if (keycode == XK_Down)
		printf("[↓]");
	else if (keycode == XK_Meta_L)
		printf("[CMD_L]");
	else if (keycode == XK_Meta_R)
		printf("[CMD_R]");
	else if (keycode == XK_ISO_Group_Shift)
		printf("[Option]");
	else if (keycode == XK_Escape)
	{
		close_window(param);
		printf("[Esc]");
	}
	else
		printf("key_hook is called. keycode = %x, param = %p\n", keycode, param);
	fflush(stdout);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	printf("mouse_hook is called. button = %d, x = %d, y = %d, param = %p\n",
		button, x, y, param);
	return (0);
}

int	loop_hook(void *param)
{
	printf("loop_hook is called. param = %p\n", param);
	return (0);
}

void	pixel_out_sample(void *mlx_ptr, void *win_ptr)
{
	t_rgb	red;
	t_rgb	green;
	t_rgb	blue;

	red = (t_rgb){.r = 255};
	green = (t_rgb){.g = 255};
	blue = (t_rgb){.b = 255};
	mlx_string_put(mlx_ptr, win_ptr, 0, 50, rgb2mlxint(red), "red");
	mlx_string_put(mlx_ptr, win_ptr, 1, 51, rgb2mlxint(red), "red");
	mlx_string_put(mlx_ptr, win_ptr, 100, 50, rgb2mlxint(green), "green");
	mlx_string_put(mlx_ptr, win_ptr, 105, 55, rgb2mlxint(green), "green");
	mlx_string_put(mlx_ptr, win_ptr, 200, 50, rgb2mlxint(blue), "blue");
	mlx_string_put(mlx_ptr, win_ptr, 210, 60, rgb2mlxint(blue), "blue");
	for (int x = 0; x < 100; x++)
	{
		for (int y = 100; y < 200; y++)
		{
			red.r = (x % 256) * 2;
			green.g = (x % 256) * 2;
			blue.b = (x % 256) * 2;
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb2mlxint(red));
			mlx_pixel_put(mlx_ptr, win_ptr, x + 100, y, rgb2mlxint(green));
			mlx_pixel_put(mlx_ptr, win_ptr, x + 200, y, rgb2mlxint(blue));
		}
	}
}

void	draw_img_sample(void *mlx_ptr, void *win_ptr, char hue_add)
{
	static unsigned char	hue = 0;
	int						width;
	int						height;
	static void				*img_ptr = NULL; 
	t_img_info				img_info;
	char					*img;
	t_hsv					col;

	hue += hue_add;
	width = 200;
	height = 200;

	if (img_ptr)
		mlx_destroy_image(mlx_ptr, img_ptr);
	img_ptr = mlx_new_image(mlx_ptr, width, height);
	img = mlx_get_data_addr(img_ptr,
			&img_info.bits_per_pixel, &img_info.size_line, &img_info.endian);
	//printf("bits_per_pixel: %d, size_line: %d, endian: %d\n",
	//		img_info.bits_per_pixel, img_info.size_line, img_info.endian);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			col = (t_hsv){.h = hue, .s = x, .v = y};
			*((int *)img + height * y + x) = hsv2mlxint(col);
		}
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 300, 300);
}

void	mlx_playground(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_ptrs	ptrs;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hoge");
	ptrs.mlx_ptr = mlx_ptr;
	ptrs.win_ptr = win_ptr;
	printf("mlx: %p, win: %p\n", mlx_ptr, win_ptr);
	mlx_clear_window(mlx_ptr, win_ptr);
	pixel_out_sample(mlx_ptr, win_ptr);
	draw_img_sample(mlx_ptr, win_ptr, 0);
	//mlx_key_hook(win_ptr, &key_hook, &ptrs);
	mlx_mouse_hook(win_ptr, mouse_hook, &ptrs);
	//mlx_expose_hook(win_ptr, expose_hook, &ptrs);
	//mlx_loop_hook(mlx_ptr, loop_hook, &ptrs);
	mlx_loop(mlx_ptr);
}
