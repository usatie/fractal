/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:06:29 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 23:39:28 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rand.h"

// Returns pseudo random number
// This source code is taken from URL below.
// https://stackoverflow.com/questions/53886131/how-does-xorshift32-works
uint64_t	rand(void)
{
	const uint64_t	multiplier = UINT64_C(2685821657736338717);
	uint64_t		*state_ptr;
	uint64_t		state;

	state_ptr = rand_state();
	state = *state_ptr;
	state ^= state >> 12;
	state ^= state << 25;
	state ^= state >> 27;
	*state_ptr = state;
	return (state * multiplier);
}

// 2^64 = 18446744073709551616
#define TWO64 18446744073709551616.0

double	rand_one(void)
{
	return (rand() / TWO64);
}

// Randomness seed
#define RANDOM_SEED 0x42

// Returns the pointer to rand state to set/get like global variable
uint64_t	*rand_state(void)
{
	static uint64_t	state = RANDOM_SEED;

	return (&state);
}
