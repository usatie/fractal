/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:01:00 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 17:12:53 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "draw.h"
#include "img.h"
#include "affine.h"

static bool		need_to_update(t_fractal *f);

bool	barnsley(t_fractal *f)
{
	bool	updated;

	updated = false;
	if (need_to_update(f))
	{
		ft_memset(f->speeds, 0, sizeof(t_speeds));
		clear_img(f->img, FRACT_WIDTH, FRACT_HEIGHT);
		updated = true;
	}
	updated |= affine_iteration(f, (const t_ifs_config *)&g_ifs_barnsley[0]);
	put_speeds_to_img(f);
	return (updated);
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
