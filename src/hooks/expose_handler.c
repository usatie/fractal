/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:34:51 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 11:20:50 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "hooks.h"

void	put_debug_text_to_window(t_env *e);

int	expose_handler(t_env *e)
{
	e->fractal->force_update_flag = true;
	put_help_text_to_window(e->mlx_ptr, e->fractal->win_ptr);
	return (0);
}

int	debug_expose_handler(t_env *e)
{
	put_debug_text_to_window(e);
	return (0);
}
