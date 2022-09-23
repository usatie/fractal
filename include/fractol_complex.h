/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_complex.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:09:13 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 15:15:16 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COMPLEX_H
# define FRACTOL_COMPLEX_H

# include "fractol_core.h"

// complex.c
t_complex	complex_new(double re, double im);
t_complex	cadd(t_complex lhs, t_complex rhs);
t_complex	cmul(t_complex lhs, t_complex rhs);

#endif
