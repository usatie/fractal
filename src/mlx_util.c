/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:09:07 by susami            #+#    #+#             */
/*   Updated: 2022/08/27 20:58:22 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"
#include "mlx_keymap.h"
#include <unistd.h>

void	print_keycode(int keycode)
{
	if (ft_isprint(keycode) || keycode == MK_TAB)
		write(STDOUT_FILENO, &keycode, 1);
	else if (keycode == MK_BACKSPACE)
		ft_printf("[BACK_SPACE]");
	else if (keycode == MK_LINE_FEED)
		ft_printf("[LINE_FEED]");
	else if (keycode == MK_CLEAR)
		ft_printf("[CLEAR]");
	else if (keycode == MK_RETURN)
		ft_printf("[RETURN]");
	else if (keycode == MK_PAUSE)
		ft_printf("[PAUSE]");
	else if (keycode == MK_DELETE)
		ft_printf("[DELETE]");
	else if (keycode == MK_F1)
		ft_printf("[F1]");
	else if (keycode == MK_F2)
		ft_printf("[F2]");
	else if (keycode == MK_F3)
		ft_printf("[F3]");
	else if (keycode == MK_F4)
		ft_printf("[F4]");
	else if (keycode == MK_F5)
		ft_printf("[F5]");
	else if (keycode == MK_F6)
		ft_printf("[F6]");
	else if (keycode == MK_F7)
		ft_printf("[F7]");
	else if (keycode == MK_F8)
		ft_printf("[F8]");
	else if (keycode == MK_F9)
		ft_printf("[F9]");
	else if (keycode == MK_F10)
		ft_printf("[F10]");
	else if (keycode == MK_F11)
		ft_printf("[F11]");
	else if (keycode == MK_F12)
		ft_printf("[F12]");
	else if (keycode == MK_SHIFT_L)
		ft_printf("[SHIFT_L]");
	else if (keycode == MK_SHIFT_R)
		ft_printf("[SHIFT_R]");
	else if (keycode == MK_CONTROL_L)
		ft_printf("[CTRL_L]");
	else if (keycode == MK_LEFT)
		ft_printf("[←]");
	else if (keycode == MK_UP)
		ft_printf("[↑]");
	else if (keycode == MK_RIGHT)
		ft_printf("[→]");
	else if (keycode == MK_DOWN)
		ft_printf("[↓]");
	else if (keycode == MK_CMD_L)
		ft_printf("[CMD_L]");
	else if (keycode == MK_CMD_R)
		ft_printf("[CMD_R]");
	else if (keycode == MK_OPTION)
		ft_printf("[Option]");
	else if (keycode == MK_ESCAPE)
		ft_printf("[Esc]");
	else
		ft_printf("key_hook is called. keycode = %x\n", keycode);
}
