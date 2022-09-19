/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:27:47 by susami            #+#    #+#             */
/*   Updated: 2022/09/19 14:36:08 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include "ft_error_functions.h"
#include "libft.h"

// argparse_flag.c
t_fractal_type	parse_fractal_type(const char *arg);
int				parse_julia_param(const char *v, t_ctx *ctx);

// argparse.c
static void		parse_flags(int argc, char **argv, t_ctx *ctx);
static bool		parse_one(int *argc, char ***argv, t_ctx *ctx);
static char		*next_arg(int *argc, char ***argv);

// (0.5, 5.0) should be center for Barnsley
t_ctx	argparse(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc < 2)
		usage_err();
	ft_memset(&ctx, 0, sizeof(t_ctx));
	init_ctx(&ctx);
	next_arg(&argc, &argv);
	parse_flags(argc, argv, &ctx);
	if (ctx.fractal_type == BARNSLEY)
	{
		ctx.zoom_level = 40;
		ctx.center = (t_dpoint){0.5, 5.0};
	}
	return (ctx);
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

static void	parse_flags(int argc, char **argv, t_ctx *ctx)
{
	while (argc > 1)
	{
		if (parse_one(&argc, &argv, ctx) == false)
			break ;
	}
	if (argc != 1)
		usage_err();
	ctx->fractal_type = parse_fractal_type(argv[0]);
}

// Return Value:
// 	- true on more flags to parse.
// 	- false on end of parsing.
//
// parse_one() consumes argc and argv.
// (i.e. argc--, argv+)
static bool	parse_one(int *argc, char ***argv, t_ctx *ctx)
{
	char	*s;
	char	*v;

	s = next_arg(argc, argv);
	if (ft_strcmp(s, "--") == 0)
		return (false);
	v = next_arg(argc, argv);
	if (ft_strcmp(s, "-j") == 0)
	{
		parse_julia_param(v, ctx);
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
