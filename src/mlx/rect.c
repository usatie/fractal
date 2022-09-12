/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:49:57 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 22:47:22 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	rect_contains(t_ipoint p, t_rect rect)
{
	return (p.x >= rect.x && p.y >= rect.y
		&& p.x <= rect.width && p.y <= rect.height);
}
