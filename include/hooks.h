/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:34:17 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 17:34:46 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

void	mlx_keydown_hook(void *win_ptr, int (*handler)(), void *param);
void	mlx_closebutton_hook(void *win_ptr, int (*handler)(), void *param);

#endif
