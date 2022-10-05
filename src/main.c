/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:06:30 by susami            #+#    #+#             */
/*   Updated: 2022/10/06 00:02:36 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "ft_error_functions.h"
#include "libft.h"
#include "img.h"
#include "color.h"
#include "hooks.h"
#include "argparse.h"
#include "env.h"
#include "img.h"

static void	init_env(t_env *e);
static void	init_fractal(t_fractal *f, void *mlx_ptr);
static void	setup_args(t_fractal *f, int argc, char*const argv[]);
static void	setup_hooks(t_env *e);

int	main(int argc, char *const argv[])
{
	t_env	e;

	init_env(&e);
	setup_args(e.fractal, argc, argv);
	setup_hooks(&e);
	return (0);
}

static void	init_env(t_env *e)
{
	e->mlx_ptr = mlx_init();
	if (e->mlx_ptr == NULL)
		err_exit("Error: mlx_init()");
	e->fractal = malloc(sizeof(t_fractal));
	if (e->fractal == NULL)
		err_exit("Error: malloc()");
	init_fractal(e->fractal, e->mlx_ptr);
}

static void	init_fractal(t_fractal *f, void *mlx_ptr)
{
	ft_memset(f, 0, sizeof(t_fractal));
	f->win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (f->win_ptr == NULL)
		err_exit("Error: mlx_new_window()");
	f->img = init_img(mlx_ptr, FRACT_WIDTH, FRACT_HEIGHT);
	if (f->img == NULL)
		err_exit("Error: init_img()");
	f->footer_img = init_img(mlx_ptr, FOOTER_WIDTH, FOOTER_HEIGHT);
	if (f->footer_img == NULL)
		err_exit("Error: init_img()");
	fill_img(f->footer_img, FOOTER_WIDTH, FOOTER_HEIGHT, white().mlx_color);
}

static void	setup_args(t_fractal *f, int argc, char *const argv[])
{
	t_args	args;

	args = argparse(argc, argv);
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
	mlx_expose_hook(e->fractal->win_ptr, expose_handler, e);
	mlx_loop(e->mlx_ptr);
}
