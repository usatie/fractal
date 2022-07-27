/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:39:49 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 10:40:23 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	init_img(t_img *img, void *mlx_ptr, int width, int height)
{
	int		bpp;
	int		size_line;
	int		endian;

	img->mlx_ptr = mlx_ptr;
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	img->data = mlx_get_data_addr(img->img_ptr, &bpp, &size_line, &endian);
	img->bpp = bpp;
	img->size_line = size_line;
	img->endian = endian;
}

void	destroy_img(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
}

void	put_pixel_in_img(t_img *img, int x, int y, int color)
{
	size_t	idx;

	idx = (x * img->bpp >> 3) + (y * img->size_line);
	*(int *)(&img->data[idx]) = color;
}

void	clear_img_rect(t_img *img, t_rect rect)
{
	int		x;
	int		y;

	y = rect.y - 1;
	while (++y < rect.height)
	{
		x = rect.x - 1;
		while (++x < rect.width)
			put_pixel_in_img(img, x, y, rgb2mlxint((t_rgb){0}));
	}
}

void	clear_win_rect(void *mlx_ptr, void *win_ptr, t_rect rect)
{
	int		x;
	int		y;
	t_img	img;

	init_img(&img, mlx_ptr, rect.width, rect.height);
	y = -1;
	while (++y < rect.height)
	{
		x = -1;
		while (++x < rect.width)
			put_pixel_in_img(&img, x, y, rgb2mlxint((t_rgb){0}));
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, rect.x, rect.y);
}
