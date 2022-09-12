/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:27:47 by susami            #+#    #+#             */
/*   Updated: 2022/09/12 15:52:59 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_ctx.h"
#include "ft_printf.h"
#include "libft.h"
// STDERR_FILENO
#include <unistd.h>

// argparse_flag.c
t_fractal_type	parse_fractal_type(const char *arg);
int				parse_julia_param(const char *v, t_ctx *ctx);

// argparse.c
static void		parse_flags(int argc, char **argv, t_ctx *ctx);
static bool		parse_one(int *argc, char ***argv, t_ctx *ctx);
static char		*next_arg(int *argc, char ***argv);

t_ctx	argparse(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc < 2)
		usage_err();
	ft_memset(&ctx, 0, sizeof(t_ctx));
	init_ctx(&ctx);
	next_arg(&argc, &argv);
	parse_flags(argc, argv, &ctx);
	if (ctx.fractal_type == barnsley)
	{
		ctx.mouse_pnt = (t_dpoint){0.5, 5};
		ctx.step_n = 40;
	}
	ctx_on_update(&ctx);
	return (ctx);
}

void	usage_err(void)
{
	ft_dprintf(STDERR_FILENO,
		"Usage: ./fractol [options] fractal_type\n");
	ft_dprintf(STDERR_FILENO,
		"options:\n");
	ft_dprintf(STDERR_FILENO,
		"    -j <angle>      Julia set parameter. <0-359>\n");
	ft_dprintf(STDERR_FILENO,
		"fractal_type:\n");
	ft_dprintf(STDERR_FILENO,
		"    Mandelbrot\n");
	ft_dprintf(STDERR_FILENO,
		"    Julia\n");
	ft_dprintf(STDERR_FILENO,
		"    Barnsley\n");
	exit(EXIT_FAILURE);
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