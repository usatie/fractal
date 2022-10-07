/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:06:30 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 23:43:01 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks.h"
#include "argparse.h"
#include "env.h"

static void	setup_args(t_fractal *f, t_args args);
static void	setup_hooks(t_env *e);

/*
#include <stdlib.h>

__attribute__((destructor))
static void	destructor(void) {
	system("leaks -q fractol");
}
*/

int	main(int argc, char *const argv[])
{
	t_args	args;
	t_env	e;

	args = argparse(argc, argv);
	init_env(&e);
	setup_args(e.fractal, args);
	setup_hooks(&e);
	return (0);
}

static void	setup_args(t_fractal *f, t_args args)
{
	setup_fractal(f, args.type);
	f->julia_degree = args.julia_degree;
	f->color_rotation_enabled = args.color_rotation_enabled;
	f->julia_rotation_enabled = args.julia_rotation_enabled;
}

static void	setup_hooks(t_env *e)
{
	mlx_keydown_hook(e->fractal->win_ptr, key_handler, e);
	mlx_mouse_hook(e->fractal->win_ptr, mouse_handler, e);
	mlx_loop_hook(e->mlx_ptr, loop_handler, e);
	mlx_closebutton_hook(e->fractal->win_ptr, close_window, e);
	mlx_closebutton_hook(e->debug_win_ptr, close_window, e);
	mlx_expose_hook(e->fractal->win_ptr, expose_handler, e);
	mlx_expose_hook(e->debug_win_ptr, debug_expose_handler, e);
	mlx_loop(e->mlx_ptr);
}
