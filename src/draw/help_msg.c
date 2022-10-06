/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:48:02 by susami            #+#    #+#             */
/*   Updated: 2022/10/06 14:43:24 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "color.h"
#include "draw.h"

#define NUM_MSG 17
#define SPACER ""

#define MSG_TITLE "[Usage]"
#define MSG_CHANGE_TYPE	"  Press [SPACE KEY] to change fractal type."
#define MSG_COLOR 		"  Press 'c' to enable/disable color rotation."
#define MSG_INCREASE_LOOP "  Press ']' to increase the number of maximum loop."
#define MSG_DECREASE_LOOP "  Press '[' to decrease the number of maximum loop."

#define MSG_LEFT 	"  Press [LEFT KEY] to move the center point to the left."
#define MSG_RIGHT 	"  Press [RIGHT KEY] to move the center point to the right."
#define MSG_UP 		"  Press [UP KEY] to move the center point to the up."
#define MSG_DOWN 	"  Press [DOWN KEY] to move the center point to the down."

#define MSG_ZOOM_IN 	"  Wheel up mouse to zoom in."
#define MSG_ZOOM_OUT 	"  Wheel down mouse to zoom out."

#define MSG_JULIA_ONLY	"[Only for Julia]"
#define MSG_JULIA 		"  Press 'j' to enable/disable fractal rotation."

void	put_help_msg_to_window(void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			h;
	char *const	msgs[NUM_MSG] = {
		MSG_TITLE,
		MSG_CHANGE_TYPE, MSG_COLOR, MSG_JULIA,
		MSG_INCREASE_LOOP, MSG_DECREASE_LOOP,
		SPACER,
		MSG_LEFT, MSG_RIGHT, MSG_UP, MSG_DOWN,
		SPACER,
		MSG_ZOOM_IN, MSG_ZOOM_OUT,
		SPACER,
		MSG_JULIA_ONLY, MSG_JULIA};

	h = 30;
	i = 0;
	while (i < NUM_MSG)
	{
		mlx_string_put(mlx_ptr, win_ptr,
			FRACT_WIDTH + 30, h, white().mlx_color, msgs[i]);
		h += 20;
		i++;
	}
}
