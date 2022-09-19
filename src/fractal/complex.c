/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:04:20 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 16:10:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
