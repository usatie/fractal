/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:01:00 by susami            #+#    #+#             */
/*   Updated: 2022/09/27 11:01:03 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// rand()
#include <stdlib.h>
#include <math.h>
#include "ft_error_functions.h"
#include "fractol_core.h"
#include "color.h"
#include "img.h"
#include "affine.h"
#include "draw.h"

/*
Barnsley's fern uses four affine transformations. 
The formula for one transformation is the following:

          ┌     ┐ ┌   ┐     ┌   ┐
f(x, y) = │ a b │ │ x │  +  │ e │  
          │ c d │ │ y │     │ f │
          └     ┘ └   ┘     └   ┘

Barnsley shows the IFS code for his Black Spleenwort fern fractal as a matrix of
values shown in a table. In the table, the columns "a" through "f" are the
coefficients of the equation, and "p" represents the probability factor.

w	| a		| b		| c		| d		| e		| f		| p		|
ƒ1	| 0		| 0		| 0		| 0.16	| 0		| 0		| 0.01	|
ƒ2	| 0.85	| 0.04	| −0.04	| 0.85	| 0		| 1.60	| 0.85	|
ƒ3	| 0.20	| −0.26	| 0.23	| 0.22	| 0		| 1.60	| 0.07	|
ƒ4	| −0.15	| 0.28	| 0.26	| 0.24	| 0		| 0.44	| 0.07	|

w	| Portion generated
ƒ1	| Stem
ƒ2	| Successively smaller leaflets
ƒ3	| Largest left-hand leaflet
ƒ4	| Largest right-hand leaflet
*/
static const t_ifs_config	g_trans[4] = {
	(t_ifs_config){.affine = (t_affine){
	.a = 0, .b = 0, .c = 0, .d = 0.16, .e = 0, .f = 0}, .p = 0.01},
	(t_ifs_config){.affine = (t_affine){
	.a = 0.85, .b = 0.04, .c = -0.04, .d = 0.85, .e = 0, .f = 1.60}, .p = 0.85},
	(t_ifs_config){.affine = (t_affine){
	.a = 0.20, .b = -0.26, .c = 0.23, .d = 0.22, .e = 0, .f = 1.60}, .p = 0.07},
	(t_ifs_config){.affine = (t_affine){
	.a = -0.15, .b = 0.28, .c = 0.26, .d = 0.24, .e = 0, .f = 0.44}, .p = 0.07},
};

static bool		need_to_update(t_fractal *f);

bool	barnsley(t_fractal *f)
{
	if (need_to_update(f))
		clear_img(f->img, FRACT_WIDTH, FRACT_HEIGHT);
	affine_iteration(f, (const t_ifs_config *)g_trans);
	return (true);
}

static bool	need_to_update(t_fractal *f)
{
	static t_fractal	prev;
	bool				is_f_updated;

	if (f->force_update_flag)
	{
		prev = *f;
		f->force_update_flag = false;
		return (true);
	}
	is_f_updated = (
			prev.win_ptr == NULL
			|| prev.zoom_level != f->zoom_level
			|| prev.type != f->type
			);
	prev = *f;
	return (is_f_updated);
}
