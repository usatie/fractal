/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_util.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:21:13 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 23:37:10 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_UTIL_H
# define FRACTOL_UTIL_H

# include <stdbool.h>

typedef struct s_complex	t_complex;
typedef struct s_ipoint		t_ipoint;
typedef struct s_dpoint		t_dpoint;
typedef struct s_rect		t_rect;

// complex.c
t_complex	complex_new(double re, double im);
t_complex	cadd(t_complex lhs, t_complex rhs);
t_complex	cmul(t_complex lhs, t_complex rhs);

// rect.c
bool		rect_contains(t_ipoint p, t_rect rect);

// double_util.c
bool		neq(double a, double b);

/*
**  Complex number
*/

/*
** re — real part
** im — imaginary part
*/
struct s_complex {
	double	re;
	double	im;
};

struct s_ipoint {
	int	x;
	int	y;
};

struct s_dpoint {
	double	x;
	double	y;
};

struct s_rect {
	int	x;
	int	y;
	int	width;
	int	height;
};

#endif
