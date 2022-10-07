/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:20:13 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 16:52:14 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_INTERNAL_H
# define DEBUG_INTERNAL_H
# include "debug.h"

# define NUM_DEBUG_ITEM 12
# define DEBUG_TEXT_NAME        "  fractal type              : %s"

# define DEBUG_TEXT_MAX_LOOP    "  max_loop                  : %d"

# define DEBUG_TEXT_ZOOM_LEVEL  "  zoom_level                : %d"
# define DEBUG_TEXT_PIXEL_WIDTH "  pixel_width               : %.20f"
# define DEBUG_TEXT_CENTER      "  center                    : (%f, %f)"

# define DEBUG_TEXT_CR          "  color_rotation_enabled    : %s"
# define DEBUG_TEXT_HUE         "  hue                       : %d"

# define DEBUG_TEXT_JR          "  julia_rotation_enabled    : %s"

void	put_text_to_debug(char *text, void *mlx_ptr, void *win_ptr);

void	put_fractal_name(t_env *e);

void	put_max_loop(t_env *e);

void	put_zoom_level(t_env *e);
void	put_pixel_widhth(t_env *e);
void	put_center(t_env *e);

void	put_color_rotation_enabled(t_env *e);
void	put_hue(t_env *e);

void	put_julia_rotation_enabled(t_env *e);

void	put_spacer(t_env *e);
#endif
