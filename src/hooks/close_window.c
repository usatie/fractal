/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:21:49 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 16:46:35 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "hooks.h"

static void	close_debug_window(t_env *e);

/*
 * Disable hooks before destroy, to avoid calling hooks
 * after some images/windows/displays are destroyed.
*/
int	close_window(t_env *e)
{
	close_debug_window(e);
	mlx_keydown_hook(e->fractal->win_ptr, NULL, NULL);
	mlx_mouse_hook(e->fractal->win_ptr, NULL, NULL);
	mlx_expose_hook(e->fractal->win_ptr, NULL, NULL);
	mlx_closebutton_hook(e->fractal->win_ptr, NULL, NULL);
	mlx_loop_hook(e->mlx_ptr, NULL, NULL);
	mlx_destroy_image(e->mlx_ptr, e->fractal->img->ptr);
	mlx_destroy_image(e->mlx_ptr, e->fractal->footer_img->ptr);
	mlx_destroy_window(e->mlx_ptr, e->fractal->win_ptr);
	mlx_destroy_display(e->mlx_ptr);
	free(e->fractal->img);
	free(e->fractal->footer_img);
	free(e->fractal);
	exit(0);
}

static void	close_debug_window(t_env *e)
{
	mlx_mouse_hook(e->debug_win_ptr, NULL, NULL);
	mlx_expose_hook(e->debug_win_ptr, NULL, NULL);
	mlx_closebutton_hook(e->debug_win_ptr, NULL, NULL);
	mlx_destroy_image(e->mlx_ptr, e->debug_img->ptr);
	mlx_destroy_window(e->mlx_ptr, e->debug_win_ptr);
	free(e->debug_img);
}
