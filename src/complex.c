/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:04:20 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 11:24:00 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>
#include "ft_printf.h"

t_complex	complex_new(double re, double im)
{
	return ((t_complex){re, im});
}

t_complex	cadd(t_complex lhs, t_complex rhs)
{
	return (complex_new(lhs.re + rhs.re, lhs.im + rhs.im));
}

/*
t_complex	csub(t_complex lhs, t_complex rhs)
{
	return (complex_new(lhs.re - rhs.re, lhs.im - rhs.im));
}
*/

t_complex	cmul(t_complex lhs, t_complex rhs)
{
	return (complex_new(lhs.re * rhs.re - lhs.im * rhs.im,
			lhs.re * rhs.im + lhs.im * rhs.re));
}

/*
c.re = a.re * b.re - a.im * b.im
c.im = a.re * b.im + a.im * b.re

c / b = a

a.re = (c.re * b.re + c.im * b.im) / (b.re * b.re + b.im * b.im)
a.im = (c.re * (-b.im) + c.im * b.re ) / (b.re * b.re + b.im * b.im)
*/

/*
t_complex	cdiv(t_complex c, t_complex b)
{
	t_complex	a;

	a.re = (c.re * b.re + c.im * b.im) / (b.re * b.re + b.im * b.im);
	a.im = (c.re * (-b.im) + c.im * b.re) / (b.re * b.re + b.im * b.im);
	return (a);
}
*/
