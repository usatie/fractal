/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_playground.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:11:55 by susami            #+#    #+#             */
/*   Updated: 2022/07/24 12:12:21 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "fractol.h"
#include "mlx.h"
#include <keysymdef.h>
#include <stdlib.h>

typedef struct __attribute__((packed)) s_mlx_color {
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	alpha;
}	t_mlx_color;

typedef struct s_mlx_ptrs {
	void	*mlx_ptr;
	void	*win_ptr;
} t_mlx_ptrs;

typedef struct s_img_info {
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img_info;

int	color(t_mlx_color c)
{
	return (*(int *)&c);
}

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
	if (isprint(keycode) || keycode == XK_Tab)
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
	t_mlx_color	red;
	t_mlx_color	green;
	t_mlx_color	blue;

	red = (t_mlx_color){.red = 255};
	green = (t_mlx_color){.green = 255};
	blue = (t_mlx_color){.blue = 255};
	mlx_string_put(mlx_ptr, win_ptr, 0, 50, color(red), "red");
	mlx_string_put(mlx_ptr, win_ptr, 1, 51, color(red), "red");
	mlx_string_put(mlx_ptr, win_ptr, 100, 50, color(green), "green");
	mlx_string_put(mlx_ptr, win_ptr, 105, 55, color(green), "green");
	mlx_string_put(mlx_ptr, win_ptr, 200, 50, color(blue), "blue");
	mlx_string_put(mlx_ptr, win_ptr, 210, 60, color(blue), "blue");
	for (int x = 0; x < 100; x++)
	{
		for (int y = 100; y < 200; y++)
		{
			red.red = (x % 256) * 2;
			green.green = (x % 256) * 2;
			blue.blue = (x % 256) * 2;
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color(red));
			mlx_pixel_put(mlx_ptr, win_ptr, x + 100, y, color(green));
			mlx_pixel_put(mlx_ptr, win_ptr, x + 200, y, color(blue));
		}
	}
}

void	draw_img_sample(void *mlx_ptr, void *win_ptr)
{
	int				width;
	int				height;
	void			*img_ptr; 
	t_img_info		img_info;
	char			*img;
	t_mlx_color	red;
	t_mlx_color	green;
	t_mlx_color	blue;

	red = (t_mlx_color){.red = 255};
	green = (t_mlx_color){.green = 255};
	blue = (t_mlx_color){.blue = 255};

	width = 200;
	height = 200;

	img_ptr = mlx_new_image(mlx_ptr, width, height);
	img = mlx_get_data_addr(img_ptr,
			&img_info.bits_per_pixel, &img_info.size_line, &img_info.endian);
	printf("bits_per_pixel: %d, size_line: %d, endian: %d\n",
			img_info.bits_per_pixel, img_info.size_line, img_info.endian);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if ((x + y) % 10 < 5)
				*((int *)img + height * y + x) = color(red);
			else if ((x + y) % 10 < 8)
				*((int *)img + height * y + x) = color(green);
			else
				*((int *)img + height * y + x) = color(blue);
		}
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 300, 300);
//	mlx_destroy_image(mlx_ptr, img_ptr);
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
	draw_img_sample(mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, &key_hook, &ptrs);
	mlx_mouse_hook(win_ptr, mouse_hook, &ptrs);
	mlx_expose_hook(win_ptr, expose_hook, &ptrs);
	mlx_loop_hook(mlx_ptr, loop_hook, &ptrs);
	mlx_loop(mlx_ptr);
}
