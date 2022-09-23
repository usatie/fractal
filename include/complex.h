/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:09:13 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 15:23:07 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex	t_complex;

// complex.c
t_complex	complex_new(double re, double im);
t_complex	cadd(t_complex lhs, t_complex rhs);
t_complex	cmul(t_complex lhs, t_complex rhs);

/*
   Complex number
   re — real part
   im — imaginary part
*/
struct s_complex {
	double	re;
	double	im;
};

#endif
