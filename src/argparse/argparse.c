/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:52:56 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 21:55:28 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "ft_getopt.h"
#include "argparse.h"
#include "ft_error_functions.h"

static uint32_t			parse_julia_degree(const char *s);
static enum e_fractal	parse_fractal_type(char *arg);
static bool				is_numeric(const char *s);

t_args	argparse(int argc, char *const argv[])
{
	t_args	args;
	int		opt;

	if (argc < 2)
		usage_err();
	ft_memset(&args, 0, sizeof(t_args));
	opt = ft_getopt(argc, argv);
	while (opt != -1)
	{
		if (opt == 'd')
			args.julia_degree = parse_julia_degree(*optarg());
		else if (opt == 'c')
			args.color_rotation_enabled = true;
		else if (opt == 'j')
			args.julia_rotation_enabled = true;
		else
			usage_err();
		opt = ft_getopt(argc, argv);
	}
	if (*optind() != argc - 1)
		err_exit("g_optind: %d\n", *optind());
	args.type = parse_fractal_type(argv[*optind()]);
	return (args);
}

static enum e_fractal	parse_fractal_type(char *arg)
{
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		return (MANDELBROT);
	else if (ft_strcmp(arg, "Julia") == 0)
		return (JULIA);
	else if (ft_strcmp(arg, "Barnsley") == 0)
		return (BARNSLEY);
	else if (ft_strcmp(arg, "Cyclosorus") == 0)
		return (CYCLOSORUS);
	else if (ft_strcmp(arg, "GoldenBee") == 0)
		return (GOLDEN_BEE);
	else if (ft_strcmp(arg, "FractalTree") == 0)
		return (FRACTAL_TREE);
	else
		usage_err();
}

static uint32_t	parse_julia_degree(const char *s)
{
	long	res;
	char	*endptr;

	if (!is_numeric(s))
		usage_err();
	errno = 0;
	res = ft_strtol(s, &endptr, 10);
	if (errno != 0)
		usage_err();
	if (*endptr != '\0')
		usage_err();
	if (res < 0 || res >= 360)
		usage_err();
	return ((uint32_t)res);
}

static bool	is_numeric(const char *s)
{
	if (*s == '\0')
		return (false);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}
