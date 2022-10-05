/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:34:51 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 23:21:35 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "hooks.h"

int	expose_handler(t_env *e)
{
	e->fractal->force_update_flag = true;
	put_help_msg_to_window(e->mlx_ptr, e->fractal->win_ptr);
	return (0);
}
