/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_buttonmap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:23:12 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 16:25:27 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BUTTONMAP_H
# define MLX_BUTTONMAP_H

# if defined(LINUX)
#  define MOUSE_WHEEL_UP 5
#  define MOUSE_WHEEL_DOWN 4
# elif defined(ARM)
// if m1/m2 mac
#  define MOUSE_WHEEL_UP 4
#  define MOUSE_WHEEL_DOWN 5
# else
// if x86 mac
#  define MOUSE_WHEEL_UP 4
#  define MOUSE_WHEEL_DOWN 5
# endif
#endif
