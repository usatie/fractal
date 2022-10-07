/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_internal3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:36:02 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 18:39:07 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug_internal.h"

void	put_julia_degree(t_env *e)
{
	char	s[128];

	ft_sprintf(s, DEBUG_TEXT_JULIA_DEGREE, e->fractal->julia_degree);
	put_text_to_debug(s, e->mlx_ptr, e->debug_win_ptr);
}
