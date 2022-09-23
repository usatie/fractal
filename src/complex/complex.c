/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:08:30 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 15:19:56 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

t_complex	complex_new(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

t_complex	cadd(t_complex lhs, t_complex rhs)
{
	t_complex	c;

	c.re = lhs.re + rhs.re;
	c.im = lhs.im + rhs.im;
	return (c);
}

t_complex	cmul(t_complex lhs, t_complex rhs)
{
	t_complex	c;

	c.re = lhs.re * rhs.re - lhs.im * rhs.im;
	c.im = lhs.re * rhs.im + lhs.im * rhs.re;
	return (c);
}
