/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:05:37 by susami            #+#    #+#             */
/*   Updated: 2022/09/23 22:37:50 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "mlx.h"
#include "fractol_core.h"
#include "hooks.h"
#include "draw.h"

#define LOOP_PER_FRAME 1000

int	loop_handler(t_env *e)
{
	static bool		lock;
	static size_t	cnt;
	const bool		skip_upadte = ((cnt % LOOP_PER_FRAME) != 0 || lock);
	bool			updated;

	cnt++;
	if (skip_upadte)
		return (0);
	lock = true;
	updated = draw_fractal_to_img(e->fractal);
	if (updated)
	{
		mlx_put_image_to_window(e->mlx_ptr, e->fractal->win_ptr,
			e->fractal->img->ptr, 0, 0);
	}
	lock = false;
	return (0);
}
