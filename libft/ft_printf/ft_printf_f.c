/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:04:38 by susami            #+#    #+#             */
/*   Updated: 2022/09/02 19:29:25 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <errno.h>

void	ftoa(float f, char *res, int width, int precision);
void	dtoa(double f, char *res, int width, int precision);
void	print(t_fmt *fmt, char *str, size_t len);

#define BUF_SIZE	1500
#define DEFAULT_PRECISION	6

void	printf_f(t_fmt *fmt)
{
	float	f;
	char	buf[BUF_SIZE];

	(fmt->format)++;
	if (errno == EOVERFLOW)
	{
		fmt->out_size = -1;
		return ;
	}
	f = (float)va_arg(fmt->ap, double);
	if (~fmt->flags & PRECISION_FLG)
		fmt->precision = DEFAULT_PRECISION;
	ftoa(f, buf, fmt->width, fmt->precision);
	print(fmt, buf, ft_strlen(buf));
}

/*
#include <string.h>
#include <float.h>
#include <stdint.h>
#include <stdio.h>

void	check_printf(double d, int pad, int precision)
{
	float	f = (float)d;
	static char	buf[500] = {0};

	ftoa(f, buf, pad + precision, precision);
	printf("%%f myprintf: [%*s]\n", pad + precision, buf);
	printf("%%f printf:   [%0*.*f]\n", pad + precision, precision, f);

	dtoa(d, buf, pad + precision, precision);
	printf("%%lf myprintf: [%*s]\n", pad + precision, buf);
	printf("%%lf printf:   [%0*.*lf]\n", pad + precision, precision, d);
	printf("-------------------------------\n");
}

int	main(void)
{
	double		d;
	float		f;
	uint64_t	mem64;
	uint32_t	mem32;

	check_printf(123.4567, 0, 0);
	check_printf(123.4567, 0, 1);
	check_printf(123.4567, 0, 2);
	check_printf(123.4567, 0, 6);
	check_printf(123.4567, 0, 50);
	check_printf(123.4567, 0, 150);
	check_printf(42, 10, 150);
	check_printf(4.2, 0, 150);
	check_printf(FLT_MIN, 0, 300);
	check_printf(FLT_MAX, 0, 300);
	check_printf(DBL_MIN, 0, 1080);
	check_printf(DBL_MAX, 0, 1080);

	mem32 = 1;
    memcpy(&f, &mem32, sizeof(uint32_t));
	check_printf(f, 0, 150); // denormalized num (truely minimum float)
	
	mem64 = 1;
    memcpy(&d, &mem64, sizeof(uint64_t));
	check_printf(d, 0, 1080); // denormalized num (truely minimum double)

	check_printf(0.0/0.0, 0, 0); // nan
	check_printf(1.0/0.0, 0, 0); // inf
	check_printf(-1.0/0.0, 0, 0); // -inf
}
*/
