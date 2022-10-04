/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:03:03 by susami            #+#    #+#             */
/*   Updated: 2022/09/26 15:03:16 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSEMAP_H
# define MOUSEMAP_H

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
