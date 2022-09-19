/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:30:27 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 21:12:43 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSE_H
# define ARGPARSE_H

typedef struct s_args {
	char	*fractal;
	int		julia_degree;
}	t_args;

// argparse.c
t_args	argparse(int argc, char **argv);
void	usage_err(void) __attribute__((noreturn));

// argparse_flag.c
char	*parse_fractal_type(char *arg);
int		parse_julia_degree(const char *s);
#endif
