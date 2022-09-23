/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:05:37 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 18:51:02 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fractol_core.h"
#include "hooks.h"

#define LOOP_PER_FRAME 1000

static void	draw_something(t_env *e);

int	loop_handler(t_env *e)
{
	static bool		lock;
	static size_t	cnt;
	const bool		skip_upadte = ((cnt % LOOP_PER_FRAME) != 0 || lock);

	cnt++;
	if (skip_upadte)
		return (0);
	lock = true;
	draw_something(e);
	lock = false;
	return (0);
}

#include "mlx.h"
#include "img.h"

static void	draw_something(t_env *e)
{
	static bool	is_first = true;

	if (!is_first)
	{
		return ;
	}
	for (int x = 0; x < e->fractal_win->width; x++)
	{
		for (int y = 0; y < e->fractal_win->height; y++)
		{
			put_pixel(e->fractal_img, x, y, x + y);
		}
	}
	mlx_put_image_to_window(e->mlx_ptr, e->fractal_win->ptr,
		e->fractal_img->ptr, 0, 0);
	is_first = false;
}
