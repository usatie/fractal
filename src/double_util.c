/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:45:16 by susami            #+#    #+#             */
/*   Updated: 2022/08/16 21:45:17 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	not_equal(double a, double b);

// To ignore -Wfloat-equal warnings
bool	not_equal(double a, double b)
{
	return (a < b || a > b);
}
