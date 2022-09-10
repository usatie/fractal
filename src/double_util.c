/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:45:16 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 15:29:35 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	neq(double a, double b);

// To ignore -Wfloat-equal warnings
bool	neq(double a, double b)
{
	return (a < b || a > b);
}
