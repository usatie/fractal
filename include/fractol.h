/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:00:10 by susami            #+#    #+#             */
/*   Updated: 2022/07/24 16:06:18 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define XK_MISCELLANY 1
# define XK_XKB_KEYS 1

/*
**  Complex number
*/

/*
** re — real part
** im — imaginary part
*/
typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

t_complex	complex_new(double re, double im);
t_complex	cadd(t_complex lhs, t_complex rhs);
t_complex	csub(t_complex lhs, t_complex rhs);
t_complex	cmul(t_complex lhs, t_complex rhs);
t_complex	cdiv(t_complex c, t_complex b);
char		*cstr(t_complex z);
t_complex	mandelbrot(t_complex z, t_complex c);
#endif
