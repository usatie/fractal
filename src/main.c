/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:06:30 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 19:28:27 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "ft_error_functions.h"
#include "img.h"
#include "hooks.h"
#include "fractol_core.h"

static void	init_env(t_env *e);
static void	setup_hooks(t_env *e);

int	main(int argc, char **argv)
{
	t_env	e;

	(void)argc;
	(void)argv;
	init_env(&e);
	setup_hooks(&e);
	return (0);
}

static void	init_env(t_env *e)
{
	t_window	*w;

	e->mlx_ptr = mlx_init();
	if (e->mlx_ptr == NULL)
		err_exit("Error: mlx_init()");
	w = malloc(sizeof(t_window));
	if (w == NULL)
		err_exit("Error: malloc()");
	w->width = FRACT_WIDTH;
	w->height = FRACT_HEIGHT;
	w->title = WIN_TITLE;
	w->ptr = mlx_new_window(e->mlx_ptr, w->width, w->height, w->title);
	if (w->ptr == NULL)
		err_exit("Error: mlx_new_window()");
	e->fractal_win = w;
	e->fractal_img = init_img(e->mlx_ptr, w->width, w->height);
	if (e->fractal_img == NULL)
		err_exit("Error: init_img()");
}

static void	setup_hooks(t_env *e)
{
	mlx_keydown_hook(e->fractal_win->ptr, key_handler, e);
	//mlx_mouse_hook();
	mlx_loop_hook(e->mlx_ptr, loop_handler, e);
	mlx_closebutton_hook(e->fractal_win->ptr, close_window, e);
	//mlx_expose_hook();
	mlx_loop(e->mlx_ptr);
}
