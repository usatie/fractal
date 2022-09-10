/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:45:30 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 22:26:56 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <X11/X.h>

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	ctx = argparse(argc, argv);
	ctx.mlx_ptr = mlx_init();
	ctx.win_ptr = mlx_new_window(ctx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	init_img(&ctx.fractal_img, ctx.mlx_ptr, FRACT_WIDTH, FRACT_HEIGHT);
	init_img(&ctx.config_img, ctx.mlx_ptr, CONFIG_WIDTH, CONFIG_HEIGHT);
	mlx_do_key_autorepeaton(ctx.mlx_ptr);
	mlx_hook(ctx.win_ptr, KeyPress, KeyPressMask, key_handler, &ctx);
	mlx_mouse_hook(ctx.win_ptr, mouse_handler, &ctx);
	mlx_loop_hook(ctx.mlx_ptr, loop_handler, &ctx);
	mlx_hook(ctx.win_ptr, ClientMessage, StructureNotifyMask,
		close_window, &ctx);
	mlx_loop(ctx.mlx_ptr);
	return (0);
}
