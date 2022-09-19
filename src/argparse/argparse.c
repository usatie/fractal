/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:27:47 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 21:11:47 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_error_functions.h"
#include "libft.h"
#include "argparse.h"

// argparse.c
static void		parse(int argc, char **argv, t_args *args);
static bool		parse_one(int *argc, char ***argv, t_args *args);
static char		*next_arg(int *argc, char ***argv);

t_args	argparse(int argc, char **argv)
{
	t_args	args;

	if (argc < 2)
		usage_err();
	ft_memset(&args, 0, sizeof(t_args));
	parse(argc - 1, argv + 1, &args);
	return (args);
}

void	usage_err(void)
{
	err_exit(
		"Usage: ./fractol [options] fractal_type\n"
		"options:\n"
		"    -j <angle>      Julia set parameter. <0-359>\n"
		"fractal_type:\n"
		"    Mandelbrot\n"
		"    Julia\n"
		"    Barnsley\n");
}

static void	parse(int argc, char **argv, t_args *args)
{
	while (argc > 1)
	{
		if (parse_one(&argc, &argv, args) == false)
			break ;
	}
	if (argc != 1)
		usage_err();
	args->fractal = parse_fractal_type(argv[0]);
}

// Return Value:
// 	- true on more flags to parse.
// 	- false on end of parsing.
//
// parse_one() consumes argc and argv.
// (i.e. argc--, argv+)
static bool	parse_one(int *argc, char ***argv, t_args *args)
{
	char	*s;
	char	*v;

	s = next_arg(argc, argv);
	if (ft_strcmp(s, "--") == 0)
		return (false);
	v = next_arg(argc, argv);
	if (ft_strcmp(s, "-j") == 0)
	{
		args->julia_degree = parse_julia_degree(v);
		return (true);
	}
	else
		usage_err();
}

static char	*next_arg(int *argc, char ***argv)
{
	char	*arg;

	arg = (*argv)[0];
	(*argc)--;
	(*argv)++;
	return (arg);
}
