/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:14:45 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 18:52:06 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "mlx.h"
#include "hooks.h"

// This hook is triggered by key DOWN, not by key UP.
void	mlx_keydown_hook(void *win_ptr, int (*handler)(), void *param)
{
	mlx_hook(win_ptr, KeyPress, KeyPressMask, handler, param);
}

// This hook is triggered by pressing window's x button.
void	mlx_closebutton_hook(void *win_ptr, int (*handler)(), void *param)
{
	mlx_hook(win_ptr, ClientMessage, StructureNotifyMask, handler, param);
}
