/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:04:20 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 23:36:59 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>

t_complex	complex_new(double re, double im)
{
	return ((t_complex){re, im});
}

t_complex	cadd(t_complex lhs, t_complex rhs)
{
	return (complex_new(lhs.re + rhs.re, lhs.im + rhs.im));
}

t_complex	cmul(t_complex lhs, t_complex rhs)
{
	return (complex_new(lhs.re * rhs.re - lhs.im * rhs.im,
			lhs.re * rhs.im + lhs.im * rhs.re));
}
