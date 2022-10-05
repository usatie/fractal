/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:20:57 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 23:59:28 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef struct s_hsv	t_hsv;
typedef union u_rgb		t_rgb;

t_rgb	hsv2rgb(t_hsv in);
t_rgb	rgb(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha);

t_rgb	red(void);
t_rgb	green(void);
t_rgb	blue(void);
t_rgb	black(void);
t_rgb	white(void);

/*
   HSV Color
   h — Hue
   s — Saturation
   v — Value
   alpha — Alpha
*/
struct s_hsv {
	uint8_t	h;
	uint8_t	s;
	uint8_t	v;
	uint8_t	alpha;
};

/*
** r — Red
** g — Green
** b — Blue
** alpha — Alpha
*/
struct s_rgb {
	uint8_t	b:8;
	uint8_t	g:8;
	uint8_t	r:8;
	uint8_t	alpha:8;
};

union u_rgb {
	struct s_rgb	rgb;
	int32_t			mlx_color;
};

#endif
