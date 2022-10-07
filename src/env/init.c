/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:52:05 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 00:04:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "ft_error_functions.h"
#include "libft.h"
#include "img.h"
#include "color.h"
#include "env.h"

static void	init_fractal(t_fractal *f, void *mlx_ptr);
static void	init_debug(t_env *e, void *mlx_ptr);

void	init_env(t_env *e)
{
	e->mlx_ptr = mlx_init();
	if (e->mlx_ptr == NULL)
		err_exit("Error: mlx_init()");
	e->fractal = malloc(sizeof(t_fractal));
	if (e->fractal == NULL)
		err_exit("Error: malloc()");
	init_debug(e, e->mlx_ptr);
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

static void	init_debug(t_env *e, void *mlx_ptr)
{
	int	color;

	e->debug_win_ptr = mlx_new_window(mlx_ptr, DEBUG_WIN_W, DEBUG_WIN_H,
			DEBUG_WIN_TITLE);
	if (e->debug_win_ptr == NULL)
		err_exit("Error: mlx_new_window()");
	e->debug_img = init_img(mlx_ptr, DEBUG_WIN_W, DEBUG_WIN_H);
	if (e->debug_img == NULL)
		err_exit("Error: init_img()");
	color = rgb(30, 30, 30, 0).mlx_color;
	fill_img(e->debug_img, DEBUG_WIN_W, DEBUG_WIN_H, color);
}
