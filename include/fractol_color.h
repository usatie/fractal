/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:14:42 by susami            #+#    #+#             */
/*   Updated: 2022/09/11 00:48:07 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COLOR_H
# define FRACTOL_COLOR_H

/*
**  HSV Color
*/

/*
** h — Hue
** s — Saturation
** v — Value
** alpha — Alpha
*/
typedef struct s_hsv {
	uint8_t	h;
	uint8_t	s;
	uint8_t	v;
	uint8_t	alpha;
}	t_hsv;

/*
**  RGB Color
*/

/*
** r — Red
** g — Green
** b — Blue
** alpha — Alpha
*/
typedef union u_rgb {
	struct s_rgb {
		uint8_t	b:8;
		uint8_t	g:8;
		uint8_t	r:8;
		uint8_t	alpha:8;
	} rgb;
	int32_t	mlxint;
}	t_rgb;

t_rgb	hsv2rgb(t_hsv in);
t_rgb	rgb(uint8_t r, uint8_t g, uint8_t b,
			uint8_t alpha);
t_rgb	green(void);
t_rgb	red(void);
t_rgb	black(void);
#endif
