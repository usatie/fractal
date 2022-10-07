/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_internal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:23:09 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 18:45:19 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "img.h"
#include "color.h"
#include "env.h"
#include "draw.h"
#include "debug_internal.h"

int	g_debug_print_index = 0;

// Put debug text to debug window
void	put_text_to_debug(char *text, void *mlx_ptr, void *win_ptr)
{
	const int	w = 30;
	const int	h = 30 + 20 * g_debug_print_index;

	if (*text)
	{
		mlx_string_put(mlx_ptr, win_ptr, w, h, white().mlx_color, text);
	}
	g_debug_print_index++;
}

void	put_fractal_name(t_env *e)
{
	char	s[128];

	ft_sprintf(s, DEBUG_TEXT_NAME, get_fractal_name(e->fractal->type));
	put_text_to_debug(s, e->mlx_ptr, e->debug_win_ptr);
}

void	put_max_loop(t_env *e)
{
	char	s[128];

	ft_sprintf(s, DEBUG_TEXT_MAX_LOOP, e->fractal->max_loop);
	put_text_to_debug(s, e->mlx_ptr, e->debug_win_ptr);
}

void	put_zoom_level(t_env *e)
{
	char	s[128];

	ft_sprintf(s, DEBUG_TEXT_ZOOM_LEVEL, e->fractal->zoom_level);
	put_text_to_debug(s, e->mlx_ptr, e->debug_win_ptr);
}

void	put_pixel_widhth(t_env *e)
{
	char			s[128];
	const double	width = pixel_width(e->fractal->zoom_level);

	ft_sprintf(s, DEBUG_TEXT_PIXEL_WIDTH, width);
	put_text_to_debug(s, e->mlx_ptr, e->debug_win_ptr);
}
