/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:18:25 by susami            #+#    #+#             */
/*   Updated: 2022/07/27 14:22:57 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

t_complex	mandelbrot(t_complex z, t_complex c)
{
	return (cadd(cmul(z, z), c));
}

int	divergence_speed(t_complex z, t_complex c, int max_loop)
{
	int			i;

	i = -1;
	while (++i < max_loop)
	{
		z = mandelbrot(z, c);
		if (isinf(z.re) || isinf(z.im))
			return (i);
	}
	return (i);
}

void	draw_barnsley(void *img_ptr, t_ctx ctx)
{
	float			rng;
	t_complex		c;
	int				x;
	int				y;
	char			*img;
	t_img_info		img_info;
	unsigned int	i;
	t_double_point	o;

	(void)img_ptr;
	img = mlx_get_data_addr(ctx.img_ptr,
			&img_info.bits_per_pixel, &img_info.size_line, &img_info.endian);
	y = -1;
	while (++y < FRACT_HEIGHT)
	{
		x = -1;
		while (++x < FRACT_WIDTH)
			*((int *)img + FRACT_HEIGHT * y + x) = 0;
	}
	o = calc_origin(ctx.win_mouse_pnt, ctx.mouse_pnt, ctx.step);
	i = 0;
	while (++i < pow(10, 4 + (double)ctx.max_loop / 100))
	{
		rng = ((float)rand()) / RAND_MAX;
		if (rng <= 0.01f)
			c = complex_new(0, 0.16f * c.im);
		else if (rng <= 0.06f)
			c = complex_new(-0.15f * c.re + 0.28f * c.im,
					0.26f * c.re + 0.24f * c.im + 0.44f);
		else if (rng <= 0.06f)
			c = complex_new(0.2f * c.re + -0.26f * c.im,
					0.23f * c.re + 0.22f * c.im + 1.6f);
		else
			c = complex_new(0.85f * c.re + 0.04f * c.im,
					-0.04f * c.re + 0.85f * c.im + 1.6f);
		x = (c.re - o.x) / ctx.step;
		y = (o.y - c.im) / ctx.step;
		if (x >= 0 && y >= 0 && x <= FRACT_WIDTH && y <= FRACT_HEIGHT)
			*((int *)img + FRACT_HEIGHT * y + x) = green();
	}
}

void	draw_fractal(void *img_ptr, t_double_point o,
				double step, unsigned char hue, int max_loop,
				t_fractal_type fractal_type, t_ctx ctx)
{
	int						x;
	int						y;
	int						speed;
	t_hsv					hsv;
	t_img_info				img_info;
	char					*img;
	static t_double_point	prev_o;
	static double			prev_step;
	static int				prev_max_loop;
	static double			prev_c_radian;
	static t_fractal_type	prev_fractal_type;
	static int				speeds[FRACT_WIDTH][FRACT_HEIGHT];
	bool					is_updated;

	is_updated = (prev_step != step)
		|| (prev_o.x != o.x)
		|| (prev_o.y != o.y)
		|| (prev_max_loop != max_loop)
		|| (prev_c_radian != ctx.c_radian)
		|| (prev_fractal_type != ctx.fractal_type);
	prev_o = o;
	prev_step = step;
	prev_max_loop = max_loop;
	prev_c_radian = ctx.c_radian;
	prev_fractal_type = ctx.fractal_type;
	if (is_updated && ctx.fractal_type == Barnsley)
		draw_barnsley(ctx.img_ptr, ctx);
	if (ctx.fractal_type == Barnsley)
		return ;
	img = mlx_get_data_addr(img_ptr,
			&img_info.bits_per_pixel, &img_info.size_line, &img_info.endian);
	y = -1;
	while (++y < FRACT_HEIGHT)
	{
		x = -1;
		while (++x < FRACT_WIDTH)
		{
			if (is_updated)
			{
				if (fractal_type == Mandelbrot)
					speed = divergence_speed(
							complex_new(0, 0),
							complex_new(o.x + step * (double)x,
								o.y - step * (double)y),
							max_loop);
				else if (fractal_type == Julia)
					speed = divergence_speed(
							complex_new(o.x + step * (double)x,
								o.y - step * (double)y),
							ctx.c,
							max_loop);
				else
					exit(EXIT_FAILURE);
				speed = speed * 256 / ctx.max_loop;
				speeds[x][y] = speed;
			}
			else
				speed = speeds[x][y];
			hsv = (t_hsv){(hue + speed) % 256, 255, 150, 0};
			*((int *)img + FRACT_HEIGHT * y + x) = hsv2mlxint(hsv);
		}
	}
}
