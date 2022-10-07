/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:30:05 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 22:08:06 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_getopt.h"

#define SUCCESS 0
#define ERROR -1
#define ERROR_NO_MORE_ARG -1
#define ERROR_MISSING_ARGUMENT ':'
#define ERROR_INVALID_OPTION '?'

static int	consume_nextchar(int argc, char *const argv[], char **nextchar);
static char	consume_opt(char **nextchar);
static int	consume_arg(int argc, char *const argv[], char **nextchar);

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
	static char	*nextchar = NULL;
	char		opt;

	if (consume_nextchar(argc, argv, &nextchar) == ERROR)
		return (ERROR_NO_MORE_ARG);
	opt = consume_opt(&nextchar);
	if (opt == 'd')
	{
		if (consume_arg(argc, argv, &nextchar) == ERROR)
			return (ERROR_MISSING_ARGUMENT);
		return (opt);
	}
	else if (opt == 'c')
		return (opt);
	else if (opt == 'j')
		return (opt);
	else
		return (ERROR_INVALID_OPTION);
}

/*
--------------------------------------------------------------------------------
|                           File Private Functions                             |
--------------------------------------------------------------------------------
*/
static int	consume_nextchar(int argc, char *const argv[], char **nextchar)
{
	if (*nextchar == NULL)
	{
		if (*optind() >= argc)
			return (ERROR);
		*nextchar = argv[*optind()];
		if (ft_strcmp(*nextchar, "--") == 0 || **nextchar != '-')
			return (ERROR);
		(*nextchar)++;
	}
	return (SUCCESS);
}

static char	consume_opt(char **nextchar)
{
	char		opt;

	opt = **nextchar;
	(*nextchar)++;
	if (**nextchar == '\0')
	{
		(*optind())++;
		*nextchar = NULL;
	}
	return (opt);
}

static int	consume_arg(int argc, char *const argv[], char **nextchar)
{
	if (*nextchar != NULL)
	{
		(*optarg()) = *nextchar;
		(*optind())++;
		*nextchar = NULL;
	}
	else if ((*optind()) < argc)
	{
		(*optarg()) = argv[*optind()];
		(*optind())++;
	}
	else
	{
		(*optarg()) = NULL;
		return (ERROR);
	}
	return (SUCCESS);
}
