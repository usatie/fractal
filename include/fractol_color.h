/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:14:42 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 21:15:56 by susami           ###   ########.fr       */
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
	unsigned char	h;
	unsigned char	s;
	unsigned char	v;
	unsigned char	alpha;
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
		unsigned char	b:8;
		unsigned char	g:8;
		unsigned char	r:8;
		unsigned char	alpha:8;
	} rgb;
	int	mlxint;
}	t_rgb;

t_rgb	hsv2rgb(t_hsv in);
t_rgb	rgb(unsigned char r, unsigned char g, unsigned char b,
			unsigned char alpha);
t_rgb	green(void);
t_rgb	red(void);
t_rgb	black(void);
#endif
