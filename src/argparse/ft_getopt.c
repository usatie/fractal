/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:30:05 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 15:28:42 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_getopt.h"

// Argument to the option is returned via global variable
char	*g_optarg = NULL;
// The index of the next element to be processed in argv.
int		g_optind = 1;

// Parse command-line options like getopt.
// But option string is pre determined.
// cf. man getopt
// 
// Return values
// 	If an option was successfully found, then getopt() returns the
//  option character.
//
// Other special return values
// 	-1  : There are no more option characters
// 	':' : Missing option argument
// 	'?' : Encounters an option character that was not in optstring
int	ft_getopt(int argc, char *const argv[])
{
	char		*s;

	s = argv[g_optind];
	if (ft_strcmp(s, "--") == 0 || s[0] != '-')
		return (-1);
	g_optind++;
	if (s[1] == 'd')
	{
		if (g_optind == argc)
		{
			g_optarg = NULL;
			return (':');
		}
		g_optarg = argv[g_optind];
		g_optind++;
		return ('d');
	}
	else if (s[1] == 'c')
		return ('c');
	else if (s[1] == 'j')
		return ('j');
	else
		return ('?');
}
