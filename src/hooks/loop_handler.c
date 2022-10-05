/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:05:37 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 23:52:09 by susami           ###   ########.fr       */
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
static void	put_fractal_name_to_footer(t_env *e);

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
	if (g_prev.win_ptr == NULL || g_prev.type != e->fractal->type)
		put_fractal_name_to_footer(e);
	updated = draw_fractal_to_img(e->fractal);
	if (updated)
	{
		mlx_put_image_to_window(e->mlx_ptr, e->fractal->win_ptr,
			e->fractal->img->ptr, 0, 0);
	}
	lock = false;
	return (0);
}

// 1. Place footer img right below the fractal img.
// 2. Put string (fractal name) to the footer.
#define FOOTER_STRING_OFFSET_X 160
#define FOOTER_STRING_OFFSET_Y 20

static void	put_fractal_name_to_footer(t_env *e)
{
	int	text_color;

	text_color = blue().mlx_color;
	mlx_put_image_to_window(
		e->mlx_ptr,
		e->fractal->win_ptr,
		e->fractal->footer_img->ptr,
		0,
		FRACT_HEIGHT);
	mlx_string_put(
		e->mlx_ptr,
		e->fractal->win_ptr,
		FOOTER_STRING_OFFSET_X,
		FRACT_HEIGHT + FOOTER_STRING_OFFSET_Y,
		text_color,
		get_fractal_name(e->fractal->type));
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
