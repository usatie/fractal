/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instant_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:48:38 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 23:59:07 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_rgb	red(void)
{
	return (rgb(255, 0, 0, 0));
}

t_rgb	green(void)
{
	return (rgb(0, 255, 0, 0));
}

t_rgb	blue(void)
{
	return (rgb(0, 0, 255, 0));
}

t_rgb	black(void)
{
	return (rgb(0, 0, 0, 0));
}

t_rgb	white(void)
{
	return (rgb(255, 255, 255, 255));
}
