/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:18:35 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 23:43:58 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "fractol.h"

char	*get_fractal_name(enum e_fractal type);
void	setup_fractal(t_fractal *f, enum e_fractal type);

#endif
