/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:01:00 by susami            #+#    #+#             */
/*   Updated: 2022/10/08 07:52:33 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "draw.h"
#include "img.h"
#include "color.h"
#include "affine.h"
#include "ft_error_functions.h"

static const t_ifs_config	*get_config(enum e_fractal type);
static bool					need_to_update(t_fractal *f);

// Returns true if img is updated
// Once there is a time iteration makes no change to img, iteration stops.
bool	barnsley(t_fractal *f)
{
	static bool	need_iteration = true;

	if (need_to_update(f))
	{
		ft_memset(f->speeds, 0, sizeof(t_speeds));
		fill_img(f->img, FRACT_WIDTH, FRACT_HEIGHT, black().mlx_color);
		need_iteration = true;
	}
	if (need_iteration)
	{
		if (affine_iteration(f, get_config(f->type)))
			put_speeds_to_img(f);
		else
			need_iteration = false;
		return (need_iteration);
	}
	else if (f->color_rotation_enabled)
	{
		put_speeds_to_img(f);
		return (true);
	}
	else
		return (false);
}

static const t_ifs_config	*get_config(enum e_fractal type)
{
	const t_ifs_config	*config;

	if (type == BARNSLEY)
		config = (const t_ifs_config *)g_ifs_barnsley;
	else if (type == CYCLOSORUS)
		config = (const t_ifs_config *)g_ifs_cyclosorus;
	else if (type == FRACTAL_TREE)
		config = (const t_ifs_config *)g_ifs_fractal_tree;
	else if (type == GOLDEN_BEE)
		config = (const t_ifs_config *)g_ifs_golden_bee;
	else
		err_exit("Unexpected fractal type are passed to get_config.\n");
	return (config);
}

static bool	need_to_update(t_fractal *f)
{
	bool			is_f_updated;
	const t_fractal	*prev = previous_fractal();

	if (f->force_update_flag)
	{
		f->force_update_flag = false;
		return (true);
	}
	is_f_updated = (
			prev->win_ptr == NULL
			|| prev->max_loop != f->max_loop
			|| prev->zoom_level != f->zoom_level
			|| prev->type != f->type
			);
	return (is_f_updated);
}
