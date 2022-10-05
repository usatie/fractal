/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:57:07 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 21:31:11 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "affine.h"

/*
Barnsley's Fern

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

Original Parameters come from this website.
https://www.chradams.co.uk/fern/maker.html
*/

const t_ifs_config			g_ifs_barnsley[4] = {
	(t_ifs_config){{
	.a = 0, .b = 0, .c = 0, .d = 0.16, .e = 0, .f = 0},
	.p = 0.01},
	(t_ifs_config){{
	.a = 0.85, .b = 0.04, .c = -0.04, .d = 0.85, .e = 0, .f = 1.60},
	.p = 0.85},
	(t_ifs_config){{
	.a = 0.20, .b = -0.26, .c = 0.23, .d = 0.22, .e = 0, .f = 1.60},
	.p = 0.07},
	(t_ifs_config){{
	.a = -0.15, .b = 0.28, .c = 0.26, .d = 0.24, .e = 0, .f = 0.44},
	.p = 0.07},
};

/*
Cyclosorus Fern

w	| a		| b		| c		| d		| e		| f		| p		|
ƒ1	| 0		| 0		| 0		| 0.25	| 0		| -0.4	| 0.02	|
ƒ2	| 0.95	| 0.005	| −0.005| 0.93	| -0.002| 0.5	| 0.84	|
ƒ3	| 0.035	| −0.2	| 0.16	| 0.04	| -0.09	| 0.02	| 0.07	|
ƒ4	| 0.04	| 0.2	| 0.16	| 0.04	| 0.083	| 0.12	| 0.07	|
*/
const t_ifs_config			g_ifs_cyclosorus[4] = {
	(t_ifs_config){{
	.a = 0, .b = 0, .c = 0, .d = 0.25, .e = 0, .f = -0.4},
	.p = 0.02},
	(t_ifs_config){{
	.a = 0.95, .b = 0.005, .c = -0.005, .d = 0.93, .e = -0.002, .f = 0.5},
	.p = 0.84},
	(t_ifs_config){{
	.a = 0.035, .b = -0.2, .c = 0.16, .d = 0.04, .e = -0.09, .f = 0.02},
	.p = 0.07},
	(t_ifs_config){{
	.a = 0.04, .b = 0.2, .c = 0.16, .d = 0.04, .e = 0.083, .f = 0.12},
	.p = 0.07},
};

/*
Fractal Tree

w	| a		| b		| c		| d		| e		| f		| p		|
ƒ1	| 0		| 0		| 0		| 0.5	| 0		| 0		| 0.05	|
ƒ2	| 0.42	| -0.42	| 0.42	| 0.42	| 0		| 0.2	| 0.4	|
ƒ3	| 0.42	| 0.42	| -0.42	| 0.42	| 0		| 0.2	| 0.4	|
ƒ4	| 0.1	| 0		| 0		| 0.1	| 0		| 0.2	| 0.15	|
*/
const t_ifs_config			g_ifs_fractal_tree[4] = {
	(t_ifs_config){{
	.a = 0, .b = 0, .c = 0, .d = 0.5, .e = 0, .f = 0},
	.p = 0.05},
	(t_ifs_config){{
	.a = 0.42, .b = -0.42, .c = 0.42, .d = 0.42, .e = 0, .f = 0.2},
	.p = 0.4},
	(t_ifs_config){{
	.a = 0.42, .b = 0.42, .c = -0.42, .d = 0.42, .e = 0, .f = 0.2},
	.p = 0.4},
	(t_ifs_config){{
	.a = 0.1, .b = 0, .c = 0, .d = 0.1, .e = 0, .f = 0.2},
	.p = 0.15},
};

/*
Golden Bee

w	| a		| b		| c		| d		| e		| f		| p		|
ƒ1	| 0.6178| 0		| 0		|-0.6178| 0		| 0		| 0.5	|
ƒ2	| 0		|-0.786	| 0.786	| 0		| 0.786	| 0		| 0.5	|
ƒ3	| 0		| 0		| 0		| 0		| 0		| 0		| 0		|
ƒ4	| 0		| 0		| 0		| 0		| 0		| 0		| 0		|
*/
const t_ifs_config			g_ifs_golden_bee[4] = {
	(t_ifs_config){{
	.a = 0.6178, .b = 0, .c = 0, .d = -0.6178, .e = 0, .f = 1},
	.p = 0.5},
	(t_ifs_config){{
	.a = 0, .b = -0.786, .c = 0.786, .d = 0, .e = 0.786, .f = 0},
	.p = 0.5},
	(t_ifs_config){{
	.a = 0, .b = 0, .c = 0, .d = 0, .e = 0, .f = 0},
	.p = 0},
	(t_ifs_config){{
	.a = 0, .b = 0, .c = 0, .d = 0, .e = 0, .f = 0},
	.p = 0},
};
