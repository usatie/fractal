/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_ctx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:27:36 by susami            #+#    #+#             */
/*   Updated: 2022/09/10 17:40:11 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CTX_H
# define FRACTOL_CTX_H
# include "fractol.h"

// update ctx
void	ctx_next_color_mode(t_ctx *ctx);
void	ctx_next_julia_mode(t_ctx *ctx);
void	ctx_next_fractal_type(t_ctx *ctx);
void	ctx_on_update(t_ctx *ctx);

// print config
void	put_ctx_to_window(t_ctx *ctx);
void	ctx_string_put(const t_ctx *ctx, int *height, char *str);

// print config detail
void	ctx_put_config_fractal_mode(const t_ctx *ctx, int *height);
void	ctx_put_config_color_mode(const t_ctx *ctx, int *height);
void	ctx_put_config_julia_mode(const t_ctx *ctx, int *height);
void	ctx_put_config_max_loop(const t_ctx *ctx, int *height);
void	ctx_put_config_step(const t_ctx *ctx, int *height);
void	ctx_put_config_hue(const t_ctx *ctx, int *height);
void	ctx_put_config_radian(const t_ctx *ctx, int *height);
void	ctx_put_config_mouse_point(const t_ctx *ctx, int *height);
#endif
