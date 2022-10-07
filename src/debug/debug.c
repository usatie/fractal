/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:20:56 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 15:50:16 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "img.h"
#include "debug_internal.h"

static void	clear_debug_window(t_env *e)
{
	mlx_put_image_to_window(
		e->mlx_ptr,
		e->debug_win_ptr,
		e->debug_img->ptr,
		0,
		0);
}

void	put_debug_text_to_window(t_env *e)
{
	clear_debug_window(e);
	put_text_to_debug("[DEBUG INFORMATION]", e->mlx_ptr, e->debug_win_ptr);
	put_fractal_name(e);
	put_max_loop(e);
	put_zoom_level(e);
	put_pixel_widhth(e);
	put_hue(e);
	put_color_rotation_enabled(e);
	put_julia_rotation_enabled(e);
	put_center(e);
}
