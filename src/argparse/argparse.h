/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:48:10 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 15:23:50 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSE_H
# define ARGPARSE_H

# include "fractol.h"

typedef struct s_args {
	enum e_fractal	type;

	bool			color_rotation_enabled;

	uint32_t		julia_degree;
	bool			julia_rotation_enabled;
}	t_args;

t_args	argparse(int argc, char *const argv[]);
void	usage_err(void) __attribute__((noreturn));
#endif
