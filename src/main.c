/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:45:30 by susami            #+#    #+#             */
/*   Updated: 2022/07/25 11:19:46 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

#define WIN_WIDTH 500
#define WIN_HEIGHT 500
#define WIN_TITLE "fract-ol"

void	mlx_playground(void);
void	math_playground(void);

t_double_point	calc_origin(t_int_point win_mouse_pnt,
		t_double_point mouse_pnt, double step)
{
	double	x;
	double	y;

	x = mouse_pnt.x - step * win_mouse_pnt.x;
	y = mouse_pnt.y + step * win_mouse_pnt.y;
	return ((t_double_point){x, y});
}

int	main(void)
{
	t_ctx	ctx;

	ctx.mlx_ptr = mlx_init();
	ctx.win_ptr = mlx_new_window(ctx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	ctx.img_ptr = get_fractal_img(ctx.mlx_ptr,
			calc_origin(ctx.win_mouse_pnt, ctx.mouse_pnt, ctx.step),
			ctx.step,
			ctx.hue);
	mlx_put_image_to_window(ctx.mlx_ptr, ctx.win_ptr, ctx.img_ptr, 0, 0);
	mlx_key_hook(ctx.win_ptr, key_handler, &ctx);
	mlx_mouse_hook(ctx.win_ptr, mouse_handler, &ctx);
	mlx_loop(ctx.mlx_ptr);
	return (0);
}
