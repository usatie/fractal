/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_internal2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:35:58 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 18:38:25 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug_internal.h"

void	put_hue(t_env *e)
{
	char	s[128];

	ft_sprintf(s, DEBUG_TEXT_HUE, e->fractal->hue);
	put_text_to_debug(s, e->mlx_ptr, e->debug_win_ptr);
}

void	put_color_rotation_enabled(t_env *e)
{
	char	s[128];

	if (e->fractal->color_rotation_enabled)
		ft_sprintf(s, DEBUG_TEXT_COLOR_ROTATION, "true");
	else
		ft_sprintf(s, DEBUG_TEXT_COLOR_ROTATION, "false");
	put_text_to_debug(s, e->mlx_ptr, e->debug_win_ptr);
}

void	put_julia_rotation_enabled(t_env *e)
{
	char	s[128];

	if (e->fractal->julia_rotation_enabled)
		ft_sprintf(s, DEBUG_TEXT_JULIA_ROTATION, "true");
	else
		ft_sprintf(s, DEBUG_TEXT_JULIA_ROTATION, "false");
	put_text_to_debug(s, e->mlx_ptr, e->debug_win_ptr);
}

void	put_center(t_env *e)
{
	char			s[128];
	const double	x = e->fractal->center.x;
	const double	y = e->fractal->center.y;

	ft_sprintf(s, DEBUG_TEXT_CENTER, x, y);
	put_text_to_debug(s, e->mlx_ptr, e->debug_win_ptr);
}

void	put_spacer(t_env *e)
{
	put_text_to_debug("", e->mlx_ptr, e->debug_win_ptr);
}
