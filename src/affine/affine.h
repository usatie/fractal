/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:01:11 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 16:40:29 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFFINE_H
# define AFFINE_H

# include "fractol.h"

typedef struct s_affine		t_affine;
typedef struct s_ifs_config	t_ifs_config;

t_dpoint	affine_transform(t_dpoint v, t_affine t);
bool		affine_iteration(t_fractal *f, const t_ifs_config *configv);

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

extern const t_ifs_config	g_ifs_barnsley[4];
extern const t_ifs_config	g_ifs_cyclosorus[4];
extern const t_ifs_config	g_ifs_fractal_tree[4];
extern const t_ifs_config	g_ifs_golden_bee[4];

#endif
