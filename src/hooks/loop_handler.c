/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:05:37 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 11:04:48 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_error_functions.h"
#include "mlx.h"
#include "color.h"
#include "draw.h"
#include "env.h"
#include "hooks.h"

#define LOOP_PER_FRAME 1000
#define HUE_INCREASE_PER_FRAME 1
#define JULIA_DEGREE_INCREASE_PER_FRAME 3

static void	update_env(t_env *e);

void		put_debug_text_to_window(t_env *e);

int	loop_handler(t_env *e)
{
	static bool		lock;
	static size_t	cnt;
	const bool		skip_upadte = ((cnt % LOOP_PER_FRAME) != 0 || lock);
	bool			updated;

	cnt++;
	if (skip_upadte)
		return (0);
	lock = true;
	update_env(e);
	put_footer_text_to_window(e);
	put_debug_text_to_window(e);
	updated = draw_fractal_to_img(e->fractal);
	if (updated)
	{
		mlx_put_image_to_window(e->mlx_ptr, e->fractal->win_ptr,
			e->fractal->img->ptr, 0, 0);
	}
	lock = false;
	return (0);
}

static void	update_env(t_env *e)
{
	if (e->fractal->color_rotation_enabled)
	{
		e->fractal->hue += HUE_INCREASE_PER_FRAME;
	}
	if (e->fractal->julia_rotation_enabled)
	{
		e->fractal->julia_degree += JULIA_DEGREE_INCREASE_PER_FRAME;
		e->fractal->julia_degree %= 360;
	}
}
