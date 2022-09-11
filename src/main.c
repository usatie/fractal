/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:45:30 by susami            #+#    #+#             */
/*   Updated: 2022/09/11 16:59:52 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <X11/X.h>

#include <libc.h>

/*
__attribute__((destructor))
static void	destructor(void) {
	system("leaks -q fractol");
}
*/

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	ctx = argparse(argc, argv);
	ctx.mlx_ptr = mlx_init();
	ctx.win_ptr = mlx_new_window(ctx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	init_img(&ctx.fractal_img, ctx.mlx_ptr, FRACT_WIDTH, FRACT_HEIGHT);
	init_img(&ctx.config_clear_img, ctx.mlx_ptr, CONFIG_WIDTH, CONFIG_HEIGHT);
	clear_img_rect(&ctx.config_clear_img, g_rect_config);
	mlx_do_key_autorepeaton(ctx.mlx_ptr);
	mlx_hook(ctx.win_ptr, KeyPress, KeyPressMask, key_handler, &ctx);
	mlx_mouse_hook(ctx.win_ptr, mouse_handler, &ctx);
	mlx_loop_hook(ctx.mlx_ptr, loop_handler, &ctx);
	mlx_hook(ctx.win_ptr, ClientMessage, StructureNotifyMask,
		close_window, &ctx);
	mlx_loop(ctx.mlx_ptr);
	return (0);
}

int	close_window(t_ctx *ctx)
{
	mlx_key_hook(ctx->win_ptr, NULL, NULL);
	mlx_mouse_hook(ctx->win_ptr, NULL, NULL);
	mlx_expose_hook(ctx->win_ptr, NULL, NULL);
	mlx_loop_hook(ctx->mlx_ptr, NULL, NULL);
	mlx_destroy_image(ctx->mlx_ptr, ctx->fractal_img.img_ptr);
	mlx_destroy_image(ctx->mlx_ptr, ctx->config_clear_img.img_ptr);
	mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
	free(ctx->mlx_ptr);
	exit(0);
}
