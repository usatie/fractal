/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:45:30 by susami            #+#    #+#             */
/*   Updated: 2022/06/19 23:02:21 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "fractol.h"
#include "mlx.h"
#include <keysymdef.h>

int	expose_hook(void *param)
{
	printf("expose_hook is called. param = %p\n", param);
	return (0);
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
		printf("[Esc]");
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

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hoge");
	printf("mlx: %p, win: %p\n", mlx_ptr, win_ptr);
	mlx_clear_window(mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, &key_hook, NULL);
	mlx_mouse_hook(win_ptr, mouse_hook, NULL);
	mlx_expose_hook(win_ptr, expose_hook, NULL);
	mlx_loop_hook(win_ptr, loop_hook, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
