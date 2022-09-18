/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:39:49 by susami            #+#    #+#             */
/*   Updated: 2022/09/18 22:08:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "mlx.h"

void	init_img(t_img *img, void *mlx_ptr, int width, int height)
{
	int		bpp;
	int		size_line;
	int		endian;

	img->mlx_ptr = mlx_ptr;
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (img->img_ptr == NULL)
		return ;
	img->data = mlx_get_data_addr(img->img_ptr, &bpp, &size_line, &endian);
	img->bpp = bpp;
	img->size_line = size_line;
	img->endian = endian;
}

// Update img data
void	put_pixel_in_img(const t_img *img, int x, int y, int color)
{
	int	idx;

	idx = (x * img->bpp >> 3) + (y * img->size_line);
	ft_memmove(&img->data[idx], &color, sizeof(int));
}

/*
   Clear the rect in img.

   img
   o--------------------------------o
   |                                |
   |         (x,y)                  |
   |           o--------------o     |
   |    height |     rect     |     |
   |           o--------------o     |
   |                 width          |
   o--------------------------------o

*/
void	clear_img_rect(const t_img *img, t_rect rect)
{
	int		x;
	int		y;

	y = rect.y - 1;
	while (++y < rect.y + rect.height)
	{
		x = rect.x - 1;
		while (++x < rect.x + rect.width)
			put_pixel_in_img(img, x, y, black().mlxint);
	}
}
