/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:01:00 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 21:06:12 by susami           ###   ########.fr       */
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
	bool				updated;
	const t_ifs_config	*config;

	updated = false;
	if (need_to_update(f))
	{
		ft_memset(f->speeds, 0, sizeof(t_speeds));
		clear_img(f->img, FRACT_WIDTH, FRACT_HEIGHT);
		updated = true;
	}
	if (f->type == BARNSLEY)
		config = (const t_ifs_config *)g_ifs_barnsley;
	else if (f->type == CYCLOSORUS)
		config = (const t_ifs_config *)g_ifs_cyclosorus;
	else if (f->type == FRACTAL_TREE)
		config = (const t_ifs_config *)g_ifs_fractal_tree;
	else if (f->type == GOLDEN_BEE)
		config = (const t_ifs_config *)g_ifs_golden_bee;
	updated |= affine_iteration(f, config);
	put_speeds_to_img(f);
	return (updated);
}

static bool	need_to_update(t_fractal *f)
{
	bool	is_f_updated;

	if (f->force_update_flag)
	{
		f->force_update_flag = false;
		return (true);
	}
	is_f_updated = (
			g_prev.win_ptr == NULL
			|| g_prev.zoom_level != f->zoom_level
			|| g_prev.type != f->type
			);
	return (is_f_updated);
}
