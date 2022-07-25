/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:09:07 by susami            #+#    #+#             */
/*   Updated: 2022/07/25 18:10:09 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <unistd.h>
#include "mlx.h"
#include <keysymdef.h>
#include "ft_printf.h"

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
