/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:45:30 by susami            #+#    #+#             */
/*   Updated: 2022/09/15 14:09:52 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <X11/X.h>

/*
#include <stdlib.h>

__attribute__((destructor))
static void	destructor(void) {
	system("leaks -q fractol");
}
*/

static void	init_mlx_ptrs(t_ctx *ctx);
static void	setup_mlx_hooks(t_ctx *ctx);

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	ctx = argparse(argc, argv);
	init_mlx_ptrs(&ctx);
	setup_mlx_hooks(&ctx);
	return (0);
}

static void	init_mlx_ptrs(t_ctx *ctx)
{
	ctx->mlx_ptr = mlx_init();
	ctx->win_ptr = mlx_new_window(ctx->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, WIN_TITLE);
	init_img(&ctx->fractal_img, ctx->mlx_ptr, FRACT_WIDTH, FRACT_HEIGHT);
	init_img(&ctx->config_clear_img, ctx->mlx_ptr, CONFIG_WIDTH, CONFIG_HEIGHT);
	clear_img_rect(&ctx->config_clear_img, g_rect_config);
}

/*
    1. mlx_do_key_autorepeaton() & mlx_hook(_, KeyPress, KeyPressMask, _, _)
       This is for key press and long key press.
	2. mlx_mouse_hook()
	   This is for mouse move. (for zoom in/out)
	3. mlx_loop_hook()
	   This is for main event loop. (for drawing fractals etc.)
	4. mlx_hook(_, ClientMessage, StructureNotifyMask, _, _)
	   This is for closing window when X button is pressed.
*/
static void	setup_mlx_hooks(t_ctx *ctx)
{
	mlx_do_key_autorepeaton(ctx->mlx_ptr);
	mlx_hook(ctx->win_ptr, KeyPress, KeyPressMask, key_handler, ctx);
	mlx_mouse_hook(ctx->win_ptr, mouse_handler, ctx);
	mlx_loop_hook(ctx->mlx_ptr, loop_handler, ctx);
	mlx_hook(ctx->win_ptr, ClientMessage, StructureNotifyMask,
		close_window, ctx);
	mlx_loop(ctx->mlx_ptr);
}

/*
 * Disable hooks before destroy, to avoid calling hooks
 * after some images/windows/displays are destroyed.
*/
int	close_window(t_ctx *ctx)
{
	mlx_key_hook(ctx->win_ptr, NULL, NULL);
	mlx_mouse_hook(ctx->win_ptr, NULL, NULL);
	mlx_expose_hook(ctx->win_ptr, NULL, NULL);
	mlx_loop_hook(ctx->mlx_ptr, NULL, NULL);
	mlx_destroy_image(ctx->mlx_ptr, ctx->fractal_img.img_ptr);
	mlx_destroy_image(ctx->mlx_ptr, ctx->config_clear_img.img_ptr);
	mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
	mlx_destroy_display(ctx->mlx_ptr);
	free(ctx->mlx_ptr);
	exit(0);
}
