/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:49:57 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 22:51:21 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	rect_contains(t_int_point p, t_rect rect)
{
	return (p.x >= rect.x && p.y >= rect.y
		&& p.x <= rect.width && p.y <= rect.height);
}
