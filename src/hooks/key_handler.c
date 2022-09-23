/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:09 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 19:30:19 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_core.h"
#include "keymap.h"
#include "hooks.h"

int	key_handler(int keycode, t_env *e)
{
	if (keycode == MK_ESCAPE)
		close_window(e);
	return (0);
}
