/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:06:30 by susami            #+#    #+#             */
/*   Updated: 2022/10/04 22:43:08 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "ft_error_functions.h"
#include "libft.h"
#include "img.h"
#include "hooks.h"

static void	init_env(t_env *e);
static void	init_fractal(t_fractal *f, void *mlx_ptr);
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
	f->win_ptr = mlx_new_window(mlx_ptr, FRACT_WIDTH, FRACT_HEIGHT, WIN_TITLE);
	if (f->win_ptr == NULL)
		err_exit("Error: mlx_new_window()");
	f->img = init_img(mlx_ptr, FRACT_WIDTH, FRACT_HEIGHT);
	if (f->img == NULL)
		err_exit("Error: init_img()");
	f->max_loop = 100;
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
