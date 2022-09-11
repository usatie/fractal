/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:06:03 by susami            #+#    #+#             */
/*   Updated: 2022/09/11 15:11:57 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_decimal.h"
#include "libft.h"

static t_decimal	round_fract(t_decimal decimal, int precision);

// Create decimal from num
t_decimal	new_decimal(unsigned long long num)
{
	t_decimal	decimal;
	size_t		i;

	ft_memset(&decimal, 0, sizeof(t_decimal));
	i = 0;
	while (i < DOUBLE_MAX_INT && num > 0)
	{
		decimal.int_digits[DOUBLE_MAX_INT - 1 - i] = num % 10;
		num /= 10;
		i++;
	}
	return (decimal);
}

// Multiply decimal value with int value
t_decimal	mul_decimal(t_decimal decimal, int n)
{
	int		i;
	char	carry;

	i = DOUBLE_MAX_FRACT - 1;
	while (i >= 0 && decimal.fract_digits[i] == 0)
		i--;
	carry = 0;
	while (i >= 0)
	{
		decimal.fract_digits[i] *= n;
		decimal.fract_digits[i] += carry;
		carry = decimal.fract_digits[i] / 10;
		decimal.fract_digits[i] %= 10;
		i--;
	}
	i = DOUBLE_MAX_INT - 1;
	while (i >= 0)
	{
		decimal.int_digits[i] *= n;
		decimal.int_digits[i] += carry;
		carry = decimal.int_digits[i] / 10;
		decimal.int_digits[i] %= 10;
		i--;
	}
	return (decimal);
}

// Divide decimal value by int value
t_decimal	div_decimal(t_decimal decimal, int n)
{
	size_t	i;
	char	carry;

	carry = 0;
	i = 0;
	while (i < DOUBLE_MAX_INT)
	{
		carry *= 10;
		carry += decimal.int_digits[i];
		decimal.int_digits[i] = carry / n;
		carry %= n;
		i++;
	}
	i = 0;
	while (i < DOUBLE_MAX_FRACT)
	{
		carry *= 10;
		carry += decimal.fract_digits[i];
		decimal.fract_digits[i] = carry / n;
		carry %= n;
		i++;
	}
	return (decimal);
}

/*
   Convert decimal to string.

   `res` will be NULL terminated string.
   `precision` is the right side length not including dot.
   If `precision` is 0, then no dot will be added.

   The size of `res` must be >= DOUBLE_MAX_FRACT + DOUBLE_MAX_INT.
*/
void	decimal_to_str(t_decimal decimal, char *res, int precision)
{
	int	i;

	decimal = round_fract(decimal, precision);
	i = 0;
	while (i < DOUBLE_MAX_INT - 1 && decimal.int_digits[i] == 0)
		i++;
	while (i < DOUBLE_MAX_INT)
		*res++ = decimal.int_digits[i++] + '0';
	if (precision > 0)
		*res++ = '.';
	i = 0;
	while (i < precision)
	{
		if (i < DOUBLE_MAX_FRACT)
			*res = decimal.fract_digits[i] + '0';
		else
			*res = '0';
		res++;
		i++;
	}
	*res = '\0';
}

static t_decimal	round_fract(t_decimal decimal, int precision)
{
	int	i;
	int	carry;

	if (precision >= DOUBLE_MAX_FRACT || decimal.fract_digits[precision] < 5)
		return (decimal);
	i = precision - 1;
	carry = 1;
	while (carry > 0 && i >= 0)
	{
		decimal.fract_digits[i] += carry;
		carry = decimal.fract_digits[i] / 10;
		decimal.fract_digits[i] %= 10;
		i--;
	}
	i = DOUBLE_MAX_INT - 1;
	while (carry > 0 && i >= 0)
	{
		decimal.int_digits[i] += carry;
		carry = decimal.int_digits[i] / 10;
		decimal.int_digits[i] %= 10;
		i--;
	}
	return (decimal);
}
