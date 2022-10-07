/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:34:17 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 16:46:44 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "fractol.h"
// custom_hooks.c
void	mlx_keydown_hook(void *win_ptr, int (*handler)(), void *param);
void	mlx_closebutton_hook(void *win_ptr, int (*handler)(), void *param);

// loop_handler.c
int		loop_handler(t_env *e);
int		key_handler(int keycode, t_env *e);
int		mouse_handler(int button, int x, int y, t_env *e);
int		expose_handler(t_env *e);
int		debug_expose_handler(t_env *e);

// close_window.c
int		close_window(t_env *e);
#endif
