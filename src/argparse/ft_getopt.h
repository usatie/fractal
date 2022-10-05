/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:30:13 by susami            #+#    #+#             */
/*   Updated: 2022/10/05 13:47:55 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

int	ft_getopt(int argc, char *const argv[]);

extern char	*g_optarg;
extern int	g_optind;
extern int	g_opterr;
extern int	g_optopt;
#endif
