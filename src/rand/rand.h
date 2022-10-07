/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:06:23 by susami            #+#    #+#             */
/*   Updated: 2022/10/07 23:17:36 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAND_H
# define RAND_H

# include <inttypes.h>

uint64_t	rand(void);
double		rand_one(void);
uint64_t	*rand_state(void);
#endif
