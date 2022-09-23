/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_iteration.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:10:08 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 20:12:26 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "complex.h"
#include "draw.h"

// Returns the number of iterations needed to diverge.(for z to become infinite)
//
// Complex Iteration:
//   f(z) = z^2 + c
//
//   z1 = f(z0)
//   z2 = f(z1)
//   z3 = f(z2)
//   ...
uint32_t	complex_iteration(t_complex z, t_complex c, uint32_t max_loop)
{
	uint32_t	i;

	i = 0;
	while (i < max_loop)
	{
		z = cadd(cmul(z, z), c);
		if (isinf(z.re) || isinf(z.im))
			return (i);
		i++;
	}
	return (i);
}
