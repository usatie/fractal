/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:39:53 by susami            #+#    #+#             */
/*   Updated: 2022/10/04 13:42:13 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "affine.h"

/*
Apply Affine Transformation.

          ┌     ┐ ┌   ┐     ┌   ┐
f(x, y) = │ a b │ │ x │  +  │ e │  
          │ c d │ │ y │     │ f │
          └     ┘ └   ┘     └   ┘
*/
t_dpoint	affine_transform(t_dpoint v, t_affine t)
{
	t_dpoint	ret;

	ret.x = (t.a * v.x + t.b * v.y) + t.e;
	ret.y = (t.c * v.x + t.d * v.y) + t.f;
	return (ret);
}
