/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:01:11 by susami            #+#    #+#             */
/*   Updated: 2022/09/27 09:47:31 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFFINE_H
# define AFFINE_H

typedef struct s_affine		t_affine;
typedef struct s_ifs_config	t_ifs_config;

void	affine_iteration(t_fractal *f, const t_ifs_config *configv);

/*
Coefficients of the Affine Transformation

          ┌     ┐ ┌   ┐     ┌   ┐
f(x, y) = │ a b │ │ x │  +  │ e │  
          │ c d │ │ y │     │ f │
          └     ┘ └   ┘     └   ┘
*/
struct s_affine {
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;
	double	f;
};

/*
Iterated Function System

Iteratively apply affine transformation `affine` on probability `p`.
*/
struct s_ifs_config {
	t_affine	affine;
	double		p;
};
#endif
