/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:20:13 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 18:45:25 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_INTERNAL_H
# define DEBUG_INTERNAL_H
# include "debug.h"

# define DEBUG_TEXT_NAME             "  fractal type              : %s"

# define DEBUG_TEXT_MAX_LOOP         "  max_loop                  : %d"

# define DEBUG_TEXT_ZOOM_LEVEL       "  zoom_level                : %d"
# define DEBUG_TEXT_PIXEL_WIDTH      "  pixel_width               : %.20f"
# define DEBUG_TEXT_CENTER           "  center                    : (%f, %f)"

# define DEBUG_TEXT_COLOR_ROTATION   "  color_rotation_enabled    : %s"
# define DEBUG_TEXT_HUE              "  hue                       : %d"

# define DEBUG_TEXT_JULIA_ROTATION   "  julia_rotation_enabled    : %s"
# define DEBUG_TEXT_JULIA_DEGREE     "  julia_degree              : %d"

extern int	g_debug_print_index;

// debug_internal.c
// debug_internal2.c
void	put_text_to_debug(char *text, void *mlx_ptr, void *win_ptr);

void	put_fractal_name(t_env *e);

void	put_max_loop(t_env *e);

void	put_zoom_level(t_env *e);
void	put_pixel_widhth(t_env *e);
void	put_center(t_env *e);

void	put_color_rotation_enabled(t_env *e);
void	put_hue(t_env *e);

void	put_julia_rotation_enabled(t_env *e);
void	put_julia_degree(t_env *e);

void	put_spacer(t_env *e);
#endif
