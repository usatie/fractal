/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   footer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:55:15 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 11:05:04 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "color.h"
#include "draw.h"

#define FOOTER_STRING_OFFSET_X 160
#define FOOTER_STRING_OFFSET_Y 20

static void	put_fractal_name_to_footer(t_env *e);

void	put_footer_text_to_window(t_env *e)
{
	const bool	is_first_time = (g_prev.win_ptr == NULL);
	const bool	is_type_changed = (g_prev.type != e->fractal->type);

	if (is_first_time || is_type_changed || e->fractal->force_update_flag)
		put_fractal_name_to_footer(e);
}

// 1. Place footer img right below the fractal img.
// 2. Put string (fractal name) to the footer.
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
