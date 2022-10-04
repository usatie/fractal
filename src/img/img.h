/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:57:43 by susami            #+#    #+#             */
/*   Updated: 2022/09/26 21:04:57 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include "fractol_core.h"

void	*init_img(void *mlx_ptr, int width, int height);
void	put_pixel(const t_img *img, int x, int y, int mlx_color);
void	clear_img(t_img *img, int width, int height);
#endif
