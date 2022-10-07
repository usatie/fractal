/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:07:26 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 22:08:13 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NULL
#include <stddef.h>
#include "ft_getopt.h"

// Argument to the option is returned via global variable
// char	*g_optarg = NULL;
char	**optarg(void)
{
	static char	*g_optarg = NULL;

	return (&g_optarg);
}

// The index of the next element to be processed in argv.
// int		g_optind = 1;
int	*optind(void)
{
	static int	g_optind = 1;

	return (&g_optind);
}
